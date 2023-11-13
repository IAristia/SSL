/* Reverse Polish Notation calculator. */

%{
  #include <stdio.h>
  int yylex (void);
  void yyerror (char const *);
%}

%union {
  double val;
}
%token <val> NUMERO
%token SUMA RESTA DIVISION MULTIPLICACION SYNTAXERROR POPRESULT

%% /* Grammar rules and actions follow. */

empty_rule:
  /* empty */
  ;

input:
empty_rule
| input line
;

line:
  POPRESULT
| exp POPRESULT      { printf ("%.10g\n", $1); }
;

exp:
  NUMERO        { $$ = $1; }
| exp exp SUMA   { $$ = $1 + $2;      }
| exp exp RESTA   { $$ = $1 - $2;      }
| exp exp MULTIPLICACION   { $$ = $1 * $2;      }
| exp exp DIVISION   { $$ = $1 / $2;      }
;