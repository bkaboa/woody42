#ifndef WOODY_H
# define WOODY_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <elf.h>
# include <sys/mman.h>

enum x86{
    X64 = 1,
    X32 = 2
};

typedef int x86;

typedef struct woody {
    void    *map; // map of the file
    size_t  file_size; // size of the file
    x86 bit;
} woody_t;

int8_t ft_strcmp(const char *str1, const char *str2);
int parse_file(woody_t *woody, const char *file);
int check_elf(woody_t *woody);
int printErrno(const char *ctx);

#endif

