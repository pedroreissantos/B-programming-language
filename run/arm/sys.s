@ (C) Pedro Reis dos Santos, 2013

@ Linux system calls:
@ user-visible error numbers are in the range -1 - -124: see <asm-i386/errno.h>
@	if ((unsigned long)(res) >= (unsigned long)(-125)) {
@		errno = -(res);
@		res = -1;
@	}

.section .data
.global errno
errno: .word	0

.section	.text

doit:
	swi $0
    ldr r1, =0xfffff001
	cmp	r0, r1
	blt	.Lret
	rsb	r0, r0, #0
    ldr r1, =errno
    str r0, [r1]
    ldr r0, =-1
.Lret:	bx lr

.global restart_syscall
restart_syscall: ldr r7, =0
    b doit
.global exit
exit: ldr r7, =1
    b doit
.global fork
fork: ldr r7, =2
    b doit
.global read
read: ldr r7, =3
    b doit
.global write
write: ldr r7, =4
    b doit
.global open
open: ldr r7, =5
    b doit
.global close
close: ldr r7, =6
    b doit

.global creat
creat: ldr r7, =8
    b doit
.global link
link: ldr r7, =9
    b doit
.global unlink
unlink: ldr r7, =10
    b doit
.global execve
execve: ldr r7, =11
    b doit
.global chdir
chdir: ldr r7, =12
    b doit
.global time
time: ldr r7, =13
    b doit
.global mknod
mknod: ldr r7, =14
    b doit
.global chmod
chmod: ldr r7, =15
    b doit
.global lchown
lchown: ldr r7, =16
    b doit

.global lseek
lseek: ldr r7, =19
    b doit
.global getpid
getpid: ldr r7, =20
    b doit
.global mount
mount: ldr r7, =21
    b doit
.global umount
umount: ldr r7, =22
    b doit
.global setuid
setuid: ldr r7, =23
    b doit
.global getuid
getuid: ldr r7, =24
    b doit
.global stime
stime: ldr r7, =25
    b doit
.global ptrace
ptrace: ldr r7, =26
    b doit
.global alarm
alarm: ldr r7, =27
    b doit

.global pause
pause: ldr r7, =29
    b doit
.global utime
utime: ldr r7, =30
    b doit

.global access
access: ldr r7, =33
    b doit
.global nice
nice: ldr r7, =34
    b doit

.global sync
sync: ldr r7, =36
    b doit
.global kill
kill: ldr r7, =37
    b doit
.global rename
rename: ldr r7, =38
    b doit
.global mkdir
mkdir: ldr r7, =39
    b doit
.global rmdir
rmdir: ldr r7, =40
    b doit
.global dup
dup: ldr r7, =41
    b doit
.global pipe
pipe: ldr r7, =42
    b doit
.global times
times: ldr r7, =43
    b doit

.global _brk
_brk:
.global brk
brk: ldr r7, =45
    b doit
.global setgid
setgid: ldr r7, =46
    b doit
.global getgid
getgid: ldr r7, =47
    b doit

.global geteuid
geteuid: ldr r7, =49
    b doit
.global getegid
getegid: ldr r7, =50
    b doit
.global acct
acct: ldr r7, =51
    b doit
.global umount2
umount2: ldr r7, =52
    b doit

.global ioctl
ioctl: ldr r7, =54
    b doit
.global fcntl
fcntl: ldr r7, =55
    b doit

.global setpgid
setpgid: ldr r7, =57
    b doit

.global umask
umask: ldr r7, =60
    b doit
.global chroot
chroot: ldr r7, =61
    b doit
.global ustat
ustat: ldr r7, =62
    b doit
.global dup2
dup2: ldr r7, =63
    b doit
.global getppid
getppid: ldr r7, =64
    b doit
.global getpgrp
getpgrp: ldr r7, =65
    b doit
.global setsid
setsid: ldr r7, =66
    b doit
.global sigaction
sigaction: ldr r7, =67
    b doit

.global setreuid
setreuid: ldr r7, =70
    b doit
.global setregid
setregid: ldr r7, =71
    b doit
.global sigsuspend
sigsuspend: ldr r7, =72
    b doit
.global sigpending
sigpending: ldr r7, =73
    b doit
.global sethostname
sethostname: ldr r7, =74
    b doit
.global setrlimit
setrlimit: ldr r7, =75
    b doit
.global getrlimit
getrlimit: ldr r7, =76
    b doit
.global getrusage
getrusage: ldr r7, =77
    b doit
.global gettimeofday
gettimeofday: ldr r7, =78
    b doit
.global settimeofday
settimeofday: ldr r7, =79
    b doit
.global getgroups
getgroups: ldr r7, =80
    b doit
.global setgroups
setgroups: ldr r7, =81
    b doit
.global select
select: ldr r7, =82
    b doit
.global symlink
symlink: ldr r7, =83
    b doit

.global readlink
readlink: ldr r7, =85
    b doit
.global uselib
uselib: ldr r7, =86
    b doit
.global swapon
swapon: ldr r7, =87
    b doit
.global reboot
reboot: ldr r7, =88
    b doit
.global readdir
readdir: ldr r7, =89
    b doit
.global mmap
mmap: ldr r7, =90
    b doit
.global munmap
munmap: ldr r7, =91
    b doit
.global truncate
truncate: ldr r7, =92
    b doit
.global ftruncate
ftruncate: ldr r7, =93
    b doit
.global fchmod
fchmod: ldr r7, =94
    b doit
.global fchown
fchown: ldr r7, =95
    b doit
.global getpriority
getpriority: ldr r7, =96
    b doit
.global setpriority
setpriority: ldr r7, =97
    b doit

.global statfs
statfs: ldr r7, =99
    b doit
.global fstatfs
fstatfs: ldr r7, =100
    b doit

.global socketcall
socketcall: ldr r7, =102
    b doit
.global syslog
syslog: ldr r7, =103
    b doit
.global setitimer
setitimer: ldr r7, =104
    b doit
.global getitimer
getitimer: ldr r7, =105
    b doit
.global stat
stat: ldr r7, =106
    b doit
.global lstat
lstat: ldr r7, =107
    b doit
.global fstat
fstat: ldr r7, =108
    b doit

.global vhangup
vhangup: ldr r7, =111
    b doit

.global syscall
syscall: ldr r7, =113
    b doit
.global wait4
wait4: ldr r7, =114
    b doit
.global swapoff
swapoff: ldr r7, =115
    b doit
.global sysinfo
sysinfo: ldr r7, =116
    b doit
.global ipc
ipc: ldr r7, =117
    b doit
.global fsync
fsync: ldr r7, =118
    b doit
.global sigreturn
sigreturn: ldr r7, =119
    b doit
.global clone
clone: ldr r7, =120
    b doit
.global setdomainname
setdomainname: ldr r7, =121
    b doit
.global uname
uname: ldr r7, =122
    b doit

.global adjtimex
adjtimex: ldr r7, =124
    b doit
.global mprotect
mprotect: ldr r7, =125
    b doit
.global sigprocmask
sigprocmask: ldr r7, =126
    b doit

.global init_module
init_module: ldr r7, =128
    b doit
.global delete_module
delete_module: ldr r7, =129
    b doit

.global quotactl
quotactl: ldr r7, =131
    b doit
.global getpgid
getpgid: ldr r7, =132
    b doit
.global fchdir
fchdir: ldr r7, =133
    b doit
.global bdflush
bdflush: ldr r7, =134
    b doit
.global sysfs
sysfs: ldr r7, =135
    b doit
.global personality
personality: ldr r7, =136
    b doit

.global setfsuid
setfsuid: ldr r7, =138
    b doit
.global setfsgid
setfsgid: ldr r7, =139
    b doit
.global _llseek
_llseek: ldr r7, =140
    b doit
.global getdents
getdents: ldr r7, =141
    b doit
.global _newselect
_newselect: ldr r7, =142
    b doit
.global flock
flock: ldr r7, =143
    b doit
.global msync
msync: ldr r7, =144
    b doit
.global readv
readv: ldr r7, =145
    b doit
.global writev
writev: ldr r7, =146
    b doit
.global getsid
getsid: ldr r7, =147
    b doit
.global fdatasync
fdatasync: ldr r7, =148
    b doit
.global _sysctl
_sysctl: ldr r7, =149
    b doit
.global mlock
mlock: ldr r7, =150
    b doit
.global munlock
munlock: ldr r7, =151
    b doit
.global mlockall
mlockall: ldr r7, =152
    b doit
.global munlockall
munlockall: ldr r7, =153
    b doit
.global sched_setparam
sched_setparam: ldr r7, =154
    b doit
.global sched_getparam
sched_getparam: ldr r7, =155
    b doit
.global sched_setscheduler
sched_setscheduler: ldr r7, =156
    b doit
.global sched_getscheduler
sched_getscheduler: ldr r7, =157
    b doit
.global sched_yield
sched_yield: ldr r7, =158
    b doit
.global sched_get_priority_max
sched_get_priority_max: ldr r7, =159
    b doit
.global sched_get_priority_min
sched_get_priority_min: ldr r7, =160
    b doit
.global sched_rr_get_interval
sched_rr_get_interval: ldr r7, =161
    b doit
.global nanosleep
nanosleep: ldr r7, =162
    b doit
.global mremap
mremap: ldr r7, =163
    b doit
.global setresuid
setresuid: ldr r7, =164
    b doit
.global getresuid
getresuid: ldr r7, =165
    b doit

.global poll
poll: ldr r7, =168
    b doit
.global nfsservctl
nfsservctl: ldr r7, =169
    b doit
.global setresgid
setresgid: ldr r7, =170
    b doit
.global getresgid
getresgid: ldr r7, =171
    b doit
.global prctl
prctl: ldr r7, =172
    b doit
.global rt_sigreturn
rt_sigreturn: ldr r7, =173
    b doit
.global rt_sigaction
rt_sigaction: ldr r7, =174
    b doit
.global rt_sigprocmask
rt_sigprocmask: ldr r7, =175
    b doit
.global rt_sigpending
rt_sigpending: ldr r7, =176
    b doit
.global rt_sigtimedwait
rt_sigtimedwait: ldr r7, =177
    b doit
.global rt_sigqueueinfo
rt_sigqueueinfo: ldr r7, =178
    b doit
.global rt_sigsuspend
rt_sigsuspend: ldr r7, =179
    b doit
.global pread64
pread64: ldr r7, =180
    b doit
.global pwrite64
pwrite64: ldr r7, =181
    b doit
.global chown
chown: ldr r7, =182
    b doit
.global getcwd
getcwd: ldr r7, =183
    b doit
.global capget
capget: ldr r7, =184
    b doit
.global capset
capset: ldr r7, =185
    b doit
.global sigaltstack
sigaltstack: ldr r7, =186
    b doit
.global sendfile
sendfile: ldr r7, =187
    b doit

.global vfork
vfork: ldr r7, =190
    b doit
.global ugetrlimit
ugetrlimit: ldr r7, =191
    b doit
.global mmap2
mmap2: ldr r7, =192
    b doit
.global truncate64
truncate64: ldr r7, =193
    b doit
.global ftruncate64
ftruncate64: ldr r7, =194
    b doit
.global stat64
stat64: ldr r7, =195
    b doit
.global lstat64
lstat64: ldr r7, =196
    b doit
.global fstat64
fstat64: ldr r7, =197
    b doit
.global lchown32
lchown32: ldr r7, =198
    b doit
.global getuid32
getuid32: ldr r7, =199
    b doit
.global getgid32
getgid32: ldr r7, =200
    b doit
.global geteuid32
geteuid32: ldr r7, =201
    b doit
.global getegid32
getegid32: ldr r7, =202
    b doit
.global setreuid32
setreuid32: ldr r7, =203
    b doit
.global setregid32
setregid32: ldr r7, =204
    b doit
.global getgroups32
getgroups32: ldr r7, =205
    b doit
.global setgroups32
setgroups32: ldr r7, =206
    b doit
.global fchown32
fchown32: ldr r7, =207
    b doit
.global setresuid32
setresuid32: ldr r7, =208
    b doit
.global getresuid32
getresuid32: ldr r7, =209
    b doit
.global setresgid32
setresgid32: ldr r7, =210
    b doit
.global getresgid32
getresgid32: ldr r7, =211
    b doit
.global chown32
chown32: ldr r7, =212
    b doit
.global setuid32
setuid32: ldr r7, =213
    b doit
.global setgid32
setgid32: ldr r7, =214
    b doit
.global setfsuid32
setfsuid32: ldr r7, =215
    b doit
.global setfsgid32
setfsgid32: ldr r7, =216
    b doit
.global getdents64
getdents64: ldr r7, =217
    b doit
.global pivot_root
pivot_root: ldr r7, =218
    b doit
.global mincore
mincore: ldr r7, =219
    b doit
.global madvise
madvise: ldr r7, =220
    b doit
.global fcntl64
fcntl64: ldr r7, =221
    b doit

.global gettid
gettid: ldr r7, =224
    b doit
.global readahead
readahead: ldr r7, =225
    b doit
.global setxattr
setxattr: ldr r7, =226
    b doit
.global lsetxattr
lsetxattr: ldr r7, =227
    b doit
.global fsetxattr
fsetxattr: ldr r7, =228
    b doit
.global getxattr
getxattr: ldr r7, =229
    b doit
.global lgetxattr
lgetxattr: ldr r7, =230
    b doit
.global fgetxattr
fgetxattr: ldr r7, =231
    b doit
.global listxattr
listxattr: ldr r7, =232
    b doit
.global llistxattr
llistxattr: ldr r7, =233
    b doit
.global flistxattr
flistxattr: ldr r7, =234
    b doit
.global removexattr
removexattr: ldr r7, =235
    b doit
.global lremovexattr
lremovexattr: ldr r7, =236
    b doit
.global fremovexattr
fremovexattr: ldr r7, =237
    b doit
.global tkill
tkill: ldr r7, =238
    b doit
.global sendfile64
sendfile64: ldr r7, =239
    b doit
.global futex
futex: ldr r7, =240
    b doit
.global sched_setaffinity
sched_setaffinity: ldr r7, =241
    b doit
.global sched_getaffinity
sched_getaffinity: ldr r7, =242
    b doit
.global io_setup
io_setup: ldr r7, =243
    b doit
.global io_destroy
io_destroy: ldr r7, =244
    b doit
.global io_getevents
io_getevents: ldr r7, =245
    b doit
.global io_submit
io_submit: ldr r7, =246
    b doit
.global io_cancel
io_cancel: ldr r7, =247
    b doit
.global exit_group
exit_group: ldr r7, =248
    b doit
.global lookup_dcookie
lookup_dcookie: ldr r7, =249
    b doit
.global epoll_create
epoll_create: ldr r7, =250
    b doit
.global epoll_ctl
epoll_ctl: ldr r7, =251
    b doit
.global epoll_wait
epoll_wait: ldr r7, =252
    b doit
.global remap_file_pages
remap_file_pages: ldr r7, =253
    b doit

.global set_tid_address
set_tid_address: ldr r7, =256
    b doit
.global timer_create
timer_create: ldr r7, =257
    b doit
.global timer_settime
timer_settime: ldr r7, =258
    b doit
.global timer_gettime
timer_gettime: ldr r7, =259
    b doit
.global timer_getoverrun
timer_getoverrun: ldr r7, =260
    b doit
.global timer_delete
timer_delete: ldr r7, =261
    b doit
.global clock_settime
clock_settime: ldr r7, =262
    b doit
.global clock_gettime
clock_gettime: ldr r7, =263
    b doit
.global clock_getres
clock_getres: ldr r7, =264
    b doit
.global clock_nanosleep
clock_nanosleep: ldr r7, =265
    b doit
.global statfs64
statfs64: ldr r7, =266
    b doit
.global fstatfs64
fstatfs64: ldr r7, =267
    b doit
.global tgkill
tgkill: ldr r7, =268
    b doit
.global utimes
utimes: ldr r7, =269
    b doit
.global arm_fadvise64_64
arm_fadvise64_64: ldr r7, =270
    b doit
.global pciconfig_iobase
pciconfig_iobase: ldr r7, =271
    b doit
.global pciconfig_read
pciconfig_read: ldr r7, =272
    b doit
.global pciconfig_write
pciconfig_write: ldr r7, =273
    b doit
.global mq_open
mq_open: ldr r7, =274
    b doit
.global mq_unlink
mq_unlink: ldr r7, =275
    b doit
.global mq_timedsend
mq_timedsend: ldr r7, =276
    b doit
.global mq_timedreceive
mq_timedreceive: ldr r7, =277
    b doit
.global mq_notify
mq_notify: ldr r7, =278
    b doit
.global mq_getsetattr
mq_getsetattr: ldr r7, =279
    b doit
.global waitid
waitid: ldr r7, =280
    b doit
.global socket
socket: ldr r7, =281
    b doit
.global bind
bind: ldr r7, =282
    b doit
.global connect
connect: ldr r7, =283
    b doit
.global listen
listen: ldr r7, =284
    b doit
.global accept
accept: ldr r7, =285
    b doit
.global getsockname
getsockname: ldr r7, =286
    b doit
.global getpeername
getpeername: ldr r7, =287
    b doit
.global socketpair
socketpair: ldr r7, =288
    b doit
.global send
send: ldr r7, =289
    b doit
.global sendto
sendto: ldr r7, =290
    b doit
.global recv
recv: ldr r7, =291
    b doit
.global recvfrom
recvfrom: ldr r7, =292
    b doit
.global shutdown
shutdown: ldr r7, =293
    b doit
.global setsockopt
setsockopt: ldr r7, =294
    b doit
.global getsockopt
getsockopt: ldr r7, =295
    b doit
.global sendmsg
sendmsg: ldr r7, =296
    b doit
.global recvmsg
recvmsg: ldr r7, =297
    b doit
.global semop
semop: ldr r7, =298
    b doit
.global semget
semget: ldr r7, =299
    b doit
.global semctl
semctl: ldr r7, =300
    b doit
.global msgsnd
msgsnd: ldr r7, =301
    b doit
.global msgrcv
msgrcv: ldr r7, =302
    b doit
.global msgget
msgget: ldr r7, =303
    b doit
.global msgctl
msgctl: ldr r7, =304
    b doit
.global shmat
shmat: ldr r7, =305
    b doit
.global shmdt
shmdt: ldr r7, =306
    b doit
.global shmget
shmget: ldr r7, =307
    b doit
.global shmctl
shmctl: ldr r7, =308
    b doit
.global add_key
add_key: ldr r7, =309
    b doit
.global request_key
request_key: ldr r7, =310
    b doit
.global keyctl
keyctl: ldr r7, =311
    b doit
.global semtimedop
semtimedop: ldr r7, =312
    b doit
.global vserver
vserver: ldr r7, =313
    b doit
.global ioprio_set
ioprio_set: ldr r7, =314
    b doit
.global ioprio_get
ioprio_get: ldr r7, =315
    b doit
.global inotify_init
inotify_init: ldr r7, =316
    b doit
.global inotify_add_watch
inotify_add_watch: ldr r7, =317
    b doit
.global inotify_rm_watch
inotify_rm_watch: ldr r7, =318
    b doit
.global mbind
mbind: ldr r7, =319
    b doit
.global get_mempolicy
get_mempolicy: ldr r7, =320
    b doit
.global set_mempolicy
set_mempolicy: ldr r7, =321
    b doit

#define __ARM_NR_BASE (__NR_SYSCALL_BASE+0x0f0000)
.global breakpoint
breakpoint: ldr r7, =0x0f0001
    b doit
.global cacheflush
cacheflush: ldr r7, =0x0f0002
    b doit
.global usr26
usr26: ldr r7, =0x0f0003
    b doit
.global usr32
usr32: ldr r7, =0x0f0004
    b doit
.global set_tls
set_tls: ldr r7, =0x0f0005
    b doit
