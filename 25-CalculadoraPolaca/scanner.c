#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "scanner.h"

void main (FILE *stream) {

int c{0};

while ((c = getc(stream)) != EOF){

}
}

enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};

typedef enum TokenType TokenType;

typedef double TokenValue;

struct Token{
 TokenType type;
 TokenValue val;
};

bool GetNextToken (Token *t){
return};