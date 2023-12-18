#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    int i = 5;
    while (i--)
    {
        printf("... %s\n", get_next_line(fd));
    }
    close(fd);
    return 0;
}