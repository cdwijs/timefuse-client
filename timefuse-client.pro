QT = core gui widgets network
CONFIG += c++11 debug

TARGET = timefuse-client
TEMPLATE = app

SOURCES += main.cpp \
           user.cpp \
           create_account_window.cpp \
           reset_password_window.cpp \
           LoginWindow.cpp \
           tcp_connection.cpp \
           encrypt_string.cpp \
           home_screen.cpp \
           schedulinggrid.cpp \
           add_group.cpp \
           createevent.cpp \
           usercreatedevent.cpp

HEADERS += user.hpp \
           create_account_window.hpp \
           reset_password_window.hpp \
           LoginWindow.hpp \
           tcp_connection.hpp \
           encrypt_string.hpp \
           home_screen.hpp \
           schedulinggrid.h \
           add_group.h \
           createevent.h \
           usercreatedevent.h

FORMS += create_account_window.ui \
         reset_password_window.ui \
         home_screen.ui \
         schedulinggrid.ui \
         add_group.ui \
         createevent.ui
