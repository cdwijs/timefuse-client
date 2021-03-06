QT = core gui widgets network testlib
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
           account_settings.cpp \
           manage_groups.cpp \
           create_group_event.cpp \
           friends_list.cpp \
           edit_group.cpp \
           friend_requests.cpp \
           suggested_time.cpp \
           group_event_thread.cpp \
           user_event_thread.cpp \
           friends_thread.cpp \
           suggest_user_event.cpp \
           refresh_thread.cpp

HEADERS += user.hpp \
           create_account_window.hpp \
           reset_password_window.hpp \
           LoginWindow.hpp \
           tcp_connection.hpp \
           encrypt_string.hpp \
           home_screen.hpp \
           schedulinggrid.hpp \
           add_group.h \
           createevent.hpp \
           account_settings.hpp \
           manage_groups.hpp \
           create_group_event.hpp \
           friends_list.hpp \
           edit_group.hpp \
           friend_requests.hpp \
           suggested_time.hpp \
           group_event_thread.hpp \
           user_event_thread.hpp \
           friends_thread.hpp \
           suggest_user_event.hpp \
           refresh_thread.hpp

FORMS += create_account_window.ui \
         reset_password_window.ui \
         home_screen.ui \
         schedulinggrid.ui \
         add_group.ui \
         createevent.ui \
         account_settings.ui \
         manage_groups.ui \
         create_group_event.ui \
         edit_group.ui \
         friends_list.ui \
         friend_requests.ui \
         suggested_time.ui \
         suggest_user_event.ui
