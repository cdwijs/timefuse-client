#ifndef __CREATE_ACCOUNT_WINDOW_HPP__
#define __CREATE_ACCOUNT_WINDOW_HPP__
#include <QtWidgets>
#include <QtGui>

#include "ui_create_account_window.h"
#include "user.hpp"

class user;

namespace Ui {
    class create_account_window;
}

class create_account_window : public QWidget
{
   Q_OBJECT
public:
   explicit create_account_window (QWidget * _p_parent = NULL);
   virtual ~create_account_window();

   Q_SIGNAL void send_create_account(user * u);
private:
    Ui::create_account_window * m_p_ui;
};
#endif
