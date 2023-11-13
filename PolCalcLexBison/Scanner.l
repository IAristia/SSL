%option noyywrap

%{
#include "parser.tab.h"
%}

%%

[ \t]+   {}
-?[0-9]+(\.)?([0-9]+)?  {yylval = atof(yytext); return NUMBER;}
"+"                     {return ADDITION;}
"-"                     {return SUBTRACTION;}
"*"                     {return MULTIPLICATION;}
"/"                     {return DIVISION;}
"\n"                    {return POPRESULT;}
.                       {printf("[Error] lex error\n"); exit(1);}

%%