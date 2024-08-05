%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
int yylex();
int yyerror (char *s);
int yywrap(){
return(1);
}
%}

%define api.value.type {double}
%token NUMBER ADDITION SUBTRACTION MULTIPLICATION DIVISION POPRESULT

%%

input:    /* vacio */
        | input line
;

line:     POPRESULT
        | exp POPRESULT  { printf ("Resultado: %f\n", $1); }
;

exp:      NUMBER                  { $$ = $1;         }
        | exp exp ADDITION        { $$ = $1 + $2;    }
        | exp exp SUBTRACTION     { $$ = $1 - $2;    }
        | exp exp MULTIPLICATION  { $$ = $1 * $2;    }
        | exp exp DIVISION        { $$ = $1 / $2;    }
;
%%

int yyerror (char *s)
{
  printf ("[Error] %s\n", s);
}

int main ()
{
  yyparse();
}
