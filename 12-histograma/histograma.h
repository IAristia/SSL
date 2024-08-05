#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#include <stdio.h>
#include <stdbool.h>

#include "graficador.h"

#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 10
#endif

typedef enum
{
    In,
    Out,
} State;

int main();

unsigned withEnumSwitch(FILE *stream);
void withGoTo(FILE *stream);
unsigned withRec(FILE *stream);
void withX(FILE *stream);

#endif