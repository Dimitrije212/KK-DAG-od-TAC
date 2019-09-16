%option noyywrap
%option nounput
%{
#include <cstdlib>
#include <iostream>

  using namespace std;
#include "ast.hpp"
#include "parser.tab.hpp"

%}


%%
"print"            return print_token;
"if"               return if_token;
"goto"             return goto_token;
[-*+/();.:=<>]       return *yytext;
[a-zA-Z_][a-zA-Z_0-9]*   {
  yylval.s = new string(yytext);
  return id_token;
}
[0-9]+   {
  yylval.i = atoi(yytext);
  return num_token;
}
[ \t\n]            {   }
.   {
  cerr << "Leksicka greska: Neprepoznat karakter '" << *yytext << "'" << endl;
  exit(EXIT_FAILURE);
}
%%
