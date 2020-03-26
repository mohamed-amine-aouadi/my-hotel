#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirconnexion()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("aymen");
db.setPassword("aymen");
if (db.open())
test=true;
    return  test;
}

void Connexion::fermerconnexion(){
    db.close();
}


