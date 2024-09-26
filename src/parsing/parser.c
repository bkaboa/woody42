#include "../../hdr/woody.h"

int parse_file(char *file)
{
    int fileFd;
    fileFd = open(file, O_RDONLY);
    if (fileFd < 0)
        return (printErrno(file));
    return (fileFd);
}

void *parseElf(int fd)
{
    size_t numb;
}
