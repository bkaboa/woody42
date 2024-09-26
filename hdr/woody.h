#ifndef WOODY_H
# define WOODY_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <elf.h>
# include <sys/mman.h>


# define W_LITTLE_ENDIAN ELFDATA2LSB
# define W_BIG_ENDIAN ELFDATA2MSB
# define ARCH_32 ELFCLASS32
# define ARCH_64 ELFCLASS64

enum x86{
    X64 = 1,
    X32 = 2
};

typedef int x86;

typedef struct woody {
    void        *map; // map of the file
    size_t      file_size; // size of the file
    u_int8_t    endian;
    u_int8_t    arch;
    x86 bit;
} woody_t;

int8_t ft_strcmp(const char *str1, const char *str2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(char *str);
void ft_memset(void *ptr, const u_int8_t data, size_t lenght);

int parse_file(woody_t *woody, const char *file);
int check_elf(woody_t *woody);

int printErrno(const char *ctx);

#endif

