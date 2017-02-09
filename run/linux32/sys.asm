; (C) Pedro Reis dos Santos, 2003

; Linux system calls:
; user-visible error numbers are in the range -1 - -124: see <asm-i386/errno.h>
;	if ((unsigned long)(res) >= (unsigned long)(-125)) {
;		errno = -(res);
;		res = -1;
;	}

segment .data
global errno
errno	dd	0

segment	.text
global _brk
_brk:	jmp brk

sys5:
	mov	edi, [esp+20]
sys4:
	mov	esi, [esp+16]
sys3:
	mov	edx, [esp+12]
sys2:
	mov	ecx, [esp+8]
sys1:
	mov	ebx, [esp+4]
sys0:
	int	0x80
	cmp	eax, 0xfffff001
	jb	.Lret
	neg	eax
	mov	[errno], eax
	mov	eax, -1
.Lret:	ret

%macro _syscall 3
global	%1
%1 :	mov	eax, %2
	jmp	sys%3
%endmacro
; from asm/unistd.h

_syscall	exit	,		  1,	1
_syscall	fork	,		  2,	0
_syscall	read	,		  3,	3
_syscall	write	,		  4,	3
_syscall	open	,		  5,	3
_syscall	close	,		  6,	1
_syscall	waitpid	,		  7,	3
_syscall	creat	,		  8,	2
_syscall	link	,		  9,	2
_syscall	unlink	,		 10,	1
_syscall	execve	,		 11,	3
_syscall	chdir	,		 12,	1
_syscall	time	,		 13,	1
_syscall	mknod	,		 14,	3
_syscall	chmod	,		 15,	2
_syscall	lchown	,		 16,	3
;_syscall	break	,		 17,	?	; Not in Linux 2.0
;_syscall	oldstat	,		 18,	?	; obsolete
_syscall	lseek	,		 19,	3
_syscall	getpid	,		 20,	0
_syscall	mount	,		 21,	5
_syscall	umount	,		 22,	1
_syscall	setuid	,		 23,	1
_syscall	getuid	,		 24,	0
_syscall	stime	,		 25,	1
_syscall	ptrace	,		 26,	4
_syscall	alarm	,		 27,	1
;_syscall	oldfstat,		 28,	?	; obsolete
_syscall	_pause	,		 29,	0
_syscall	utime	,		 30,	2
;_syscall	stty	,		 31,	?	; Not in Linux 2.0
;_syscall	gtty	,		 32,	?	; Not in Linux 2.0
_syscall	access	,		 33,	2
_syscall	nice	,		 34,	1
;_syscall	ftime	,		 35,	?	; Not in Linux 2.0
_syscall	sync	,		 36,	0
_syscall	kill	,		 37,	2
_syscall	rename	,		 38,	2
_syscall	mkdir	,		 39,	2
_syscall	rmdir	,		 40,	1
_syscall	dup	,		 41,	1
_syscall	pipe	,		 42,	1
_syscall	_times	,		 43,	1
;_syscall	prof	,		 44,	?	; Not in Linux 2.0
_syscall	brk	,		 45,	1
_syscall	setgid	,		 46,	1
_syscall	getgid	,		 47,	0
_syscall	signal	,		 48,	2
_syscall	geteuid	,		 49,	0
_syscall	getegid	,		 50,	0
_syscall	acct	,		 51,	1
;_syscall	umount2	,		 52,	?	; Not documented
;_syscall	lock	,		 53,	?	; Not in Linux 2.0
_syscall	ioctl	,		 54,	3
_syscall	fcntl	,		 55,	3
;_syscall	mpx	,		 56,	?	; Not in Linux 2.0
_syscall	setpgid	,		 57,	2
;_syscall	ulimit	,		 58,	?	; Not in Linux 2.0
;_syscall	oldolduname,		 59,	?	; obsolete
_syscall	umask	,		 60,	1
_syscall	chroot	,		 61,	1
_syscall	ustat	,		 62,	2
_syscall	dup2	,		 63,	2
_syscall	getppid	,		 64,	0
_syscall	getpgrp	,		 65,	0
_syscall	setsid	,		 66,	0
;_syscall	sigaction,		 67,	?
;_syscall	sgetmask,		 68,	?
;_syscall	ssetmask,		 69,	?
_syscall	setreuid,		 70,	2
_syscall	setregid,		 71,	2
_syscall	sigsuspend,		 72,	1
_syscall	sigpending,		 73,	1
_syscall	sethostname,		 74,	2
_syscall	setrlimit,		 75,	2
_syscall	getrlimit,		 76,	2
_syscall	getrusage,		 77,	2
_syscall	gettimeofday,		 78,	2
_syscall	settimeofday,		 79,	2
_syscall	getgroups,		 80,	2
_syscall	setgroups,		 81,	2
_syscall	select	,		 82,	5
_syscall	symlink	,		 83,	2
;_syscall	oldlstat,		 84,	?	; obsolete
_syscall	readlink,		 85,	3
_syscall	uselib	,		 86,	1
_syscall	swapon	,		 87,	2
_syscall	reboot	,		 88,	3
_syscall	readdir	,		 89,	3
_syscall	mmap	,		 90,	1
_syscall	munmap	,		 91,	2
_syscall	truncate,		 92,	2
_syscall	ftruncate,		 93,	2
_syscall	fchmod	,		 94,	2
_syscall	fchown	,		 95,	3
_syscall	getpriority,	 	 96,	2
_syscall	setpriority,		 97,	3
;_syscall	profil	,		 98,	?	; Not documented
_syscall	statfs	,		 99,	2
_syscall	fstatfs	,		100,	2
_syscall	ioperm	,		101,	3
_syscall	socketcall,		102,	2
_syscall	syslog	,		103,	3
_syscall	setitimer,		104,	3
_syscall	getitimer,		105,	2
_syscall	stat	,		106,	2
_syscall	lstat	,		107,	2
_syscall	fstat	,		108,	2
;_syscall	olduname,		109,	?	; obsolete
_syscall	iopl	,		110,	1
_syscall	vhangup	,		111,	0
_syscall	idle	,		112,	0
_syscall	vm86old	,		113,	1
_syscall	wait4	,		114,	4
_syscall	swapoff	,		115,	1
_syscall	sysinfo	,		116,	1
_syscall	ipc	,		117,	5
_syscall	fsync	,		118,	1
_syscall	sigreturn,		119,	1
_syscall	clone	,		120,	4
_syscall	setdomainname,		121,	2
_syscall	uname	,		122,	1
_syscall	modify_ldt,		123,	3
_syscall	adjtimex,		124,	1
_syscall	mprotect,		125,	3
_syscall	sigprocmask,		126,	3
_syscall	create_module,		127,	2
_syscall	init_module,		128,	2
_syscall	delete_module,		129,	1
_syscall	get_kernel_syms,	130,	1
_syscall	quotactl,		131,	4
_syscall	getpgid	,		132,	1
_syscall	fchdir	,		133,	1
_syscall	bdflush	,		134,	2
_syscall	sysfs	,		135,	3
_syscall	personality,		136,	1
;_syscall	afs_syscall,		137,	?	; Not in Linux 2.0
_syscall	setfsuid,		138,	1
_syscall	setfsgid,		139,	1
_syscall	_llseek	,		140,	5
_syscall	getdents,		141,	3
;_syscall	_newselect,		142,	?
_syscall	flock	,		143,	2
_syscall	msync	,		144,	3
_syscall	readv	,		145,	3
_syscall	writev	,		146,	3
_syscall	getsid	,		147,	1
_syscall	fdatasync,		148,	1
_syscall	_sysctl	,		149,	1
_syscall	mlock	,		150,	2
_syscall	munlock	,		151,	2
_syscall	mlockall,		152,	1
_syscall	munlockall,		153,	0
_syscall	sched_setparam,		154,	2
_syscall	sched_getparam,		155,	2
_syscall	sched_setscheduler,	156,	3
_syscall	sched_getscheduler,	157,	1
_syscall	sched_yield,		158,	0
_syscall	sched_get_priority_max,	159,	1
_syscall	sched_get_priority_min,	160,	1
_syscall	sched_rr_get_interval,	161,	2
_syscall	nanosleep,		162,	2
_syscall	mremap	,		163,	4
_syscall	setresuid,		164,	3
_syscall	getresuid,		165,	3
_syscall	vm86	,		166,	2
_syscall	query_module,		167,	5
_syscall	poll	,		168,	3
_syscall	nfsservctl,		169,	3
_syscall	setresgid,		170,	3
_syscall	getresgid,		171,	3
_syscall	prctl	,		172,	5
_syscall	rt_sigreturn,		173,	1
;_syscall	rt_sigaction,		174,	?
;_syscall	rt_sigprocmask,		175,	4
;_syscall	rt_sigpending,		176,	2
;_syscall	rt_sigtimedwait,	177,	?
;_syscall	rt_sigqueueinfo,	178,	?
;_syscall	rt_sigsuspend,		179,	?
_syscall	pread	,		180,	4
_syscall	pwrite	,		181,	4
_syscall	chown	,		182,	3
_syscall	getcwd	,		183,	2
_syscall	capget	,		184,	2
_syscall	capset	,		185,	2
;_syscall	sigaltstack,		186,	?	; conforms to XPG4-UNIX
_syscall	sendfile,		187,	4
;_syscall	getpmsg	,		188,	?	; Not documented
;_syscall	putpmsg	,		189,	?	; Not documented
_syscall	vfork	,		190,	1
;_syscall	ugetrlimit,		191,	?	; Not documented
;_syscall	mmap2	,		192,	?	; Not documented
;_syscall	truncate64,		193,	?	; Not documented
;_syscall	ftruncate64,		194,	?	; Not documented
;_syscall	stat64	,		195,	?	; Not documented
;_syscall	lstat64	,		196,	?	; Not documented
;_syscall	fstat64	,		197,	?	; Not documented
;_syscall	lchown32,		198,	?	; Not documented
;_syscall	getuid32,		199,	?	; Not documented
;_syscall	getgid32,		200,	?	; Not documented
;_syscall	geteuid32,		201,	?	; Not documented
;_syscall	getegid32,		202,	?	; Not documented
;_syscall	setreuid32,		203,	?	; Not documented
;_syscall	setregid32,		204,	?	; Not documented
;_syscall	getgroups32,		205,	?	; Not documented
;_syscall	setgroups32,		206,	?	; Not documented
;_syscall	fchown32,		207,	?	; Not documented
;_syscall	setresuid32,		208,	?	; Not documented
;_syscall	getresuid32,		209,	?	; Not documented
;_syscall	setresgid32,		210,	?	; Not documented
;_syscall	getresgid32,		211,	?	; Not documented
;_syscall	chown32	,		212,	?	; Not documented
;_syscall	setuid32,		213,	?	; Not documented
;_syscall	setgid32,		214,	?	; Not documented
;_syscall	setfsuid32,		215,	?	; Not documented
;_syscall	setfsgid32,		216,	?	; Not documented
;_syscall	pivot_root,		217,	?	; For boot only
;_syscall	mincore	,		218,	3
_syscall	madvise	,		219,	3
;_syscall	madvise1,		219,	?	; to be removed
;_syscall	getdents64,		220,	?	; Not documented
;_syscall	fcntl64	,		221,	?	; Not documented
