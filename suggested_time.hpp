#ifndef SUGGESTED_TIME_HPP
#define SUGGESTED_TIME_HPP

#include <QMessageBox>
#include <QStringList>
#include <iostream>
#include <QWidget>
#include <QTest>
#include "ui_suggested_time.h"
#include "tcp_connection.hpp"

namespace Ui {
class suggested_time;
}

class suggested_time : public QWidget
{
    Q_OBJECT

public:
    explicit suggested_time(QWidget * _p_parent = NULL);
    virtual ~suggested_time();

	QString * m_p_username;
	QString * m_p_password;

	Q_SIGNAL void return_to_group_event();
    void fill_fields();
private:
    Ui::suggested_time * m_p_ui;
	
    Q_SLOT void on_selected_time();
    Q_SLOT void on_back_button();
};

#endif
