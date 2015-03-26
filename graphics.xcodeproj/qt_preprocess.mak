#############################################################################
# Makefile for building: ../../../bin/graphics.app/Contents/MacOS/graphics
# Generated by qmake (2.01a) (Qt 4.8.6) on: Thu Mar 26 21:10:48 2015
# Project:  graphics.pro
# Template: app
# Command: /usr/local/bin/qmake -spec /usr/local/Cellar/qt/4.8.6/mkspecs/macx-xcode -o graphics.xcodeproj/project.pbxproj graphics.pro
#############################################################################

MOC       = /usr/local/Cellar/qt/4.8.6/bin/moc
UIC       = /usr/local/Cellar/qt/4.8.6/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
INCPATH       = -I/usr/local/Cellar/qt/4.8.6/mkspecs/macx-xcode -I. -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtNetwork.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtNetwork.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtOpenGL.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtOpenGL.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/include -I. -Iincludes -Iincludes/expparser -I/usr/local/Cellar/qt/4.8.6/lib/Qt3D.framework/Versions/1/Headers -I/usr/local/Cellar/qt/4.8.6/include/Qt3D -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -I. -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers -F/usr/local/Cellar/qt/4.8.6/lib
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

compilers: ./moc_GLView.cpp ./moc_CanvasState.cpp ./moc_FunctionInputWindow.cpp\
	 ./moc_widget.cpp ./moc_window.cpp ./ui_FunctionInputWindow.h
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_GLView.cpp moc_CanvasState.cpp moc_FunctionInputWindow.cpp moc_widget.cpp moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_GLView.cpp moc_CanvasState.cpp moc_FunctionInputWindow.cpp moc_widget.cpp moc_window.cpp
moc_GLView.cpp: RCube.h \
		GLView.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ GLView.h -o moc_GLView.cpp

moc_CanvasState.cpp: includes/CanvasStateData.h \
		includes/Line.h \
		includes/Point.h \
		includes/CanvasText.h \
		includes/CanvasState.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ includes/CanvasState.h -o moc_CanvasState.cpp

moc_FunctionInputWindow.cpp: includes/window.h \
		includes/CanvasState.h \
		includes/CanvasStateData.h \
		includes/Line.h \
		includes/Point.h \
		includes/CanvasText.h \
		includes/MainCanvas.h \
		includes/CanvasDataGenerator.h \
		includes/MathFunction.h \
		includes/expparser/parser.h \
		includes/expparser/constants.h \
		includes/expparser/error.h \
		includes/expparser/functions.h \
		includes/expparser/variablelist.h \
		includes/Range.h \
		includes/FunctionInputWindow.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ includes/FunctionInputWindow.h -o moc_FunctionInputWindow.cpp

moc_widget.cpp: includes/widget.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ includes/widget.h -o moc_widget.cpp

moc_window.cpp: includes/CanvasState.h \
		includes/CanvasStateData.h \
		includes/Line.h \
		includes/Point.h \
		includes/CanvasText.h \
		includes/MainCanvas.h \
		includes/CanvasDataGenerator.h \
		includes/MathFunction.h \
		includes/expparser/parser.h \
		includes/expparser/constants.h \
		includes/expparser/error.h \
		includes/expparser/functions.h \
		includes/expparser/variablelist.h \
		includes/Range.h \
		includes/window.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ includes/window.h -o moc_window.cpp

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
ui_FunctionInputWindow.h: includes/FunctionInputWindow.ui
	/usr/local/Cellar/qt/4.8.6/bin/uic includes/FunctionInputWindow.ui -o ui_FunctionInputWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

