# include "../../hdr/woody.h"

int printError(char *ctx)
{
    perror(ctx);
    return (-1);
}