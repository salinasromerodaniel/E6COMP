%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.hpp"
#include "Scanner.hpp"
//#undef YY_DECL
//#define YY_DECL int C_1::Scanner::yylex();
%}

%option debug
%option outfile="Scanner.cpp"
%option yyclass="C_1::Scanner"
%option c++
%option noyywrap
%option case-insensitive

ENTERO [0-9]+
FLOTANTE [0-9]*\.[0-9]+([Ee][+-]?[0-9]+)?
ID [A-Za-z_][A-Za-z0-9_]*
ESP [ \t\n\r]
CADENA ["]([^"\\\n]|\\.|\\\n)*["]
%%
"char"   { return CHAR;}
"int"    { return INT;}
"float"  { return FLOAT;}
"double" { return DOUBLE;}
"void"   { return VOID;}
"struct" { return STRUCT;}
"else"   { return ELSE;}
"if"     { return IF;}
"while"  { return WHILE;}
"do"     { return DO;}
"return" { return RETURN;}
"break"  { return BREAK;}
"print"  { return PRINT;}
"scan"   { return SCAN;}
"+"      { return MAS;}
"-"      { return MENOS;}
"*"      { return MUL;}
"/"      { return DIV;}
"="      { return ASIG;}
"("      { return LPAR;}
")"      { return RPAR;}
"{"      { return RBRACKET;}
"}"      { return LBRACKET;}
"<"      { return MENOR;}
">"      { return MAYOR;}
"<="     { return MENORIGUAL;}
">="     { return MAYORIGUAL;}
"=="     { return IGUAL;}
"!="     { return DIFF;}
"&&"     { return AND;}
"||"     { return OR;}
"!"	 { retur NOT;}
";"      { return PYC;}
","      { return COMA;}
"."      { return PUNTO;}
{ENTERO}    { return NUMERO;}
{FLOTANTE}  { return NUMERO;}
{CADENA}    { return CADENA;}
{ID} {return ID;}
{ESP} {}


.    { cout<<"ERROR LEXICO "<<yytext<<endl;}

%%