;--- include file created by h2incx v0.99.11, copyright 2005 japheth
;--- source file: c:\programme\devstudio\vc6\include\CONIO.H, last modified: 6/15/1998 0:0

if _MSC_VER gt 1000
;#pragma once 
endif 
ifndef _INC_CONIO
_INC_CONIO	EQU	<>
if  0 eq defined(_WIN32) AND  0 eq defined(_MAC)
.err <ERROR : Only Mac or Win32 targets supported ! >
endif 
ifndef _MAC
ifdef __cplusplus
;extern "C"
;{
endif 
ifndef _CRTIMP
ifdef _DLL
_CRTIMP	EQU	<__declspec ( dllimport )>
else 
_CRTIMP	EQU	<>
endif 
endif 
if ( 0 eq defined(_MSC_VER) AND  0 eq defined(__cdecl))
__cdecl	EQU	<>
endif 
ifndef _CRTAPI1
if _MSC_VER ge 800 AND _M_IX86 ge 300
_CRTAPI1	EQU	<__cdecl>
else 
_CRTAPI1	EQU	<>
endif 
endif 
@DefProto _CRTIMP, _cgets, c, , <:ptr SBYTE>
@DefProto _CRTIMP, _cprintf, c, , <:ptr SBYTE, :VARARG>
@DefProto _CRTIMP, _cputs, c, , <:ptr SBYTE>
@DefProto _CRTIMP, _cscanf, c, , <:ptr SBYTE, :VARARG>
@DefProto _CRTIMP, _getch, c, , <>
@DefProto _CRTIMP, _getche, c, , <>
ifdef _M_IX86
_inp proto c :WORD
_inpw proto c :WORD
_inpd proto c :WORD
endif 
@DefProto _CRTIMP, _kbhit, c, , <>
ifdef _M_IX86
_outp proto c :WORD, :DWORD
_outpw proto c :WORD, :WORD
_outpd proto c :WORD, :DWORD
endif 
@DefProto _CRTIMP, _putch, c, , <:DWORD>
@DefProto _CRTIMP, _ungetch, c, , <:DWORD>
if  0 eq __STDC__
@DefProto _CRTIMP, cgets, c, , <:ptr SBYTE>
@DefProto _CRTIMP, cprintf, c, , <:ptr SBYTE, :VARARG>
@DefProto _CRTIMP, cputs, c, , <:ptr SBYTE>
@DefProto _CRTIMP, cscanf, c, , <:ptr SBYTE, :VARARG>
ifdef _M_IX86
inp proto c :WORD
inpw proto c :WORD
endif 
@DefProto _CRTIMP, getch, c, , <>
@DefProto _CRTIMP, getche, c, , <>
@DefProto _CRTIMP, kbhit, c, , <>
ifdef _M_IX86
outp proto c :WORD, :DWORD
outpw proto c :WORD, :WORD
endif 
@DefProto _CRTIMP, putch, c, , <:DWORD>
@DefProto _CRTIMP, ungetch, c, , <:DWORD>
endif 
ifdef __cplusplus
;}
endif 
endif 
endif 

;--- errors: 0
;--- end of file ---
