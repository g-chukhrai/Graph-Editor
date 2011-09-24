HEADERS += vertex.h \
    edge.h \
    graphscene.h \
    mainwindow.h \
    graph.h \
    subwindow.h \
    cmultprocessor.h \
    dialog.h \
    viewer.h
SOURCES += vertex.cpp \
    edge.cpp \
    graphscene.cpp \
    mainwindow.cpp \
    main.cpp \
    graph.cpp \
    subwindow.cpp \
    cmultprocessor.cpp \
    dialog.cpp \
    viewer.cpp
RESOURCES += res.qrc
RC_FILE = icon.rc
QMAKE_CFLAGS_RELEASE += -O0
QMAKE_CXXFLAGS_RELEASE += -O0
QMAKE_OBJECTIVE_CFLAGS_RELEASE += -O0
FORMS += dialog.ui
