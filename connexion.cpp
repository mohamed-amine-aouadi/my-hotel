#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirconnexion()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_Projet2A");
db.setUserName("firas");
db.setPassword("firas");
if (db.open())
test=true;
    return  test;
}

void Connexion::fermerconnexion(){
    db.close();
}


