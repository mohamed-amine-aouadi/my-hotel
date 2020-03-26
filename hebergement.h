#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class hebergement
{
private:
    int CIN,NUM,NB_personnes,NumChambre;
    QString Nom,Prenom,DateARRIVEE,DateDEPART,TypeReservation,TypeChambre;

public:
    hebergement();
    hebergement(int,int,QString,QString,QString,QString,QString,QString);
    bool ajouterH();
};

#endif // HEBERGEMENT_H
