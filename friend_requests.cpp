// Copyright 2017 Hunter L. Allen, Anqi Wang
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "friend_requests.hpp"

friend_requests::friend_requests(QWidget * parent)
: QWidget(parent),
  m_p_ui(new Ui::friend_requests)
{
  QPalette qpalette(QColor(102, 219, 255, 255), QColor(204, 243, 255, 255));
  this->setPalette(qpalette);
  QFont font(QString("Courier"), 10.5, QFont::Thin, false);
  this->setFont(font);

  m_p_ui->setupUi(this);

  m_p_username = new QString("");
  m_p_password = new QString("");

  // connect buttons
  connect(m_p_ui->back_button, &QPushButton::released,
    this, &friend_requests::on_back_button);
  connect(m_p_ui->accept, &QPushButton::released,
    this, &friend_requests::on_add_friend);
  connect(m_p_ui->decline, &QPushButton::released,
    this, &friend_requests::on_delete_friend);
}

friend_requests::~friend_requests() {}

void friend_requests::on_add_friend()
{
  if (m_p_ui->list_friends->currentItem() == NULL) {return;}
  QString * request = new QString("ACCEPT_FRIEND ");

  (*request) += m_p_username; (*request) += ":::";
  (*request) += m_p_password; (*request) += ":::";
  (*request) += m_p_ui->list_friends->currentItem()->text();

  QString * response = setup_connection(request);

  std::cerr << "response: " << response->toStdString() << std::endl;

  if (response->contains("OK")) {
    m_p_ui->list_friends->clear();
    fill_fields();
  } else {
    QMessageBox::critical(this, tr("Error"), *response);
  }

  delete response; delete request;
}

void friend_requests::on_delete_friend()
{
  if (m_p_ui->list_friends->currentItem() == NULL) {return;}
  QString * request = new QString("DELETE_FRIEND ");

  (*request) += m_p_username; (*request) += ":::";
  (*request) += m_p_password; (*request) += ":::";
  (*request) += m_p_ui->list_friends->currentItem()->text();

  QString * response = setup_connection(request);

  std::cerr << "response: " << response->toStdString() << std::endl;

  if (response->contains("OK")) {
    m_p_ui->list_friends->clear();
    fill_fields();
  } else {
    QMessageBox::critical(this, tr("Error"), *response);
  }

  delete response; delete request;
}

void friend_requests::on_back_button()
{
  m_p_ui->list_friends->clear();
  Q_EMIT (return_to_friends());
}

void friend_requests::fill_fields()
{
  m_p_ui->list_friends->clear();
  QString * request = new QString("FRIEND_REQUESTS ");

  (*request) += m_p_username; (*request) += ":::";
  (*request) += m_p_password; (*request) += "\r\n\0";

  QString * response = setup_connection(request);

  if (!response->contains("ERROR")) {
    response->replace("\r\n", "");
    QStringList list = response->split('\n');

    for (int i = 0; i < list.size(); i++) {
      if (list.at(i).size() == 0) {continue;}
      m_p_ui->list_friends->addItem(list.at(i));
    }
  }
  delete response; delete request;
}
