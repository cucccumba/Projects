#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_text(char **text, int strings_count)
{
    for (int i = 0; i < strings_count; ++i)
        printf("%s", text[i]);
    printf("\n");
}

int input_text(char **text)
{
    FILE *f;
    f = fopen("Onegin.txt", "r");
    if (f == NULL)
    {
        perror("ERROR");
        return 0;
    }
    else
    {
        int i = 0;
        int strings_count = 0;
        char buf[100];
        while (fgets(buf, 100, f))
        {
            text[i] = (char *)realloc(text[i], strlen(buf));
            strcpy(text[i], buf);
            ++i;
            ++strings_count;
        }
        return strings_count;
    }
}

int compare (const void *lhs, const void *rhs)
{
    const char *l = *((const char**)lhs);
    const char *r = *((const char**)rhs);
    return strcmp(l, r);
}

char **sort_text(char **text, char **sorted_text, int strings_count)
{
    for (int i = 0; i < strings_count; ++i)
        strcpy(sorted_text[i], text[i]);

    qsort(sorted_text, strings_count, sizeof(char *), compare);
    return sorted_text;
}

int compare_back(const void *lhs, const void *rhs)
{
    const char *l = *((const char**)lhs);
    const char *r = *((const char**)rhs);
    int size_l = strlen(l);
    int size_r = strlen(r);
    char *reversed_l = (char *)calloc(size_l, sizeof(char));
    char *reversed_r = (char *)calloc(size_r, sizeof(char));

    for (int i = 0; i < size_l - 1; ++i)
        reversed_l[i] = l[size_l - 2 - i];
    reversed_l[size_l - 1] = '\n';
    reversed_l[size_l] = '\0';

    for (int i = 0; i < size_r - 1; ++i)
        reversed_r[i] = r[size_r - 2 - i];
    reversed_r[size_r - 1] = '\n';
    reversed_r[size_r] = '\0';

    int result = strcmp(reversed_l, reversed_r);
    free(reversed_l);
    free(reversed_r);
    return result;
}

char **sort_back_text(char **text, char **sorted_back_text, int strings_count)
{
    for (int i = 0; i < strings_count; ++i)
        strcpy(sorted_back_text[i], text[i]);
    qsort(sorted_back_text, strings_count, sizeof(char *), compare_back);
    return sorted_back_text;
}

int main()
{
    char **text = (char **)calloc(100, sizeof(char *));
    for (int i = 0; i < 100; ++i)
        text[i] = (char *)calloc(50, sizeof(char));
    int strings_count = input_text(text);
    text = (char **)realloc(text, strings_count);

    char **sorted_text = (char **)calloc(strings_count, sizeof(char *));
    for (int i = 0; i < strings_count; ++i)
        sorted_text[i] = (char *)calloc(strlen(text[i]), sizeof(char));
    sorted_text = sort_text(text, sorted_text, strings_count);

    char **sorted_back_text = (char **)calloc((strings_count), sizeof(char *));
    for (int i = 0; i < strings_count; ++i)
        sorted_back_text[i] = (char *)calloc(strlen(text[i]), sizeof(char));

    sorted_back_text = sort_back_text(text, sorted_back_text, strings_count);

    print_text(text, strings_count);
    print_text(sorted_text, strings_count);
    print_text(sorted_back_text, strings_count);

    free(text);
    free(sorted_text);
    free(sorted_back_text);
    return 0;
}