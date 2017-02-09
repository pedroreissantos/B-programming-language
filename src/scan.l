%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "node.h" 
#include "y.tab.h"
char *dupstr(const char *s);
int yyerror(char *s), octal(char *s), character(char *s);
%}
%x COM STR
%%
<COM>.|\n		;
<COM>"*/"		BEGIN 0;

"/*"			BEGIN COM;
"auto"			return AUTO;
"extrn"			return EXTRN;
"if"			return IF;
"else"			return ELSE;
"while"			return WHILE;
"case"			return CASE;
"default"		return DEFAULT;
"switch"		return SWITCH;
"break"			return BREAK;
"goto"			return GOTO;
"return"		return RETURN;
"<="			return LE;
">="			return GE;
"=="			return EQ;
"!="			return NE;
"<<"			return LSH;
">>"			return RSH;
"++"			return INC;
"--"			return DEC;
"="			return ASSIGN;

[a-zA-Z_\b][a-zA-Z_\b0-9]* yylval.s = dupstr(yytext); return NAME;
\'(([^*']|\*[nrt*'"()0]){1,4})\' yylval.i = character(yytext+1); return CTE;
\"([^*"]|\*.)*\"	yylval.s = malloc(yyleng); *yylval.s = 0; REJECT;
\"			BEGIN STR;
<STR>\"			BEGIN 0; return STRING;
<STR>"*n"		strcat(yylval.s, "\n");
<STR>"*t"		strcat(yylval.s, "\t");
<STR>"*0"		strcat(yylval.s, "\0");
<STR>"*("		strcat(yylval.s, "{");
<STR>"*)"		strcat(yylval.s, "}");
<STR>\*[*'"]		strcat(yylval.s, yytext+1);
<STR>\*.		yyerror("invalid escape sequence in string");
<STR>.|\n		strcat(yylval.s, yytext);
[1-9][0-9]*		{ errno = 0; yylval.i = strtol(yytext, 0, 0);
			  if (errno == ERANGE) yyerror("decimal overflow");
			  return CTE; }
0[0-9]*			yylval.i = octal(yytext); return CTE;
[-+*/%!&|~^<>()?:;,\[\]{}#]	return *yytext;

[ \n\r\t]+		;

.			yyerror("unknown character"); /* -Wall */ if (0) { REJECT; unput    (*yytext); input(); }
%%
int yywrap(void) {
  if (YYSTATE == COM) yyerror("unterminated comment");
  if (YYSTATE == STR) yyerror("unterminated string");
  return 1;
} 
char *getyytext() { return yytext; }
int character(char *s)
{
  int val, i, pos;
  for (val = pos = i = 0; s[pos] != '\'' && i < 4; i++, pos++) {
    if (s[pos] == '*')
      switch(s[++pos]) {
        case '*': case '(': case ')':  case '\'': case '"':  break;
	case 't': s[pos] = '\t'; break;
	case 'n': s[pos] = '\n'; break;
	case '0': s[pos] = '\0'; break;
	default: yyerror("invalid character escape sequence"); break;
      }
    val |= s[pos] << (i*8);
  }
  if (i == 4 && s[pos] != '\'') yyerror("character sequence too long");
  return val;
}

int octal(char *s)
{
  int i, a = 0, b = 0;

  for (i = 0; i < strlen(s); i++) {
    if (s[i] < '0' || s[i] > '9') break;
    b = b * 8 + s[i] - '0';
    if (b < a) {
      yyerror("octal overflow");
      break;
    }
    a = b;
  }
  return a;
}
