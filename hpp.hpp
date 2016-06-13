#ifndef _H_AI
#define _H_AI

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
using namespace std;
#include "meta.hpp"

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	vector<Sym*> nest; void push(Sym*);
	virtual string dump(int=0); virtual string head(); string pad(int);
	virtual Sym* eval();
	virtual Sym* str();
};
extern map<string,Sym*> glob;
extern void glob_init();

struct Error: Sym { Error(string); };

struct Str: Sym { Str(string); string head(); };

struct Vector:Sym { Vector(); };

struct Op: Sym { Op(string); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_AI
