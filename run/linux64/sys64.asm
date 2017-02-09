; (C) Pedro Reis dos Santos, 2014

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

; sys6:	mov	r9, [rsp+48]
;sys5:
;	mov	r8, [rsp+40]
;sys4:
;	mov	rcx, [rsp+32]
;sys3:
;	mov	rdx, [rsp+24]
;sys2:
;	mov	rsi, [rsp+16]
;sys1:
;	mov	rdi, [rsp+8]
sys5:
sys4:
sys3:
sys2:
sys1:
sys0:
	syscall
	mov	rcx, 0xfffffffffffff001
	cmp	rax, rcx
	jb	.Lret
	neg	rax
	mov	[errno], rax
	mov	rax, -1
.Lret:	ret

%macro _syscall 3
global	%1
%1 :	mov	eax, %2
	jmp	sys%3
%endmacro
; /usr/include/x86_64-linux-gnu/asm/unistd_64.h

_syscall	read,		  0,	3
_syscall	write,		  1,	3
_syscall	open,		  2,	3
_syscall	close,		  3,	1
_syscall	stat,		  4,	2
_syscall	fstat,		  5,	2
_syscall	lstat,		  6,	2
_syscall	poll,		  7,	3
_syscall	lseek,		  8,	3
_syscall	mmap,		  9,	1
_syscall	mprotect,	 10,	3
_syscall	munmap,		 11,	2
_syscall	brk,		 12,	1
;_syscall	rt_sigaction,	 13,	?
_syscall	rt_sigprocmask,	 14,	4
_syscall	rt_sigreturn,	 15,	1
_syscall	ioctl,		 16,	3
;_syscall	pread64,	 17,	?
;_syscall	pwrite64,	 18,	?
_syscall	readv,		 19,	3
_syscall	writev,		 20,	3
_syscall	access,		 21,	2
_syscall	pipe,		 22,	1
_syscall	select,		 23,	5
_syscall	sched_yield,	 24,	0
_syscall	mremap,		 25,	4
_syscall	msync,		 26,	3
_syscall	mincore,	 27,	3
_syscall	madvise,	 28,	3
;_syscall	shmget,		 29,	?
;_syscall	shmat,		 30,	?
;_syscall	shmctl,		 31,	?
_syscall	dup,		 32,	1
_syscall	dup2,		 33,	2
;_syscall	pause,		 34,	?
_syscall	nanosleep,	 35,	2
_syscall	getitimer,	 36,	2
_syscall	alarm,		 37,	1
_syscall	setitimer,	 38,	3
_syscall	getpid,		 39,	0
_syscall	sendfile,	 40,	4
;_syscall	socket,		 41,	?
;_syscall	connect,	 42,	?
;_syscall	accept,		 43,	?
;_syscall	sendto,		 44,	?
;_syscall	recvfrom,	 45,	?
;_syscall	sendmsg,	 46,	?
;_syscall	recvmsg,	 47,	?
;_syscall	shutdown,	 48,	?
;_syscall	bind,		 49,	?
;_syscall	listen,		 50,	?
;_syscall	getsockname,	 51,	?
;_syscall	getpeername,	 52,	?
;_syscall	socketpair,	 53,	?
;_syscall	setsockopt,	 54,	?
;_syscall	getsockopt,	 55,	?
_syscall	clone,		 56,	4
_syscall	fork,		 57,	0
_syscall	vfork,		 58,	0
_syscall	execve,		 59,	3
_syscall	exit,		 60,	1
_syscall	wait4,		 61,	4
_syscall	kill,		 62,	2
_syscall	uname,		 63,	1
;_syscall	semget,		 64,	?
;_syscall	semop,		 65,	?
;_syscall	semctl,		 66,	?
;_syscall	shmdt,		 67,	?
;_syscall	msgget,		 68,	?
;_syscall	msgsnd,		 69,	?
;_syscall	msgrcv,		 70,	?
;_syscall	msgctl,		 71,	?
_syscall	fcntl,		 72,	3
_syscall	flock,		 73,	2
_syscall	fsync,		 74,	1
_syscall	fdatasync,	 75,	1
_syscall	truncate,	 76,	2
_syscall	ftruncate,	 77,	2
_syscall	getdents,	 78,	3
_syscall	getcwd,		 79,	2
_syscall	chdir,		 80,	1
_syscall	fchdir,		 81,	1
_syscall	rename,		 82,	2
_syscall	mkdir,		 83,	2
_syscall	rmdir,		 84,	1
_syscall	creat,		 85,	2
_syscall	link,		 86,	2
_syscall	unlink,		 87,	1
_syscall	symlink,	 88,	2
_syscall	readlink,	 89,	3
_syscall	chmod,		 90,	2
_syscall	fchmod,		 91,	2
_syscall	chown,		 92,	3
_syscall	fchown,		 93,	3
_syscall	lchown,		 94,	3
_syscall	umask,		 95,	1
_syscall	gettimeofday,	 96,	2
_syscall	getrlimit,	 97,	2
_syscall	getrusage,	 98,	2
_syscall	sysinfo,	 99,	1
;_syscall	times,		100,	?
_syscall	ptrace,		101,	4
_syscall	getuid,		102,	0
_syscall	syslog,		103,	3
_syscall	getgid,		104,	0
_syscall	setuid,		105,	1
_syscall	setgid,		106,	1
_syscall	geteuid,	107,	0
_syscall	getegid,	108,	0
_syscall	setpgid,	109,	2
_syscall	getppid,	110,	0
_syscall	getpgrp,	111,	0
_syscall	setsid,		113,	0
_syscall	setreuid,	113,	2
_syscall	setregid,	114,	2
_syscall	getgroups,	115,	2
_syscall	setgroups,	116,	2
_syscall	setresuid,	117,	3
_syscall	getresuid,	118,	3
_syscall	setresgid,	119,	3
_syscall	getresgid,	120,	3
_syscall	getpgid,	121,	1
_syscall	setfsuid,	122,	1
_syscall	setfsgid,	123,	1
_syscall	getsid,		124,	1
_syscall	capget,		125,	2
_syscall	capset,		126,	2
_syscall	rt_sigpending,		127,	2
;_syscall	rt_sigtimedwait,	128,	?
;_syscall	rt_sigqueueinfo,	129,	?
;_syscall	rt_sigsuspend,		130,	?
;_syscall	sigaltstack,		131,	?
_syscall	utime,		132,	2
_syscall	mknod,		133,	3
_syscall	uselib,		134,	1
_syscall	personality,	135,	1
_syscall	ustat,		136,	2
_syscall	statfs,		137,	2
_syscall	fstatfs,	138,	2
_syscall	sysfs,		139,	3
_syscall	getpriority, 	140,	2
_syscall	setpriority,	141,	3
_syscall	sched_setparam,	142,	2
_syscall	sched_getparam,	143,	2
_syscall	sched_setscheduler,	144,	3
_syscall	sched_getscheduler,	145,	1
_syscall	sched_get_priority_max,	146,	1
_syscall	sched_get_priority_min,	147,	1
_syscall	sched_rr_get_interval,	148,	2
_syscall	mlock,		149,	2
_syscall	munlock,	150,	2
_syscall	mlockall,	151,	1
_syscall	munlockall,	152,	0
_syscall	vhangup,	153,	0
_syscall	modify_ldt,	154,	3
;_syscall	pivot_root,	155,	?
_syscall	_sysctl,	156,	1
_syscall	prctl,		157,	5
;_syscall	arch_prctl,	158,	?
_syscall	adjtimex,	159,	1
_syscall	setrlimit,	160,	2
_syscall	chroot,		161,	1
_syscall	sync,		162,	0
_syscall	acct,		163,	1
_syscall	settimeofday,	164,	2
_syscall	mount,		165,	5
;_syscall	umount2,	166,	?
_syscall	swapon,		167,	2
_syscall	swapoff,	168,	1
_syscall	reboot,		169,	3
_syscall	sethostname,	170,	2
_syscall	setdomainname,	171,	2
_syscall	iopl,		172,	1
_syscall	ioperm,		173,	3
_syscall	create_module,	174,	2
_syscall	init_module,	175,	2
_syscall	delete_module,	176,	1
_syscall	get_kernel_syms,	177,	1
_syscall	query_module,	178,	5
_syscall	quotactl,	179,	4
_syscall	nfsservctl,	180,	3
;_syscall	getpmsg,	181,	?
;_syscall	putpmsg,	182,	?
;_syscall	afs_syscall,	183,	?
;_syscall	afs_syscall,	183,	?
;_syscall	tuxcall,	184,	?
;_syscall	security,	185,	?
;_syscall	gettid,	186,	?
;_syscall	readahead,	187,	?
;_syscall	setxattr,	188,	?
;_syscall	lsetxattr,	189,	?
;_syscall	fsetxattr,	190,	?
;_syscall	getxattr,	191,	?
;_syscall	lgetxattr,	192,	?
;_syscall	fgetxattr,	193,	?
;_syscall	listxattr,	194,	?
;_syscall	llistxattr,	195,	?
;_syscall	flistxattr,	196,	?
;_syscall	removexattr,	197,	?
;_syscall	lremovexattr,	198,	?
;_syscall	fremovexattr,	199,	?
;_syscall	tkill,		200,	?
_syscall	time,		201,	1
;_syscall	time,		201,	?
;_syscall	futex,		202,	?
;_syscall	sched_setaffinity,	203,	?
;_syscall	sched_getaffinity,	204,	?
;_syscall	set_thread_area,	205,	?
;_syscall	io_setup,	206,	?
;_syscall	io_destroy,	207,	?
;_syscall	io_getevents,	208,	?
;_syscall	io_submit,	209,	?
;_syscall	io_cancel,	210,	?
;_syscall	get_thread_area,	211,	?
;_syscall	lookup_dcookie,	212,	?
;_syscall	epoll_create,	213,	?
;_syscall	epoll_ctl_old,	214,	?
;_syscall	epoll_wait_old,	215,	?
;_syscall	remap_file_pages,	216,	?
;_syscall	getdents64,	217,	?
;_syscall	getdents64,	217,	?
;_syscall	set_tid_address,	218,	?
;_syscall	restart_syscall,	219,	?
;_syscall	semtimedop,	220,	?
;_syscall	fadvise64,	221,	?
;_syscall	timer_create,	222,	?
;_syscall	timer_settime,	223,	?
;_syscall	timer_gettime,	224,	?
;_syscall	timer_getoverrun,	225,	?
;_syscall	timer_delete,	226,	?
;_syscall	clock_settime,	227,	?
;_syscall	clock_gettime,	228,	?
;_syscall	clock_getres,	229,	?
;_syscall	clock_nanosleep,	230,	?
;_syscall	exit_group,	231,	?
;_syscall	epoll_wait,	232,	?
;_syscall	epoll_ctl,	233,	?
;_syscall	tgkill,		234,	?
;_syscall	utimes,		235,	?
;_syscall	vserver,	236,	?
;_syscall	mbind,		237,	?
;_syscall	set_mempolicy,	238,	?
;_syscall	get_mempolicy,	239,	?
;_syscall	mq_open,	240,	?
;_syscall	mq_unlink,	241,	?
;_syscall	mq_timedsend,	242,	?
;_syscall	mq_timedreceive,	243,	?
;_syscall	mq_notify,	244,	?
;_syscall	mq_getsetattr,	245,	?
;_syscall	kexec_load,	246,	?
;_syscall	waitid,		247,	?
;_syscall	add_key,	248,	?
;_syscall	request_key,	249,	?
;_syscall	keyctl,		250,	?
;_syscall	ioprio_set,	251,	?
;_syscall	ioprio_get,	252,	?
;_syscall	inotify_init,	253,	?
;_syscall	inotify_add_watch,	254,	?
;_syscall	inotify_rm_watch,	255,	?
;_syscall	migrate_pages,	256,	?
;_syscall	openat,		257,	?
;_syscall	mkdirat,	258,	?
;_syscall	mknodat,	259,	?
;_syscall	fchownat,	260,	?
;_syscall	futimesat,	261,	?
;_syscall	newfstatat,	262,	?
;_syscall	unlinkat,	263,	?
;_syscall	renameat,	264,	?
;_syscall	linkat,		265,	?
;_syscall	symlinkat,	266,	?
;_syscall	readlinkat,	267,	?
;_syscall	fchmodat,	268,	?
;_syscall	faccessat,	269,	?
;_syscall	pselect6,	270,	?
;_syscall	ppoll,		271,	?
;_syscall	unshare,	272,	?
;_syscall	set_robust_list,	273,	?
;_syscall	get_robust_list,	274,	?
;_syscall	splice,		275,	?
;_syscall	tee,		276,	?
;_syscall	sync_file_range,	277,	?
;_syscall	vmsplice,	278,	?
;_syscall	move_pages,	279,	?
;_syscall	utimensat,	280,	?
;_syscall	epoll_pwait,	281,	?
;_syscall	signalfd,	282,	?
;_syscall	timerfd_create,	283,	?
;_syscall	eventfd,	284,	?
;_syscall	fallocate,	285,	?
;_syscall	timerfd_settime,	286,	?
;_syscall	timerfd_gettime,	287,	?
;_syscall	accept4,	288,	?
;_syscall	signalfd4,	289,	?
;_syscall	eventfd2,	290,	?
;_syscall	epoll_create1,	291,	?
;_syscall	dup3,		292,	?
;_syscall	pipe2,		293,	?
;_syscall	inotify_init1,	294,	?
;_syscall	preadv,		295,	?
;_syscall	pwritev,	296,	?
;_syscall	rt_tgsigqueueinfo,	297,	?
;_syscall	perf_event_open,	298,	?
;_syscall	recvmmsg,	299,	?
;_syscall	fanotify_init,	300,	?
;_syscall	fanotify_mark,	301,	?
;_syscall	prlimit64,	302,	?
