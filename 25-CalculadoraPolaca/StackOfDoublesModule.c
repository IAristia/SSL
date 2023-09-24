#include "StackOfDoublesModule.h"

static StackItem stack[MAX];
static StackItem *p = stack;

void Push(StackItem item)
{
    if (IsFull())
    {
        return;
    }

    *p++ = item;
}

StackItem Pop()
{
    if (IsEmpty())
    {
        return 0.0;
    }

    return *--p;
}

bool IsEmpty() { return p == stack; }

bool IsFull() { return *p == MAX; }
