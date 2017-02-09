/* $Id: tabid.c,v 1.2 2013/01/22 17:52:56 prs Exp $ */
#include "tabid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yyerror(char*);
static char buf[80]; /* for error messages */
int IDdebug;

static struct id { int type; long attrib; char *name; struct id *next; } *root = 0;
/* define a new  ID => 'name' != 0 (if 'next' is 0 then EOF)
   define a new BUCKET => 'name' == 0 && 'next' points to previous BUCKET
*/

void *IDroot(void *swap) {
  struct id *old = root;
  root = (struct id *)swap;
  return old;
}

static int level;
static void IDadd(int typ, char *s, long attrib) {
  struct id *aux = (struct id*)malloc(sizeof(struct id));

  if (aux == 0) { yyerror("No memory.\n"); return; }
  aux->name = s;
  aux->next = root;
  aux->type = typ;
  aux->attrib = attrib;
  root = aux;
  if (IDdebug != 0) {
    if (s == 0) printf("#>>PUSH=%d\n", level);
    else printf("#>>ADD=%s\n", s);
  }
}

void IDpush() { level++; IDadd(0,0,0); }
void IDpop() {
  struct id *aux;

  while ((aux = root) != 0) {
    root = aux->next;
    if (aux->name == 0) { free(aux); break; }
    free(aux);
  }
  if (IDdebug != 0) printf("#>>POP=%d\n", level);
  level--;
}
void IDclear() { while (level > 0) IDpop(); }

/* insert a new ID into the current bucket, return:
   1 - if is new ID (might have been defined in an upper bucket)
   0 - there is an ID with the same name in the bucket
*/
int IDnew(int typ, char *s, long attrib) {
  struct id *aux;

  for (aux = root; aux != 0 && aux->name != 0; aux = aux->next)
    if (strcmp(aux->name, s) == 0) {
      if (attrib != IDtest) {
        sprintf(buf, "\t%s: already defined.\n", s);
        yyerror(buf);
      }
      return 0;
    }
  IDadd(typ, s, attrib);
  return 1;
}

int IDinsert(int lev, int typ, char *s, long attrib) {
  struct id *aux, *scout = root, **base;

  if (lev > level) { yyerror("Invalid scope level"); return 0; }
  if (lev == level) return IDnew(typ, s, attrib);

  for (lev = level - lev; lev > 0; lev--) {
    while (scout->name != 0) scout = scout->next;
    base = &scout->next;
    scout = scout->next;
  }

  aux = (struct id*)malloc(sizeof(struct id));
  if (aux == 0) { yyerror("No memory.\n"); return 0; }
  aux->name = s;
  aux->next = *base;
  aux->type = typ;
  aux->attrib = attrib;
  *base = aux;
  if (IDdebug != 0) printf("#>>INSERT(%d)=%s\n", lev, s);
  return 1;
}

int IDreplace(int typ, char *s, long attrib) {
  struct id *aux;

  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name != 0 && strcmp(aux->name, s) == 0) {
      aux->type = typ;
      aux->attrib = attrib;
      return 1;
    }
  return -1;
}

/* find an ID, return:
   -1 - if no ID can be found in any visible bucket up to the root
   type - there is an accessible ID previously defined
*/
int IDfind(char *s, long *attrib) {
  struct id *aux;

  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name != 0 && strcmp(aux->name, s) == 0) {
      if (attrib != 0 && attrib != ((long*)IDtest)) *attrib = aux->attrib;
      return aux->type;
    } /* else if (aux->name == 0 && lev > 0 && --lev == 0) break; */
  if (attrib != ((long*)IDtest)) {
    sprintf(buf, "%s: undefined.", s);
    yyerror(buf);
  }
  return -1;
}

int IDsearch(char *s, long *attrib, int skip, int lev) {
  struct id *aux = root;

  if (skip > level) skip = level;
  while (skip-- > 0) { /* skip the first 'skip' levels */
    while (aux->name != 0) aux = aux->next;
    aux = aux->next;
  }
  for (; aux != 0; aux = aux->next)
    if (aux->name != 0 && strcmp(aux->name, s) == 0) {
      if (attrib != 0 && attrib != ((long*)IDtest)) *attrib = aux->attrib;
      return aux->type;
    } else
      if (aux->name == 0 && lev > 0 && --lev == 0)
	break; /* stop after 'lev' levels */
  if (attrib != ((long*)IDtest)) {
    sprintf(buf, "%s: undefined.", s);
    yyerror(buf);
  }
  return -1;
}

int IDlevel() { return level; }

int IDforall(IDfunc f, long user, int skip, int lev) {
  struct id *aux;
  int cnt = 0, ret;

  if (skip > level) skip = level;
  while (skip-- > 0) { /* skip the first 'skip' levels */
    while (aux->name != 0) aux = aux->next;
    aux = aux->next;
  }

  for (aux = root; aux != 0; aux = aux->next, cnt += ret)
    if (aux->name == 0) {
      if ((ret = (*f)(0,"",0,user)) < 0)
        break;
      if (lev > 0 && --lev == 0)
	break; /* stop after 'lev' levels */
    }
    else
      if ((ret = (*f)(aux->type, aux->name, aux->attrib, user)) < 0)
        break;

  return cnt;
}

void IDprint(int skip, int lev) {
  struct id *aux;

  if (skip > level) skip = level;
  while (skip-- > 0) { /* skip the first 'skip' levels */
    while (aux->name != 0) aux = aux->next;
    aux = aux->next;
  }
  for (aux = root; aux != 0; aux = aux->next)
    if (aux->name == 0) {
      printf(" :");
      if (lev > 0 && --lev == 0)
	break; /* stop after 'lev' levels */
    }
    else
      printf(" %s:%d#%ld", aux->name, aux->type, aux->attrib);
  printf("\n");
}
