#include "Stack.h"

#include "Stack.h"
#include <string.h>

int HashData(struct Stack *st)
{
    int hash = 0;
    for (int i = 0; i < st->index; ++i)
        hash += st->data[i] * (i + 1);
    return hash;
}

int HashStk(struct Stack *st)
{
    int hash = 0;
    for (size_t i = 0; i < strlen(st->name); ++i)
        hash += st->name[i];
    hash += st->hash + st->max_size + st->index + st->ERROR;
    return hash;
}

struct Stack* Stack_init(struct Stack *st)
{
    assert(st);
    st->data = (elem_t*)calloc(st->max_size, sizeof(elem_t));
    st->stkhash = HashStk(st);
    assert(st->data);
    return st;
}


void Stack_push(struct Stack *st, elem_t item)
{
    assert(st);
    Assert_OK(st, __LINE__, __FILE__);
    if (st->index >= st->max_size - 1)
    {
        st->data = (elem_t*)realloc(st->data, (st->max_size * 2) * sizeof(elem_t));
        st->max_size *= 2;
        assert(st->data);
    }


    st->data[st->index++] = item;
    st->hash = HashData(st);
    st->stkhash = HashStk(st);
    Assert_OK(st, __LINE__, __FILE__);
}

void Stack_pop(struct Stack *st, elem_t *item)
{
    assert(st);
    Assert_OK(st, __LINE__, __FILE__);

    if (st->index <= st->max_size / 2 - delta && st->max_size > 10)
    {
        st->data = (elem_t*)realloc(st->data, (st->max_size / 2) *  sizeof(elem_t));
        st->max_size /= 2;
        assert(st);
    }

    *item = st->data[--st->index];

    st->hash = HashData(st);
    st->stkhash = HashStk(st);
    Assert_OK(st, __LINE__,__FILE__);
}

void Stack_top(struct Stack *st, elem_t *item)
{
    assert(st);
    Assert_OK(st, __LINE__, __FILE__);

    *item = st->data[st->index - 1];
    st->hash = HashData(st);
    st->stkhash = HashStk(st);
    Assert_OK(st, __LINE__, __FILE__);
}

void Stack_destroy(struct Stack *st)
{
    assert(st);

    free(st->data);
}

