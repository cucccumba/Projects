#include "read_and_write.h"


void input_text(char *buf, char *filename)
{
    int f = open(filename, O_RDONLY);
    if (f < 0)
    {
        perror("ERROR");
        exit(1);
    }
    int chars_reed = bufsize;
    char *p = buf;
    while (chars_reed == bufsize)
    {
        chars_reed = read(f, p, bufsize);
        if (chars_reed < 0)
            perror("ERROR");
        if (chars_reed == bufsize)
        {
            buf = (char*)(realloc(buf, bufsize + bufsize));
            p = buf + bufsize;
        }

    }
}


void print_text_in_file(String *strings, int strings_count, char *filename)
{
    assert(strings);

    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    char endl[] = {'\n'};
    for (size_t i = 0; i < strings_count; ++i)
    {
        write(fd, strings[i].p_string, strings[i].lenght);
        write(fd, endl, 1);
    }
    write(fd, endl, 1);
    char div[] = {'_'};
    for (int i = 0; i < 20; ++i)
    {
        write(fd, div, 1);
    }
    write(fd, endl, 1);
}

int count_strings(char *buf)
{
    assert(buf);

    int strings_count = 0;
    for (char *s = strchr(buf, '\n'); s != NULL; s = strchr(s + 1, '\n'))
    {
        if (*(s - 1) != '\n')
            ++strings_count;
    }
    return strings_count;
}

String * make_index(String *strings, char *buf)
{
    assert(buf);

    int i = 0;
    char *previous_pointer = buf;
    for(char *s = strchr(buf, '\n'); s != NULL; s = strchr(s + 1, '\n'))
    {
        if (*(s - 1) != '\n')
        {
            strings[i].p_string = previous_pointer;
            strings[i].lenght = s - previous_pointer;
            ++i;
            *s = '\0';
            previous_pointer = ++s;

        }
    }
    return strings;
}