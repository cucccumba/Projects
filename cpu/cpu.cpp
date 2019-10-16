#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "Stack.h"
#include <math.h>

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

int main()
{
    int fd_r = open("Asm.txt", O_RDONLY);
    struct stat statbuf = {};
    fstat(fd_r, &statbuf);
    int file_size = statbuf.st_size;
    int buf[file_size / sizeof(int)];
    if (read(fd_r, buf, file_size) < 0)
        perror("READ:");
    int i = 0;
    struct Stack st = {"st"};
    Stack_init(&st);
    int ax = 0, bx = 0, cx = 0, dx = 0, ex = 0, fx = 0;
    while (i < file_size / sizeof(int))
    {
        switch (buf[i])
        {
            case 1:
            {
                switch(buf[i + 1])
                {
                    case 1:
                    {
                        Stack_push(&st, ax);
                        i += 2;
                        break;
                    }
                    case 2:
                    {
                        Stack_push(&st, bx);
                        i += 2;
                        break;
                    }
                    case 3:
                    {
                        Stack_push(&st, cx);
                        i += 2;
                        break;
                    }
                    case 4:
                    {
                        Stack_push(&st, dx);
                        i += 2;
                        break;
                    }
                    default:
                    {
                        printf("ERROR, wrong reg in push");
                        exit(1);
                    }
                }
                break;
            }
            case 2:
            {
                switch(buf[i + 1])
                {
                    case 1:
                    {
                        Stack_pop(&st, &ax);
                        i += 2;
                        break;
                    }
                    case 2:
                    {
                        Stack_pop(&st, &bx);
                        i += 2;
                        break;
                    }
                    case 3:
                    {
                        Stack_pop(&st, &cx);
                        i += 2;
                        break;
                    }
                    case 4:
                    {
                        Stack_pop(&st, &dx);
                        i += 2;
                        break;
                    }
                    default:
                    {
                        printf("ERROR, wrong reg in pop");
                        exit(2);
                    }
                }
                break;
            }
            case 3:
            {
                Stack_pop(&st, &ex);
                Stack_pop(&st, &fx);
                ex = ex * fx;
                Stack_push(&st, ex);
                ++i;
                break;
            }
            case 4:
            {
                Stack_pop(&st, &ex);
                Stack_pop(&st, &fx);
                ex = fx - ex;
                Stack_push(&st, ex);
                ++i;
                break;
            }
            case 5:
            {
                Stack_pop(&st, &ex);
                ex = sqrt(ex);
                Stack_push(&st, ex);
                ++i;
                break;
            }
            case 6:
            {
                Stack_push(&st, buf[i + 1]);
                i += 2;
                break;
            }
            case 7:
            {
                Stack_pop(&st, &ex);
                printf("%d\n", ex);
                ++i;
                break;
            }
            case 8:
            {
                Stack_pop(&st, &ex);
                Stack_pop(&st, &fx);
                ex = fx / ex;
                Stack_push(&st, ex);
                ++i;
                break;
            }
            case 11:
            {
                Stack_push(&st, buf[i + 1]);
                i += 2;
                break;
            }
            case 12:
            {
                Stack_push(&st, buf[i + 1]);
                i += 2;
                break;
            }
        }
    }
    return 0;
}