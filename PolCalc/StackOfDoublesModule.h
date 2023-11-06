#ifndef STACK_OF_DOUBLES_MODULE_H
#define STACK_OF_DOUBLES_MODULE_H

#include <stdbool.h>

#define MAX 100

typedef double StackItem;

void Push(StackItem item);
StackItem Pop();
bool IsEmpty();
bool IsFull();

#endif /* STACK_OF_DOUBLES_MODULE_H*/