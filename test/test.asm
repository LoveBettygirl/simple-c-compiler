.586
.model flat, stdcall
option casemap :none

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\msvcrt.lib
includelib \masm32\lib\masm32.lib

include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\gdi32.inc
include \masm32\include\windows.inc
include \masm32\include\msvcrt.inc
include \masm32\include\masm32.inc
include \masm32\macros\macros.asm


.data
	_a DWORD 0
	_b DWORD 0
	_c DWORD 0
	_D BYTE 0
	t0 DWORD 0
	t1 DWORD 0
	t2 DWORD 0
	t3 DWORD 0
	t4 DWORD 0
	t5 DWORD 0
	t6 DWORD 0
	szInputInt BYTE "%d",0
	szOutputInt BYTE "%d",13,10,0
	szInputChar BYTE "%c",0
	szOutputChar BYTE "%c",13,10,0


.code

_start:
	mov eax, 5
	mov _a, eax
	mov eax, 7
	mov _c, eax
	invoke crt_scanf,offset szInputInt,addr _b
	invoke crt_getchar
	invoke crt_scanf,offset szInputChar,addr _D
	invoke crt_getchar
	invoke crt_printf,offset szOutputChar,_D
	mov al, 80
	mov _D, al
	invoke crt_printf,offset szOutputChar,_D
L0:
	mov eax, _a
	add eax, 3
	mov t0, eax
	mov eax, _b
	add eax, 1
	mov t1, eax
	mov eax, t1
	add eax, 2
	mov t1, eax
	mov eax, t0
	cmp eax, t1
	jl L4
	jmp L3
L4:
	mov eax, _a
	cmp eax, _b
	je L3
	jmp L1
L3:
	mov eax, 1
	cmp eax, 1
	jne L1
	jmp L2
L1:
	mov eax, _a
	add eax, 1
	mov t2, eax
	mov eax, t2
	mov _a, eax
	jmp L0
L2:
	mov eax, _c
	add eax, 1
	mov t3, eax
	mov eax, t3
	mov _c, eax
L5:
	mov eax, _a
	cmp eax, _b
	jge L6
	jmp L7
L6:
	invoke crt_printf,offset szOutputInt,_b
	mov eax, _b
	add eax, 1
	mov t4, eax
	mov eax, t4
	mov _b, eax
	jmp L5
L7:
	invoke crt_printf,offset szOutputInt,_a
	invoke crt_printf,offset szOutputInt,_b
	mov eax, _a
	cmp eax, _c
	je L9
	jmp L8
L8:
	mov eax, 10
	mov _b, eax
	invoke crt_printf,offset szOutputInt,_c
	jmp L10
L9:
	mov eax, 100
	mov _a, eax
	invoke crt_printf,offset szOutputInt,_c
L10:
	mov eax, _c
	sub eax, 1
	mov t5, eax
	mov eax, t5
	mov _c, eax
	invoke crt_printf,offset szOutputInt,_a
	invoke crt_printf,offset szOutputInt,_b
	invoke crt_printf,offset szOutputInt,_c
	mov eax, _b
	imul eax, _c
	mov t6, eax
	mov eax, _a
	add eax, t6
	mov t6, eax
	invoke crt_printf,offset szOutputInt,t6
L11:
	mov eax, _a
	cmp eax, 0
	je L12
	jmp L13
L12:
	invoke crt_printf,offset szOutputChar,_D
	jmp L11
L13:
	invoke ExitProcess, 0
end _start
