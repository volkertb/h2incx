
# nmake makefile, creates h2incx.exe (Win32)
# tools used:
# - JWasm or MASM 6.x
# - WinInc
# - MS link

name = h2incx

WIN=1
DOS=0
WININC=\wininc

!ifndef DEBUG
DEBUG=0
!endif

!if $(DEBUG)
OUTDIR=DEBUG
!else
OUTDIR=RELEASE
!endif

!if $(DEBUG)
#AOPTD=-Zi -D_DEBUG
AOPTD=-Zi -D_DEBUG -D_TRACE
LOPTD= debug
LINK= link.exe
!else
LOPTD=
AOPTD=
LINK= link.exe
!endif

!ifndef MASM
MASM=0
!endif

AOPT=-c -nologo -coff -Sg -Fl$(OUTDIR)\ -Fo$(OUTDIR)\ $(AOPTD) -D_ML -I$(WININC)\Include
!if $(MASM)
ASM = ml.exe $(AOPT)
!else
ASM = jwasm.exe $(AOPT)
!endif

OBJS = $(OUTDIR)\$(name).obj  $(OUTDIR)\CIncFile.obj $(OUTDIR)\CList.obj

LIBS=$(WININC)\Lib\kernel32.lib Lib\libc32s.lib Lib\except.lib
!if $(DOS)
LIBSD=dkrnl32s.lib imphlp.lib Lib\except.lib
!endif

!if $(WIN)
TARGETW=$(OUTDIR)\$(name).exe
!endif
!if $(DOS)
TARGETD=$(OUTDIR)\$(name)D.exe
!endif

.asm{$(OUTDIR)}.obj:
	@$(ASM) $<

ALL: $(OUTDIR) $(TARGETW) $(TARGETD)

$(OUTDIR):
	@mkdir $(OUTDIR)

$(OUTDIR)\$(name).exe: $(OBJS)
	@link /SUBSYSTEM:CONSOLE $(OBJS) /OUT:$(OUTDIR)\$(name).exe $(LIBS) /map:$*.map

$(OUTDIR)\$(name)D.exe: $(OBJS)
	@link /SUBSYSTEM:CONSOLE $(HXDIR)\Lib\InitW32.obj $(OBJS) /OUT:$(OUTDIR)\$(name)D.exe /libpath:$(HXDIR)\Lib $(LIBSD) /stub:$(HXDIR)\Bin\loadpex.bin /map:$*.map /fixed:no
	@$(HXDIR)\bin\patchPE $*.exe

clean:
	@del $(OUTDIR)\*.obj
	@del $(OUTDIR)\*.map
	@del $(OUTDIR)\*.lst
	@del $(OUTDIR)\*.exe
