#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}
notification::notification(QString titre,QString text)
{
  this->text=text;
    this->titre=titre;
}

void notification::afficher()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/1.1/2/projet C++/projet/myappico.ico"));
    notifyIcon->show();;
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}

