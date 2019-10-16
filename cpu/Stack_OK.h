#pragma once

#include <stdio.h>
#include "Stack.h"

//! Checks if it is all alright with stack
//! \return true if stack is ok, false if not
bool StackOK(struct Stack *st);
//! Calls StackOK and if StackOK return false, print dump, line and file, where ERROR occurred
void Assert_OK(struct Stack *st, int  line, char *s);
