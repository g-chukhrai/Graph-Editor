#############################################################################
# Makefile for building: GraphEditor
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? 15. ??? 20:56:36 2010
# Project:  GraphEditor.pro
# Template: app
# Command: d:\downloads\qt\2010.02.1\qt\bin\qmake.exe -spec ..\Downloads\QT\2010.02.1\qt\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile GraphEditor.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = d:\downloads\qt\2010.02.1\qt\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: GraphEditor.pro  ../Downloads/QT/2010.02.1/qt/mkspecs/win32-g++/qmake.conf ../Downloads/QT/2010.02.1/qt/mkspecs/qconfig.pri \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/qt_functions.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/qt_config.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/exclusive_builds.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/default_pre.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/default_pre.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/release.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/debug_and_release.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/default_post.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/default_post.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/rtti.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/exceptions.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/stl.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/shared.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/warn_on.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/qt.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/thread.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/moc.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/win32/windows.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/resources.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/uic.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/yacc.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/lex.prf \
		../Downloads/QT/2010.02.1/qt/mkspecs/features/include_source_dir.prf \
		d:/Downloads/QT/2010.02.1/qt/lib/qtmain.prl
	$(QMAKE) -spec ..\Downloads\QT\2010.02.1\qt\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile GraphEditor.pro
..\Downloads\QT\2010.02.1\qt\mkspecs\qconfig.pri:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\qt_functions.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\qt_config.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\exclusive_builds.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\default_pre.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\default_pre.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\release.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\debug_and_release.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\default_post.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\default_post.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\rtti.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\exceptions.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\stl.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\shared.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\warn_on.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\qt.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\thread.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\moc.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\win32\windows.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\resources.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\uic.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\yacc.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\lex.prf:
..\Downloads\QT\2010.02.1\qt\mkspecs\features\include_source_dir.prf:
d:\Downloads\QT\2010.02.1\qt\lib\qtmain.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ..\Downloads\QT\2010.02.1\qt\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile GraphEditor.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
