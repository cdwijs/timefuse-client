#ifndef __USER_HPP__
#define __USER_HPP__
#include <QtNetwork>
#include <stdexcept>
#include <QObject>
#include <QtCore>

class user : public QObject
{
  Q_OBJECT

public:
  explicit user(QObject * _p_parent = NULL);
  explicit user(const QByteArray & b, QObject * _p_parent = NULL);
  virtual ~user();

  const QString & get_email() {return m_email;}
  const QString & get_cell() {return m_cell_phone;}
  const QString & get_username() {return m_username_hash;}
  const QString & get_password() {return m_password_hash;}
  const QString & get_user_id() {return m_user_id;}
  const QString & get_schedule_id() {return m_schedule_id;}

  void set_email(const QString & _email) {m_email = _email;}
  void set_cell(const QString & _cell) {m_cell_phone = _cell;}
  void set_username(const QString & _username_hash) {m_username_hash = _username_hash;}
  void set_password(const QString & _password_hash) {m_password_hash = _password_hash;}
  void set_user_id(const QString & _user_id) {m_user_id = _user_id;}
  void set_schedule_id(const QString & _schedule_id) {m_schedule_id = _schedule_id;}

  QByteArray to_byte_array();

private:
  QString m_email;
  QString m_username_hash;
  QString m_password_hash;
  QString m_cell_phone;
  QString m_user_id;
  QString m_schedule_id;
};
#endif
