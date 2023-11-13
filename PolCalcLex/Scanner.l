%option noyywrap
%{
#include "Scanner.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef YY_NULL
#define YY_NULL createToken(0.0, TokenEoF, "")
#define YY_DECL Token yylex(void)

Token createToken(double value, enum TokenType type, char lexemeError[])
{
    Token token;
    token.type = type;
    token.val = value;
    strncpy(token.lexeme, lexemeError, sizeof(token.lexeme));
    return token;
}

%}

%%

[ \t]   { return createToken(0.0, WhiteSpace, ""); }

"+"     { return createToken(0.0, Addition, ""); }
"/"     { return createToken(0.0, Division, ""); }
"*"     { return createToken(0.0, Multiplication, ""); }

"-"     { return createToken(0.0, Substraction, ""); }

-?[0-9]+(\.[0-9]+)?  { return createToken(atof(yytext), Number, ""); }

\n      { return createToken(0.0, PopResult, ""); }
.       { return createToken(0.0, LexError, yytext); }

%%

bool GetNextToken(Token *t)
{
    do {
        *t = yylex(); 
    } while (t->type == WhiteSpace);
    return t->type != LexError && t->type != TokenEoF;
}