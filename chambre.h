#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class chambre
{
private:
    int NUM,CAPACITE;
    QString TypeChambre,EtatChambre;
public:
    chambre();
    chambre(int,QString,QString,int);
    bool ajouterCH();
    QSqlQuery ChambreVide(QString type);
     QSqlQuery afficherChambre();
     bool supprimerChambre(QString num);
     QSqlQuery selectionnerChambre(QString val);
     QSqlQuery TriCapacite();
     bool update(QString type,QString etat,QString capacite,QString num);
     QSqlQuery rechercheChambre(QString val,QString type);
     void ReserverChambre(int num);
};

#endif // CHAMBRE_H
