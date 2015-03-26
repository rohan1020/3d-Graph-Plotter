#############################################################################
# Makefile for building: 2dpaint.app/Contents/MacOS/2dpaint
# Generated by qmake (2.01a) (Qt 4.8.6) on: Tue Mar 24 15:11:10 2015
# Project:  2dpaint.pro
# Template: app
# Command: /usr/local/bin/qmake -spec /usr/local/Cellar/qt/4.8.6/mkspecs/macx-xcode -o 2dpaint.xcodeproj/project.pbxproj 2dpaint.pro
#############################################################################

MOC       = /usr/local/Cellar/qt/4.8.6/bin/moc
UIC       = /usr/local/Cellar/qt/4.8.6/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
INCPATH       = -I/usr/local/Cellar/qt/4.8.6/mkspecs/macx-xcode -I. -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/include -I. -I. -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers -F/usr/local/Cellar/qt/4.8.6/lib
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compilers: ./moc_CanvasState.cpp ./moc_FunctionInputWindow.cpp ./moc_widget.cpp\
	 ./moc_window.cpp ./ui_FunctionInputWindow.h
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_CanvasState.cpp moc_FunctionInputWindow.cpp moc_widget.cpp moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CanvasState.cpp moc_FunctionInputWindow.cpp moc_widget.cpp moc_window.cpp
moc_CanvasState.cpp: CanvasStateData.h \
		Line.h \
		Point.h \
		CanvasText.h \
		CanvasState.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ CanvasState.h -o moc_CanvasState.cpp

moc_FunctionInputWindow.cpp: FunctionInputWindow.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ FunctionInputWindow.h -o moc_FunctionInputWindow.cpp

moc_widget.cpp: widget.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ widget.h -o moc_widget.cpp

moc_window.cpp: CanvasState.h \
		CanvasStateData.h \
		Line.h \
		Point.h \
		CanvasText.h \
		MainCanvas.h \
		CanvasDataGenerator.h \
		MathFunction.h \
		Range.h \
		window.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ window.h -o moc_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_FunctionInputWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_FunctionInputWindow.h
ui_FunctionInputWindow.h: FunctionInputWindow.ui
	/usr/local/Cellar/qt/4.8.6/bin/uic FunctionInputWindow.ui -o ui_FunctionInputWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

