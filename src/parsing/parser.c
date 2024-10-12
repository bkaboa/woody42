#include "../../hdr/woody.h"

int get_map(woody_t *woody, int fd)
{
    off_t   len = lseek(fd, 0, SEEK_END);
    if (len == -1)
        return printErrno("lseek");
    woody->file_size = len;
    if ((size_t)len < sizeof (Elf32_Ehdr)) {
        dprintf(2, "Invalid binary\n");
        return -1;
    }
    woody->map = mmap(NULL, woody->file_size, PROT_READ, MAP_PRIVATE,fd, 0);
    if (!(woody->map))
        return printErrno("mmap");
    return 0;
}

int parse_file(woody_t *woody, const char *file)
{
    int fileFd;
    fileFd = open(file, O_RDONLY);
    if (fileFd < 0)
        return (printErrno(file));
    int ret = get_map(woody, fileFd);
    close(fileFd);
    return ret;
}

void    *get_element_from_map(woody_t *woody, size_t offset, size_t len) {
    const size_t  end_offset = offset + len;

    if (end_offset > woody->file_size) {
        dprintf(2, "Map out of range\n");
        return NULL;
    }
    return woody->map + offset;
}

int check_elf(woody_t *woody) {
    const Elf32_Ehdr * const elf_header = get_element_from_map(woody, 0, sizeof (Elf32_Ehdr));
    if (!elf_header)
        return -1;
    printf("ELF Header:\n\
  Magic:   %x %c %c %c\n\
  Class:                             %s\n\
  Data:                              %s\n\
  Version:                           %d\n\
  OS/ABI:                            %d\n",
        elf_header->e_ident[EI_MAG0],
        elf_header->e_ident[EI_MAG1],
        elf_header->e_ident[EI_MAG2],
        elf_header->e_ident[EI_MAG3],
        elf_header->e_ident[EI_CLASS] == ARCH_64 ? "ELF64" : "ELF32",
        elf_header->e_ident[EI_DATA] == W_BIG_ENDIAN ? "big endian" : "little endian",
        elf_header->e_ident[EI_VERSION],
        elf_header->e_ident[EI_OSABI]
    );
    if (ft_strncmp((char *)elf_header, ELFMAG, 4)) {
        dprintf(2, "Invalid binary (not ELF)\n");
        return -1;
    }
    if (elf_header->e_ident[EI_CLASS] != ARCH_64 && elf_header->e_ident[EI_CLASS] != ARCH_32) {
        dprintf(2, "Invalid binary (arch diff 32/64)\n");
        return -1;
    }
    woody->fileProps.arch = elf_header->e_ident[EI_CLASS];
    if (elf_header->e_ident[EI_DATA] != W_BIG_ENDIAN && elf_header->e_ident[EI_DATA] != W_LITTLE_ENDIAN) {
        dprintf(2, "Invalid binary (endian not recognize)\n");
        return -1;
    }
    woody->fileProps.endian = elf_header->e_ident[EI_CLASS];
    return 0;
}
