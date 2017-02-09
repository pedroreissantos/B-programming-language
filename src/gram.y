%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tabid.h"
#include "node.h"
/*
   tabid no yacc gera LOAD/ADDR para ID (int:0 func:1 label:2 ptr:3)
   calcula os deslocamentos dos ADDR e o valor do ENTER
*/
extern long lbl;
char *mklbl(long);
void variable(char*,Node*,Node*), function(char*,int,Node*), externs();
int yylex(); /* -Wall */

static char buf[80]; /* error messages */
static int gt, pos, dim(Node*);
static void *gtr, *root, *swr, gotos();
static Node *name(Node*), *swf(Node*), *swg(int pop);
%}

%union {
	int i;		/* integer value */
	char *s;	/* symbol name or string literal */
	Node *n;	/* tree node */
}

%token AUTO EXTRN IF ELSE WHILE CASE SWITCH SWITAB GOTO RETURN DEFAULT BREAK
%token <i> CTE
%token <s> NAME STRING

%nonassoc IFX
%nonassoc ELSE
%right ASSIGN
%right '?' ':'
%left '|'
%left '^'
%left '&'
%left LSH RSH
%nonassoc EQ NE
%nonassoc '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%right INC DEC ADDR UMINUS '!' '~'
%nonassoc '[' '('

%type<n> def vc inits names ival cte name cnames enames stmt stmts retval lvalue rvalue args

%token LOAD LABEL END DO START DIM LOCAL PTR DECL
%token AND OR ARG ID ETIQ JMP JZ JNZ
%token ADD SUB MUL DIV MOD NOT BOR BXOR BAND LT GT
%token LIST STMT BLOCK ALLOC INDEX CALL ARIF ARELSE BNOT FUNC
%%
file	: decl				{ externs(); }
decl	:
	| decl def
	;

def	: name vc inits ';'		{ IDnew($2->info, $1->value.s, 0); variable($1->value.s, $2, $3); }
	| name vc ';'			{ IDnew($2->info, $1->value.s, 0); variable($1->value.s, $2, 0); }
	| name '(' { IDnew(1, $1->value.s, 0); IDpush(); pos = 8; } names ')' { pos = 0; } stmt { gotos(); printf("# %s: enter %d\n", $1->value.s, -pos); IDpop(); function($1->value.s, -pos, $7); }
	| name '(' { IDnew(1, $1->value.s, 0); IDpush(); pos = 0; } ')' stmt { gotos(); printf("# %s: enter %d\n", $1->value.s, -pos); IDpop(); function($1->value.s, -pos, $5); }
	;

vc	:				{ $$ = nilNode(END); $$->info = 0; }
	| '[' CTE ']'			{ $$ = intNode(DIM, $2); $$->info = 3; }
	| '[' ']'			{ $$ = nilNode(DIM); $$->info = 3; }
	;

inits	: ival				{ $$ = uniNode(LIST, $1); }
	| inits ',' ival		{ $$ = addNode($1, $3, -1); }
	;

names	: name				{ IDnew(0, $1->value.s, pos); pos += 4; }
	| names ',' name		{ IDnew(0, $3->value.s, pos); pos += 4; }
	;

ival	: cte
	| '-' CTE			{ $$ = intNode(CTE, -$2); }
	| name
	;

cte	: CTE				{ $$ = intNode(CTE, $1); }
	| STRING			{ $$ = strNode(STRING, $1); }
	;

name	: NAME				{ $$ = strNode(NAME, $1); }
	;

cnames	: name vc			{ $$ = binNode(AUTO, nilNode(END), $1); IDnew($2->info, $1->value.s, pos -= 4 * dim($2)); }
	| cnames ',' name vc		{ $$ = binNode(AUTO, $1, $3); IDnew($3->info, $3->value.s, pos -= 4 * dim($4)); }
	;

enames	: name				{ $$ = binNode(EXTRN, nilNode(END), $1); IDnew(0, $1->value.s, 0); $1->info = 0; }
	| name '(' ')'			{ $$ = binNode(EXTRN, nilNode(END), $1); IDnew(1, $1->value.s, 0); $1->info = 1; $$->CHILD(1)->attrib = FUNC; }
	| enames ',' name		{ $$ = binNode(EXTRN, $1, $3); IDnew(0, $3->value.s, 0); $3->info = 0; }
	| enames ',' name '(' ')'	{ $$ = binNode(EXTRN, $1, $3); IDnew(1, $3->value.s, 0); $3->info = 1; $$->CHILD(1)->attrib = FUNC; }
	;

stmt	: AUTO cnames ';' stmt		{ $$ = binNode(DECL, $2, $4); }
	| EXTRN enames ';' stmt		{ $$ = binNode(DECL, $2, $4); }
	| name ':' { IDinsert(1, 2, $1->value.s, 0); } stmt			{ $$ = binNode(LABEL, $1, $4); }
	| CASE cte ':' stmt		{ $$ = binNode(CASE, swf($2), $4); }
	| CASE '-' CTE ':' stmt		{ $$ = binNode(CASE, swf(intNode(CTE, -$3)), $5); }
	| DEFAULT ':' stmt		{ $$ = binNode(CASE, swf(0), $3); }
	| '{' { IDpush(); } stmts '}'	{ $$ = uniNode(BLOCK, $3); IDpop(); }
	| IF '(' rvalue ')' stmt %prec IFX { $$ = binNode(IF, $3, $5); }
	| IF '(' rvalue ')' stmt ELSE stmt { $$ = binNode(ELSE, binNode(IF, $3, $5), $7); }
	| WHILE '(' rvalue ')' stmt	{ $$ = binNode(WHILE, binNode(DO, nilNode(START), $3), $5); }
	| SWITCH '(' rvalue ')' { swg(0); } stmt { $$ = binNode(SWITCH, binNode(DEFAULT, $3, swg(1)), $6); }
	| BREAK ';'			{ $$ = nilNode(BREAK); }
	| GOTO { gt = 1; } rvalue ';'	{ $$ = uniNode(GOTO, $3); gt = 0; }
	| RETURN retval ';'		{ $$ = uniNode(RETURN, $2); }
	| rvalue ';'			{ $$ = $1; }
	| lvalue '#' rvalue ';'		{ $$ = binNode(ALLOC, $3, $1); }
	| ';'				{ $$ = nilNode(END); }
	;

stmts	:				{ $$ = nilNode(END); }
	| stmts stmt			{ $$ = binNode(STMT, $1, $2); }
	;

retval	:				{ $$ = intNode(CTE, 0); }
	| '(' rvalue ')'		{ $$ = $2; }
	;

lvalue	: name				{ $$ = name($1); }
	| lvalue '[' rvalue ']'		{ $$ = binNode(INDEX, $1, $3); $$->info = 0; }
	| '*' lvalue			{ $$ = uniNode(LOAD, $2); $$->info = 0; }
	;

rvalue	: lvalue		{ $$ = uniNode(LOAD, $1); }
	| '(' rvalue ')'	{ $$ = $2; }
	| cte
	| rvalue '(' args ')'	{ $$ = binNode(CALL, $1, $3); }
	| rvalue '(' ')'	{ $$ = binNode(CALL, $1, nilNode(END)); }
      	| '-' rvalue %prec UMINUS { $$ = uniNode(UMINUS, $2); }
      	| '!' rvalue		{ $$ = uniNode(NOT, $2); }
	| '&' lvalue %prec ADDR	{ $$ = uniNode(PTR, $2); }
	| '~' rvalue		{ $$ = uniNode(BNOT, $2); }
	| lvalue INC		{ $$ = binNode(INC, $1, intNode(CTE, $1->info == 3 ? 4 : 1)); }
	| lvalue DEC		{ $$ = binNode(DEC, $1, intNode(CTE, $1->info == 3 ? 4 : 1)); }
	| INC lvalue		{ $$ = binNode(INC, intNode(CTE, $2->info == 3 ? 4 : 1), $2); }
	| DEC lvalue		{ $$ = binNode(DEC, intNode(CTE, $2->info == 3 ? 4 : 1), $2); }
     	| rvalue '*' rvalue	{ $$ = binNode(MUL, $1, $3); }
     	| rvalue '/' rvalue	{ $$ = binNode(DIV, $1, $3); }
     	| rvalue '%' rvalue	{ $$ = binNode(MOD, $1, $3); }
    	| rvalue '+' rvalue	{ $$ = binNode(ADD, $1, $3); }
    	| rvalue '-' rvalue	{ $$ = binNode(SUB, $1, $3); }
      	| rvalue LSH rvalue	{ $$ = binNode(LSH, $1, $3); }
      	| rvalue RSH rvalue	{ $$ = binNode(RSH, $1, $3); }
	| rvalue '<' rvalue	{ $$ = binNode(LT, $1, $3); }
	| rvalue '>' rvalue	{ $$ = binNode(GT, $1, $3); }
	| rvalue GE rvalue	{ $$ = binNode(GE, $1, $3); }
	| rvalue LE rvalue	{ $$ = binNode(LE, $1, $3); }
	| rvalue EQ rvalue	{ $$ = binNode(EQ, $1, $3); }
	| rvalue NE rvalue	{ $$ = binNode(NE, $1, $3); }
    	| rvalue '&' rvalue	{ $$ = binNode(BAND, $1, $3); }
    	| rvalue '^' rvalue	{ $$ = binNode(BXOR, $1, $3); }
    	| rvalue '|' rvalue	{ $$ = binNode(BOR, $1, $3); }
    	| rvalue '?' rvalue ':' rvalue { $$ = binNode(ARELSE, binNode(ARIF, $1, $3), $5); }
	| lvalue ASSIGN rvalue	{ $$ = binNode(ASSIGN, $3, $1); }
       	;

args	: rvalue		{ $$ = binNode(ARG, $1, nilNode(END)); }
	| args ',' rvalue	{ $$ = binNode(ARG, $3, $1); }
	;

%%
static Node *name(Node *nm) {
  int typ = 2, pos = 0;
  if (!gt)
    typ = IDfind(nm->value.s, (long*)&pos);
  else { /* in a goto statment */
    root = IDroot(gtr);
    IDnew(0, nm->value.s, IDtest);
    gtr = IDroot(root);
    if (IDfind(nm->value.s, (long*)IDtest) < 0)
      typ = 2; /* reference to foward label */
    else
      typ = IDfind(nm->value.s, (long*)&pos);
  }
  /* check types */
  if (pos != 0)
    nm = intNode(LOCAL, pos);
  else
    nm = strNode(ADDR, nm->value.s);
  nm->info = typ;
  return nm;
}

static int dim(Node *n)
{
  if (n->type == nodeNil) return 1;
  return n->value.i;
}

int yyerror(const char*); /* declaration may depend on yacc's version/flavor */
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

/* goto auxiliar functions */
static void gtf(int typ, char *name, int attrib, int user) {
  gtr = IDroot(root);
  if ((typ = IDsearch(name, 0, 0, 1)) != -1 && typ != 2)
    yyerror(strcat(strcpy(buf, name),": not a label"));
  root = IDroot(gtr);
}

static void gotos() {
  root = IDroot(gtr);
  IDforall((IDfunc)gtf, 0, 0, 0);
  IDclear();
  gtr = IDroot(root);
}

/* switch auxiliar functions */
static int dups(int typ, char *name, int attrib, int user) {
  if (attrib == user) return 1;
  return 0;
}

static int defs(int typ, char *name, int attrib, int user) {
  if (typ == user) return 1;
  return 0;
}

static Node *swf(Node *val) {
  char *l = mklbl(++lbl);

  root = IDroot(swr);

  /* ensure that it not a duplicate value, and there is no other default */
  if (val == 0)
    if (IDforall((IDfunc)defs, 1, 0, 1) > 0) yyerror("multiple default");
    else IDnew(1, l, 0);
  else
    if(IDforall((IDfunc)dups, val->value.i, 0, 1) > 0) yyerror("duplicate case value");
    else IDnew(0, l, val->value.i);

  swr = IDroot(root);
  return strNode(NAME, l);
}

/* type is 1 for default, 0 for case; name is the label; attrib is the case value. */
static int swt(int type, char *name, int attrib, long user) {
  Node **n = (Node**)user;
  if (name == 0 || *name == 0) return 0;
  if (type != 0) *n = addNode(*n, uniNode(DEFAULT, strNode(ETIQ, name)), -1);
  else *n = addNode(*n, binNode(CASE, strNode(ETIQ, name), intNode(CTE, attrib)), -1);
  return 1;
}

static Node *swg(int pop) {
  Node *n = 0;
  root = IDroot(swr);
  if (pop == 0) IDpush();
  else {
    n = subNode(SWITAB, 0);
    IDprint(0, 1);
    IDforall((IDfunc)swt, (long)&n, 0, 0);
    IDpop();
    /* printNode(n, 0, yynames); */
  }
  swr = IDroot(root);
  return n;
}
