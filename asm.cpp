#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*! push = 1 (11 if arg is digital)
    pop = 2  (12 if arg is digital)
    mul = 3
    sub = 4
    sqrt = 5
    ax = 1
    bx = 2
    cx = 3
    dx = 4
    in = 6
    out = 7
    div = 8
*/

int write_arg(char *p, int *w_r) //! return -1 if error, 0 if reg, 1 if digital
{
    if (strcmp(p, "ax") == 0)
    {
        *w_r = 1;
        return 0;
    }
    else if(strcmp(p, "bx") == 0)
    {
        *w_r = 2;
        return 0;
    }
    else if(strcmp(p, "cx") == 0)
    {
        *w_r = 3;
        return 0;
    }
    else if(strcmp(p, "dx") == 0)
    {
        *w_r = 4;
        return 0;
    }
    else
    {
        *w_r = atoi(p);
        return 1;
    }
}



void parse_buf(char *buf, FILE *fd_w)
{
    char *command = buf;
    for (char *s = strchr(buf, '\n'); s != NULL; s = strchr(s + 1, '\n'))
    {
        *s = '\0';
        {
            char *p = strchr(command, ' ');
            if (p != NULL)
                *p = '\0';
            int w_c = 0;
            int w_r = 0;
            if (strcmp(command, "push") == 0)
            {
                int flag = write_arg(p + 1, &w_r);
                if (flag == -1)
                    exit(1);
                else if (flag == 0)
                    w_c = 1;
                else if (flag == 1)
                    w_c = 11;
                fwrite(&w_c, 1, sizeof(int), fd_w);
                fwrite(&w_r, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "pop") == 0)
            {
                int flag = write_arg(p + 1, &w_r);
                if (flag == -1)
                    exit(1);
                else if (flag == 0)
                    w_c = 2;
                else if (flag == 1)
                    w_c = 12;
                fwrite(&w_c, 1, sizeof(int), fd_w);
                fwrite(&w_r, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "mul") == 0)
            {
                w_c = 3;
                fwrite(&w_c, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "sub") == 0)
            {
                w_c = 4;
                fwrite(&w_c, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "sqrt") == 0)
            {
                w_c = 5;
                fwrite(&w_c, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "in") == 0)
            {
                w_c = 6;
                w_r = atoi((p + 1));
                fwrite(&w_c, 1, sizeof(int), fd_w);
                fwrite(&w_r, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "out") == 0)
            {
                w_c = 7;
                fwrite(&w_c, 1, sizeof(int), fd_w);
            }
            else if (strcmp(command, "div") == 0)
            {
                w_c = 8;
                fwrite(&w_c, 1, sizeof(int), fd_w);
            }
            command = s + 1;
        }
    }
}

int main()
{
    struct stat statbuf = {};
    int fd_r = open("Text.txt", S_IRUSR);
    FILE* fd_w = fopen("Asm.txt", "wb");
    fstat(fd_r, &statbuf);
    int file_size = statbuf.st_size;
    char buf[file_size];
    if (read(fd_r, buf, file_size) < 0)
        perror("ERROR in read");
    parse_buf(buf , fd_w);
    close(fd_r);
    fclose(fd_w);
    return 0;
}