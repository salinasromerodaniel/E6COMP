#include "Parser.h"

void Parse::loadSymbols(){
	syms[0] = Symbol("expresion", noterminal, 0);
	syms[1] = Symbol("expresion_", noterminal, 1);


}

void Parser::loadProds(){
	vector <int> s={2, 1};
	prods[0] = Production(0, s);
	s.clear();
	s={5, 2, 1};
	prods[1] = Production(1, s);
	s.clear();
	s={11};


}

void Parser:: loadTable(){
	table[0][7]=0;


}

int Parser::parse(){
	stack<Symbol> pila;
	token= lexer -> yylex();
	pila.push(syms[10]);
	pila.push(sym[0]);
	while(pila.top().getName()!="$"){
		if(pila.top().getType()==noterminal){

		}else if (pila.top().getType()==terminal){
			
		}
	}
}