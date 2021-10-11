#include <map>
#include <stack>
#include <vector>
using namespace std;

#include "Symbol.h"
#include "Production.h"
#include "lexer.h"

class Parser{
	private: 
		map<int, map<int, int>> table;
		map<int, Symbol> syms;
		vector<Production> prods;
		//table[i][j]=k;
		C_1::Lexer *lexer;
		int token;

	public:
		Parser();
		~Parser();
		void loadSymbols();
		void loadProds();
		void loadTable();
		int parse();
}