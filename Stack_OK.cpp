#include "Stack_OK.h"


#include "Stack_OK.h"
#include "Stack.h"
#include <unistd.h>
#include <iostream>

void StackDump(struct Stack *st)
{
    std::cerr << std::endl << "Dump begin" << std::endl;
    std::cerr << "Stack <" << st->name << "> [" << st << "]" << "  (ERROR:" << st->ERROR << ")" << std::endl;
    std::cerr << "{" << std::endl;
    std::cerr << "    Canary1" << " = " << st->canary1 << "  [" << &st->canary1 << "]" << std::endl;
    std::cerr << "    Canary2" << " = " << st->canary2 << "  [" << &st->canary2 << "]" << std::endl;
    std::cerr << "    Index" << " = " << st->index << "  [" << &st->index << "]" << std::endl;
    std::cerr << "    Max size" << " = " << st->max_size << "  [" << &st->max_size << "]" << std::endl;
    std::cerr << "    Hash" << " = " << st->hash << "  [" << &st->hash << "]" << std::endl;
    std::cerr << "    HashStk" << " = " << st->stkhash << "  [" << &st->stkhash << "]" << std::endl;
    std::cerr << "    Data [" << &st->data << "]" << std::endl;
    if (st->index > 0 && st->index < st->max_size)
    {
        std::cerr << "    {" << std::endl;
        for (size_t i = 0; i < st->index; ++i)
            std::cerr << "        Data[" << i << "] = " << st->data[i] << "  [" << &st->data[i] << "]" << std::endl;
        std::cerr << "    }" << std::endl;
    }
    std::cerr << "}" << std::endl;
    std::cerr << "Dump end" << std::endl << std::endl;
}

bool StackOK(struct Stack *st)
{
    if (st->canary1 != canary || st->canary2 != canary)
    {
        st->ERROR = ERROR_TYPE::invalidcanary;
        return false;
    }

    int hash = HashData(st);
    if (st->hash != hash)
    {
        st->ERROR = ERROR_TYPE::wronghashdata;
        return false;
    }

    hash = HashStk(st);
    if (st->stkhash != hash)
    {
        st->ERROR = ERROR_TYPE::wronghashstk;
        return false;
    }

    if (!st->data)
    {
        st->ERROR = ERROR_TYPE::nullpointer;
        return false;
    }

    if (st->index >= st->max_size || st->index < 0 || st->max_size <= 0)
    {
        st->ERROR = ERROR_TYPE::invalidsize;
        return false;
    }

    st->ERROR = ERROR_TYPE::noerror;
    return true;
}

void Assert_OK(struct Stack *st, int line, char *s)
{
    if (StackOK(st) == 0)
    {
        StackDump(st);
        printf("ERROR IN LINE %d (file: %s)\n\n", line, s);
    }
}