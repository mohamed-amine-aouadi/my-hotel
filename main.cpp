#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login L;
    Connexion c;
    bool test=c.ouvrirconnexion();
    L.show();
    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



    return a.exec();
}
