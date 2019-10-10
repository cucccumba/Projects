#include "Sort.h"

int compare(const void* lhs, const void* rhs)
{
    String* l = (String*)lhs;
    String* r = (String*)rhs;
    char* left = (char*)calloc(l->lenght, sizeof(char));
    char* right = (char*)calloc(r->lenght, sizeof(char));

    int j = 0;
    for (size_t i = 0; i < l->lenght; ++i)
    {
        if (isalpha(l->p_string[i]))
            left[j++] = tolower(l->p_string[i]);
    }

    int k = 0;
    for (size_t i = 0; i < r->lenght; ++i)
    {
        if (isalpha(r->p_string[i]))
            right[k++] = tolower(r->p_string[i]);
    }

    int result = strcmp(left, right);
    free(left);
    free(right);
    return result;
}

String * sort_text(String *strings, String *strings_sorted, int strings_count)
{
    assert(strings);

    memcpy(strings_sorted, strings, strings_count * sizeof(String));
    qsort(strings_sorted, strings_count, sizeof(String), compare);

    assert(strings_sorted);
    return strings_sorted;
}

int compare_back(const void *lhs, const void *rhs)
{
    String* l = (String*)lhs;
    String* r = (String*)rhs;
    char* left = (char*)calloc(l->lenght, sizeof(char));
    char* right = (char*)calloc(r->lenght, sizeof(char));

    int j = 0;
    for (size_t i = 0; i < l->lenght; ++i)
    {
        if (isalpha(l->p_string[l->lenght - 1 - i]))
            left[j++] = tolower(l->p_string[l->lenght - 1 - i]);
    }

    int k = 0;
    for (size_t i = 0; i < r->lenght; ++i)
    {
        if (isalpha(r->p_string[r->lenght - 1 - i]))
            right[k++] = tolower(r->p_string[r->lenght - 1 - i]);
    }

    int result = strcmp(left, right);
    free(left);
    free(right);
    return result;
}

String * sort_text_back(String *strings, String *strings_sorted_back, int strings_count)
{
    assert(strings);

    memcpy(strings_sorted_back, strings, strings_count * sizeof(String));
    qsort(strings_sorted_back, strings_count, sizeof(String), compare_back);

    assert(strings_sorted_back);
    return strings_sorted_back;
}
