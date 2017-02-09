[global _readr]
[section .text]
_readr:
push edi
push ebp
mov ebp,esp
sub esp,byte 96
push dword 80
lea edi,[ebp + (-80)]
push dword edi
call _readln
add esp,8
mov edi,eax
cmp edi,0
jne near L2
mov eax,0
jmp L1
L2:
lea edi,[ebp + (-80)]
push dword edi
call _atod
add esp,4
fstp qword [ebp + (-96)]
fld qword [ebp + (-96)]
fstp dword [ebp + (-84)]
mov edi,dword [ebp + (-84)]
mov dword [ebp + (-88)],edi
mov eax,dword [ebp + (-88)]
L1:
mov esp,ebp
pop ebp
pop edi
ret
[global _printr]
_printr:
push edi
push ebp
mov ebp,esp
%define P_i 12
sub esp,byte 84
mov edi,dword [ebp + (P_i)]
mov dword [ebp + (-4)],edi
lea edi,[ebp + (-84)]
push dword edi
push dword 7
fld dword [ebp + (-4)]
sub esp,8
fstp qword [esp]
call _dtoa
add esp,16
mov edi,eax
push dword edi
call _prints
add esp,4
L4:
mov esp,ebp
pop ebp
pop edi
ret
[global _readd]
_readd:
push edi
push ebp
mov ebp,esp
sub esp,byte 96
push dword 80
lea edi,[ebp + (-80)]
push dword edi
call _readln
add esp,8
mov edi,eax
cmp edi,0
jne near L6
fld qword [(L8)]
jmp L5
L6:
lea edi,[ebp + (-80)]
push dword edi
call _atod
add esp,4
fstp qword [ebp + (-96)]
fld qword [ebp + (-96)]
fstp qword [ebp + (-88)]
fld qword [ebp + (-88)]
L5:
mov esp,ebp
pop ebp
pop edi
ret
[global _printd]
_printd:
push edi
push ebp
mov ebp,esp
%define P_d 12
sub esp,byte 80
lea edi,[ebp + (-80)]
push dword edi
push dword 7
fld qword [ebp + (P_d)]
sub esp,8
fstp qword [esp]
call _dtoa
add esp,16
mov edi,eax
push dword edi
call _prints
add esp,4
L9:
mov esp,ebp
pop ebp
pop edi
ret
[global _atod]
_atod:
push esi
push edi
push ebp
mov ebp,esp
%define P_s 16
sub esp,byte 20
fld qword [(L8)]
fstp qword [ebp + (-8)]
mov dword [ebp + (-12)],0
mov dword [ebp + (-16)],0
mov dword [ebp + (-20)],1
jmp L12
L11:
inc dword [ebp + (P_s)]
L12:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,32
je near L11
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,45
jne near L17
mov dword [ebp + (-20)],-1
inc dword [ebp + (P_s)]
jmp L17
L16:
inc dword [ebp + (P_s)]
L17:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,48
je near L16
jmp L20
L19:
mov edi,dword [ebp + (P_s)]
lea esi,[edi + (1)]
mov dword [ebp + (P_s)],esi
fld qword [(L22)]
fmul qword [ebp + (-8)]
movsx edi,byte [edi]
sub edi,48
push edi
fild dword [esp]
add esp,4
faddp st1
fstp qword [ebp + (-8)]
L20:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,48
jl near L23
cmp edi,57
jle near L19
L23:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,46
jne near L24
inc dword [ebp + (P_s)]
jmp L27
L26:
mov edi,dword [ebp + (P_s)]
lea esi,[edi + (1)]
mov dword [ebp + (P_s)],esi
fld qword [(L22)]
fmul qword [ebp + (-8)]
movsx edi,byte [edi]
sub edi,48
push edi
fild dword [esp]
add esp,4
faddp st1
fstp qword [ebp + (-8)]
cmp dword [ebp + (-16)],0
jg near L29
dec dword [ebp + (-16)]
L29:
L27:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,48
jl near L31
cmp edi,57
jle near L26
L31:
L24:
mov edi,dword [ebp + (P_s)]
movsx edi,byte [edi]
cmp edi,69
je near L34
cmp edi,101
jne near L32
L34:
mov edi,dword [ebp + (P_s)]
lea edi,[edi + (1)]
push dword edi
call _atoi
add esp,4
mov dword [ebp + (-12)],eax
L32:
mov edi,dword [ebp + (-16)]
add dword [ebp + (-12)],edi
cmp dword [ebp + (-12)],0
jle near L41
jmp L38
L37:
fld qword [(L22)]
fmul qword [ebp + (-8)]
fstp qword [ebp + (-8)]
L38:
mov edi,dword [ebp + (-12)]
mov esi,edi
sub esi,1
mov dword [ebp + (-12)],esi
cmp edi,0
jg near L37
jmp L36
L40:
fld qword [ebp + (-8)]
fdiv qword [(L22)]
fstp qword [ebp + (-8)]
L41:
mov edi,dword [ebp + (-12)]
lea esi,[edi + (1)]
mov dword [ebp + (-12)],esi
cmp edi,0
jl near L40
L36:
cmp dword [ebp + (-20)],0
jge near L43
fld qword [ebp + (-8)]
fchs
fstp qword [ebp + (-8)]
L43:
fld qword [ebp + (-8)]
L10:
mov esp,ebp
pop ebp
pop edi
pop esi
ret
[section .bss]
resb ($-$$) & 0
L46:
resb 32
[global _dtoa]
[section .text]
_dtoa:
push ebx
push esi
push edi
push ebp
mov ebp,esp
%define P_d 20
%define P_ndig 28
%define P_s 32
sub esp,byte 24
mov dword [ebp + (-4)],0
mov edi,dword [ebp + (P_s)]
cmp edi,0
jne near L47
lea edi,[(L46)]
mov dword [ebp + (P_s)],edi
L47:
fld qword [(L8)]
fcomp qword [ebp + (P_d)]
fstsw ax
sahf
jne near L49
mov edi,dword [ebp + (P_s)]
mov byte [edi],48
mov edi,dword [ebp + (P_s)]
mov byte [edi + (1)],0
mov eax,dword [ebp + (P_s)]
jmp L45
L49:
fld qword [(L8)]
fcomp qword [ebp + (P_d)]
fstsw ax
sahf
jbe near L51
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],45
fld qword [ebp + (P_d)]
fchs
fstp qword [ebp + (P_d)]
L51:
fld qword [(L55)]
fcomp qword [ebp + (P_d)]
fstsw ax
sahf
ja near L53
fld qword [(L55)]
fstp qword [ebp + (-12)]
mov dword [ebp + (-20)],0
jmp L59
L56:
fld qword [(L22)]
fmul qword [ebp + (-12)]
fld qword [ebp + (P_d)]
fcompp
fstsw ax
sahf
jae near L60
jmp L54
L60:
L57:
fld qword [(L22)]
fmul qword [ebp + (-12)]
fstp qword [ebp + (-12)]
inc dword [ebp + (-20)]
L59:
fld qword [(L62)]
fcomp qword [ebp + (-12)]
fstsw ax
sahf
ja near L56
jmp L54
L53:
fld qword [(L67)]
fstp qword [ebp + (-12)]
mov dword [ebp + (-20)],-1
jmp L66
L63:
fld qword [ebp + (P_d)]
fcomp qword [ebp + (-12)]
fstsw ax
sahf
jb near L68
jmp L65
L68:
L64:
fld qword [ebp + (-12)]
fdiv qword [(L22)]
fstp qword [ebp + (-12)]
dec dword [ebp + (-20)]
L66:
fld qword [(L8)]
fcomp qword [ebp + (-12)]
fstsw ax
sahf
jb near L63
L65:
L54:
fld qword [ebp + (P_d)]
fdiv qword [ebp + (-12)]
fstp qword [ebp + (P_d)]
mov dword [ebp + (-16)],0
jmp L73
L70:
fld qword [ebp + (P_d)]
sub esp,byte 4
fistp dword [esp]
pop eax
mov dword [ebp + (-24)],eax
fild dword [ebp + (-24)]
fld qword [ebp + (P_d)]
fcompp
fstsw ax
sahf
jae near L74
dec dword [ebp + (-24)]
L74:
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov ebx,dword [ebp + (-24)]
lea ebx,[ebx + (48)]
mov byte [esi + edi],bl
cmp dword [ebp + (-16)],0
jne near L76
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],46
L76:
fld qword [(L22)]
fld qword [ebp + (P_d)]
fild dword [ebp + (-24)]
fsubp st1
fmulp st1
fstp qword [ebp + (P_d)]
L71:
inc dword [ebp + (-16)]
L73:
mov edi,dword [ebp + (P_ndig)]
cmp dword [ebp + (-16)],edi
jge near L78
fld qword [(L8)]
fcomp qword [ebp + (P_d)]
fstsw ax
sahf
jne near L70
L78:
fld qword [(L81)]
fcomp qword [ebp + (P_d)]
fstsw ax
sahf
ja near L90
jmp L83
L82:
dec dword [ebp + (-4)]
L83:
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
movsx edi,byte [esi + edi]
cmp edi,57
je near L82
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
movsx edi,byte [esi + edi]
cmp edi,46
je near L85
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
lea edi,[esi + edi]
movsx esi,byte [edi]
lea esi,[esi + (1)]
mov ebx,esi
mov byte [edi],bl
jmp L80
L85:
dec dword [ebp + (-4)]
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
movsx edi,byte [esi + edi]
cmp edi,57
je near L87
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
lea edi,[esi + edi]
movsx esi,byte [edi]
lea esi,[esi + (1)]
mov ebx,esi
mov byte [edi],bl
jmp L80
L87:
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],49
inc dword [ebp + (-20)]
jmp L80
L89:
dec dword [ebp + (-4)]
L90:
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
movsx edi,byte [esi + edi]
cmp edi,48
je near L89
L80:
mov edi,dword [ebp + (-4)]
sub edi,1
mov esi,dword [ebp + (P_s)]
movsx edi,byte [esi + edi]
cmp edi,46
jne near L92
dec dword [ebp + (-4)]
L92:
cmp dword [ebp + (-20)],0
je near L94
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],69
cmp dword [ebp + (-20)],0
jge near L96
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],45
neg dword [ebp + (-20)]
L96:
cmp dword [ebp + (-20)],100
jle near L98
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov eax,dword [ebp + (-20)]
mov ebx,100
cdq
idiv ebx
lea ebx,[eax + (48)]
mov byte [esi + edi],bl
mov eax,dword [ebp + (-20)]
mov edi,100
cdq
idiv edi
mov dword [ebp + (-20)],edx
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov eax,dword [ebp + (-20)]
mov ebx,10
cdq
idiv ebx
lea ebx,[eax + (48)]
mov byte [esi + edi],bl
mov eax,dword [ebp + (-20)]
mov edi,10
cdq
idiv edi
mov dword [ebp + (-20)],edx
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov ebx,dword [ebp + (-20)]
lea ebx,[ebx + (48)]
mov byte [esi + edi],bl
jmp L99
L98:
cmp dword [ebp + (-20)],10
jle near L100
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov eax,dword [ebp + (-20)]
mov ebx,10
cdq
idiv ebx
lea ebx,[eax + (48)]
mov byte [esi + edi],bl
mov eax,dword [ebp + (-20)]
mov edi,10
cdq
idiv edi
mov dword [ebp + (-20)],edx
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov ebx,dword [ebp + (-20)]
lea ebx,[ebx + (48)]
mov byte [esi + edi],bl
jmp L101
L100:
mov edi,dword [ebp + (-4)]
lea esi,[edi + (1)]
mov dword [ebp + (-4)],esi
mov esi,dword [ebp + (P_s)]
mov ebx,dword [ebp + (-20)]
lea ebx,[ebx + (48)]
mov byte [esi + edi],bl
L101:
L99:
L94:
mov edi,dword [ebp + (-4)]
mov esi,dword [ebp + (P_s)]
mov byte [esi + edi],0
mov eax,dword [ebp + (P_s)]
L45:
mov esp,ebp
pop ebp
pop edi
pop esi
pop ebx
ret
[global _atof]
_atof:
push edi
push ebp
mov ebp,esp
%define P_s 12
sub esp,byte 8
mov edi,dword [ebp + (P_s)]
push dword edi
call _atod
add esp,4
fstp qword [ebp + (-8)]
fld qword [ebp + (-8)]
sub esp,4
fstp dword [esp]
fld dword [esp]
add esp,4
L102:
mov esp,ebp
pop ebp
pop edi
ret
[global _ftoa]
_ftoa:
push edi
push ebp
mov ebp,esp
%define P_f 12
%define P_ndig 16
%define P_s 20
mov edi,dword [ebp + (P_s)]
push dword edi
mov edi,dword [ebp + (P_ndig)]
push dword edi
fld dword [ebp + (P_f)]
sub esp,8
fstp qword [esp]
call _dtoa
add esp,16
mov edi,eax
L103:
mov esp,ebp
pop ebp
pop edi
ret
[extern _prints]
[extern _readln]
[extern _atoi]
[section .data]
times ($-$$) & 3 db 0
L81:
dd 00H
dd 040140000H
times ($-$$) & 3 db 0
L67:
dd 09999999aH
dd 03fb99999H
times ($-$$) & 3 db 0
L62:
dd 0fffffffeH
dd 07fefffffH
times ($-$$) & 3 db 0
L55:
dd 00H
dd 03ff00000H
times ($-$$) & 3 db 0
L22:
dd 00H
dd 040240000H
times ($-$$) & 3 db 0
L8:
dd 00H
dd 00H
