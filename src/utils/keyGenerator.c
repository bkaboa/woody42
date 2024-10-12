#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char *keyGenerator(void) {
    char *key = NULL;
    char *tmp;

    srand(time(NULL));

    key = malloc(256);
    if (key == NULL)
        return (NULL);
    for (int i = 0; i <= 255; i++) {
        key[i] = rand() % 255;
    }
    return (key);
}
