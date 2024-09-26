#include "../hdr/woody.h"

int main(int argc, char const *argv[])
{
    woody_t woody;

    if (parse_file(&woody, argv[argc -1]) < 0)
        return 1;
    if (check_elf(&woody))
        return 1;
    munmap(woody.map, woody.file_size);
    return 0;
}
