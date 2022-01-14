#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__ 1

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

namespace C_1
{

    class Scanner : public yyFlexLexer
    {
    public:
        Scanner(std::istream *in) : yyFlexLexer(in)
        {
        };

        using FlexLexer::yylex;
        virtual int yylex();

    private:
        const int ERROR = -1;
        const int ACEPTAR = 0;
        const int INT = 1;
        const int FLOAT = 2;
        const int ELSE = 3;
        const int IF = 4;
        const int WHILE = 5;
        const int MAS = 6;
        const int MENOS = 7;
        const int MUL = 8;
        const int DIV = 9;
        const int ASIG = 10;
        const int LPAR = 11;
        const int RPAR = 12;
        const int ID = 13;
        const int PYC = 14;
        const int COMA = 15;
        const int NUMERO = 16;
        const int ESP = 17;
        // TODO(1) Completar las constantes que faltan de los tokens
    };

}

#endif /* END __SCANNER_H__ */