#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class PERSONNEL
{
public:
    PERSONNEL();
    PERSONNEL(int,QString,int,int,QString);
    int get_cin();
    QString get_grade();
    int get_presence();
    int get_salaire();
    QString get_date();
    bool ajouter();
    bool modifier(int,QString,int,int,QString);
    QSqlQueryModel * afficher();
    bool supprimer (int);
    QSqlQuery selectionner(QString);
    QSqlQuery recherche (QString,QString);
    QSqlQuery tri_presence();
    QSqlQuery tri_cin();
    int Salaire(int cin);
    bool updateSalaire(int Salaire,int cin);
private:
    QString grade,date;
    int presence,salaire;
    int cin;


};

#endif // PERSONNEL_H
