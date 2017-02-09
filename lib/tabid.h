/* $Id: tabid.h,v 1.2 2013/01/22 17:52:56 prs Exp $ */
#ifndef _TABID_H_
#define _TABID_H_

typedef int (*IDfunc)(int,char*,long,long);
void   *IDroot(void *swap);
void	IDpop(void),
	IDpush(void),
	IDclear(void),
	IDprint(int,int);
int	IDnew(int,char*,long),
	IDreplace(int,char*,long),
	IDinsert(int,int,char*,long),
	IDfind(char*,long*),
	IDsearch(char*,long*,int,int),
	IDforall(IDfunc,long,int,int),
	IDlevel(void);

extern int IDdebug; /* set to 1 to get debug message in stdout */

#define IDtest (-1L) /* probe IDfind and IDnew without error messages */

#define IDevery(x,y) IDforall(x,y,0,0)

#endif /* _TABID_H_ */
