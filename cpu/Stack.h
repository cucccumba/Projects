#pragma once

#include <assert.h>
#include <stdlib.h>

#include "Stack_OK.h"

typedef int elem_t;
#define delta 5
#define canary 6666666666

enum ERROR_TYPE
{
    noerror, //! 0 in dump
    nullpointer, //! 1 in dump
    wronghashdata, //! 2 in dump
    invalidsize, //! 3 in dump
    invalidcanary, //! 4 in dump
    wronghashstk //! 5 in dump
};


struct Stack
{
    long canary1;
    const char *name; //! name of the stack
    elem_t *data; //! array of data
    size_t index; //! current position in data
    size_t max_size; //! max size of data
    int hash;
    int stkhash;
    ERROR_TYPE ERROR;
    long canary2;

    Stack(){};

    Stack(const char *Name)
    {
        canary1 = canary;
        canary2 = canary;
        name = Name;
        index = 0;
        max_size = 10;
        hash = 0;
        stkhash = 0;
        data = NULL;
        ERROR = ERROR_TYPE::noerror;
    }
};
//! Dynamically initializes memory for data
struct Stack* Stack_init(struct Stack *st);
//! Adds in stack item
void Stack_push(struct Stack *st, elem_t item);
//! Pulls an element from the stack (there won't be this element no more in stack)
void Stack_pop(struct Stack *st, elem_t *item);
//! Deletes stack
void Stack_destroy(struct Stack *st);
//! Pulls an element from the stack without changing data in stack
void Stack_top(struct Stack *st, elem_t *item);
int HashData(struct Stack *st);
int HashStk(struct Stack *st);
