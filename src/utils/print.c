# include "../../hdr/woody.h"

int printErrno(const char *ctx)
{
    perror(ctx);
    return (-1);
}
