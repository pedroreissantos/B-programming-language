/* $Id: node.c,v 1.1 2014/02/13 12:28:19 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#ifdef __STRICT_ANSI__
extern char *strdup(const char *); /* strdup is not ANSI */
#endif
#include "node.h"
int yyerror(char*);
extern int yylineno;

Node *newNode(NodeType t, int attrib, unsigned nops) {
    Node *p;
    size_t size;
    unsigned i;

    /* allocate node */
    size = sizeof(Node) + (t == nodeOpr ? nops * sizeof(Node*) : 0);
    if ((p = malloc(size)) == NULL) {
	yyerror("out of memory");
	exit(2);
    }

    /* copy information */
    p->type = t;
    p->attrib = attrib;
    p->line = yylineno;
    p->user = 0;
    p->state = 0;
    p->info = -1;
    p->listen = 0;
    p->place = -1;
    p->value.sub.num = nops;
    if (nops > 0) {
	for (i = 0; i < nops; i++)
	    p->value.sub.n[i] = 0;		/* ensure NULL pointers */
    }

    return p;
}

Node *nilNode(int attrib) {
    return newNode(nodeNil, attrib, 0);
}
Node *uniNode(int attrib, Node *n1) {
  return subNode(attrib, 1, n1);
}
Node *binNode(int attrib, Node *n1, Node *n2) {
  return subNode(attrib, 2, n1, n2);
}
Node *triNode(int attrib, Node *n1, Node *n2, Node *n3) {
  return subNode(attrib, 3, n1, n2, n3);
}

Node *quadNode(int attrib, Node *n1, Node *n2, Node *n3, Node *n4) {
  return subNode(attrib, 4, n1, n2, n3, n4);
}

Node *pentNode(int attrib, Node *n1, Node *n2, Node *n3, Node *n4, Node *n5) {
  return subNode(attrib, 5, n1, n2, n3, n4, n5);
}

Node *intNode(int attrib, regint i) {
    Node *p = newNode(nodeInt, attrib, 0);
    if (p != NULL) p->value.i = i;
    return p;
}

Node *realNode(int attrib, double d) {
    Node *p = newNode(nodeReal, attrib, 0);
    if (p != NULL) p->value.r = d;
    return p;
}

Node *dataNode(int attrib, int size, void *user) {
    Node *p = newNode(nodeData, attrib, 0);
    if (p != NULL) {
      p->value.d.size = size;
      p->value.d.data = user;
    }
    return p;
}

Node *strNode(int attrib, char *s) {
    Node *p = newNode(nodeStr, attrib, 0);
    if (p != NULL) p->value.s = s;
    return p;
}

Node *subNode(int oper, unsigned nops, ...) {
    va_list ap;
    Node *p = newNode(nodeOpr, oper, nops);
    unsigned i;

    if (p == NULL) return 0;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
	p->value.sub.n[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

Node *revNode(int oper, unsigned nops, ...) {
    va_list ap;
    Node *p, *q;
    unsigned i;

    p = newNode(nodeOpr, oper, nops < 3 ? nops : 2);
    if (p == NULL) return 0;
    va_start(ap, nops);
    if (nops > 0)
	p->value.sub.n[0] = va_arg(ap, Node*);
    for (i = 1; i < nops; i++) {
	p->value.sub.n[1] = va_arg(ap, Node*);
	if (i + 1 >= nops) break;
        q = newNode(nodeOpr, oper, 2);
	q->value.sub.n[0] = p;
        p = q;
    }
    va_end(ap);
    return p;
}

Node *seqNode(int oper, unsigned nops, ...) {
    va_list ap;
    Node *p, *q;
    unsigned i;

    q = p = newNode(nodeOpr, oper, nops < 3 ? nops : 2);
    if (p == NULL) return 0;
    va_start(ap, nops);
    for (i = 0; i < nops; i++) {
	p->value.sub.n[0] = va_arg(ap, Node*);
	if (nops - i < 3) {
	    p->value.sub.n[1] = va_arg(ap, Node*);
	    break;
	} else {
	    p->value.sub.n[1] = newNode(nodeOpr, oper, nops - i < 3 ? nops - i : 2);
	    if (p->value.sub.n[1] == NULL) {
	        freeNode(q);
		q = 0;
		break;
	    }
	}
	p = p->value.sub.n[1];
    }
    va_end(ap);
    return q;
}

Node *addNode(Node *base, Node *node, unsigned pos) {
    Node *p;
    size_t size;

    if (base == 0 || base->type != nodeOpr) return 0;
    size = sizeof(Node) + (base->value.sub.num + 1) * sizeof(Node*);
    if ((p = realloc(base, size)) == NULL) {
        yyerror("out of memory");
        exit(2);
    }
    if (pos > p->value.sub.num)
    	pos = p->value.sub.num; /* do not overflow */
    if (pos < p->value.sub.num)
      memmove(&p->value.sub.n[pos+1], &p->value.sub.n[pos],
	      (p->value.sub.num-pos)*sizeof(Node*));
    p->value.sub.n[pos] = node;
    p->value.sub.num++;
    return p;
}

Node *removeNode(Node *base, unsigned pos) {
    Node *p;

    if (base == 0 || base->type != nodeOpr) return 0;
    if (pos >= base->value.sub.num) return 0;

    base->value.sub.num--;
    p = base->value.sub.n[pos];
    memmove(&base->value.sub.n[pos], &base->value.sub.n[pos+1],
	      (base->value.sub.num-pos)*sizeof(Node*));
    return p;
}

void *userNode(Node *p, void *user) {
    if (p == 0) return 0;
    if (user == 0) return p->user;
    return p->user = user;
}

Node *compareNode(Node *p, Node *n, int full) {
    Node *x;
    unsigned i;

    if (p == n) return 0; /* is the same node */
    if (p->type != n->type) return n;
    if (p->attrib != n->attrib) return n;

    if (p->type == nodeOpr)
	for (i = 0; i < p->value.sub.num; i++) {
	    if ((x = compareNode(n->value.sub.n[i], p->value.sub.n[i], full)) != 0)
		return x;
	}
    else if (p->type == nodeStr && strcmp(n->value.s, p->value.s) != 0)
	return n;
    else if (p->type == nodeInt && n->value.i != p->value.i)
	return n;
    else if (p->type == nodeReal && n->value.r != p->value.r)
	return n;
    else if (p->type == nodeData && n->value.d.size != p->value.d.size &&
	     memcmp(n->value.d.data, p->value.d.data, n->value.d.size) != 0)
	return n;

    if (full == 0) return 0;
    if((full & nodeUser)  &&  p->user != n->user)   return n;
    if((full & nodeLine)  &&  p->line != n->line)   return n;
    if((full & nodeState) &&  p->state != n->state) return n;
    if((full & nodeInfo)  &&  p->info != n->info)   return n;
    if((full & nodePlace) &&  p->place != n->place) return n;
    return 0;
}

Node *copyNode(Node *p) {
    Node *n;
    size_t size = sizeof(Node);
    unsigned i;

    if (p == 0) return 0;

    /* allocate node */
    if (p->type == nodeOpr)
	size += p->value.sub.num * sizeof(Node*);
    if ((n = malloc(size)) == NULL) {
	yyerror("out of memory");
	exit(2);
    }

    /* copy information */
    memcpy(n, p, size);
    if (p->type == nodeStr)
	n->value.s = strdup(p->value.s);
    if (p->type == nodeOpr)
	for (i = 0; i < p->value.sub.num; i++)
	    n->value.sub.n[i] = copyNode(p->value.sub.n[i]);

    return n;
}

void freeNode(Node *p) {
    unsigned i;

    if (p == 0) return;
    if (p->type == nodeOpr) {
	for (i = 0; i < p->value.sub.num; i++)
	    freeNode(p->value.sub.n[i]);
    }
    free (p);
}

int debugNode;
static int print(Node *p, FILE *fp, char *tab[], int lev) {
    unsigned i, cnt = 0;

    if (p == 0) return cnt;
    cnt++;
    if (p->type == nodeOpr) fprintf(fp,"\n%*s(", 2*lev, " ");
    if (debugNode) fprintf(fp," [%lx]", (long)p);
    if (tab != 0)
      fprintf(fp," %s:", tab[p->attrib]);
    else
      fprintf(fp," %d:", p->attrib);
    switch (p->type) {
	case nodeNil: break;
	case nodeInt: fprintf(fp,PRTREG, p->value.i); break;
	case nodeReal: fprintf(fp,"%g", p->value.r); break;
	case nodeStr: fprintf(fp,"\"%s\"", p->value.s); break;
	case nodeData:
	    fprintf(fp,"%d[", p->value.d.size);
	    for (i = 0; i < (unsigned)p->value.d.size; i++)
	      fprintf(fp,"%2.2X", ((unsigned char*)p->value.d.data)[i]);
	    fprintf(fp,"]");
	    break;
	case nodeOpr: 
	    for (i = 0; i < p->value.sub.num; i++)
		cnt += print(p->value.sub.n[i], fp, tab, lev+1);
	    fprintf(fp,")");
	    break;
    }
    return cnt;
}

void printNode(Node *p, FILE *fp, char *tab[]) {
    if (fp == 0) fp = stdout;
    fprintf(fp, "\n[#%d]\n", print(p, fp, tab, 0));
}

void visitNode(Node *p, int mode, void (*func[])(Node*)) {
    unsigned i;
    if (p == 0) return;
    if (mode & PRE && func[p->attrib])
    	func[p->attrib](p);
    if (p->type == nodeOpr)
	for (i = 0; i < p->value.sub.num; i++)
	    visitNode(p->value.sub.n[i], mode, func);
    if (mode == POS && func[p->attrib])
    	func[p->attrib](p);
}

void listenNode(Node *p, int mode) {
    unsigned i;
    if (p == 0) return;
    if (mode & PRE && p->listen)
    	p->listen(p);
    if (p->type == nodeOpr)
	for (i = 0; i < p->value.sub.num; i++)
	    listenNode(p->value.sub.n[i], mode);
    if (mode == POS && p->listen)
    	p->listen(p);
}

void listenerNode(Node *p, void (*func)(Node*)) {
	p->listen = func;
}

void pathNode(Node *p, FILE *fp, char *tab[], char *base) {
    unsigned i;
    char code[12], *comp = code, *name;

    if (p == 0) return;
    if (fp == 0) fp = stdout;
    if (tab != 0)
      comp = tab[p->attrib];
    else
      sprintf(code,"%d", p->attrib);
    name = malloc(strlen(base)+strlen(comp)+2);
    sprintf(name, "%s/%s", base, comp);
    switch (p->type) {
	case nodeNil: fprintf(fp, "%s.\n", name); break;
	case nodeInt: fprintf(fp,"%s: " PRTREG "\n", name, p->value.i); break;
	case nodeReal: fprintf(fp,"%s: %g\n", name, p->value.r); break;
	case nodeStr: fprintf(fp,"%s: \"%s\"\n", name, p->value.s); break;
	case nodeData:
	    fprintf(fp,"%s: %d[", name, p->value.d.size);
	    for (i = 0; i < (unsigned)p->value.d.size; i++)
	      fprintf(fp,"%2.2X", ((unsigned char*)p->value.d.data)[i]);
	    fprintf(fp,"]\n");
	    break;
	case nodeOpr: 
	    for (i = 0; i < p->value.sub.num; i++)
		pathNode(p->value.sub.n[i], fp, tab, name);
	    break;
    }
    free(name);
}
