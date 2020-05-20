#include "personnel.h"

PERSONNEL::PERSONNEL()
{
cin=0;
grade="";
presence=0;
salaire=0;
date="";
}
PERSONNEL::PERSONNEL(int cin,QString grade,int presence,int salaire,QString date)
{
  this->cin=cin;
    this->grade=grade;
    this->presence=presence;
    this->salaire=salaire;
    this->date=date;
}

int PERSONNEL::get_cin(){return cin;}
QString PERSONNEL::get_grade(){return grade;}
int PERSONNEL::get_presence(){return presence;}
int PERSONNEL::get_salaire(){return salaire;}
QString PERSONNEL::get_date(){return date;}

bool PERSONNEL::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("INSERT INTO PERSONNEL (CIN ,GRADE,PRESENCE,SALAIRE,DATECONTRAT) VALUES (:cin,:grade,:presence,:salaire,:date)");
    query.bindValue(":cin",res);
    query.bindValue(":grade",grade);
    query.bindValue(":presence",presence);
    query.bindValue(":salaire",salaire);
    query.bindValue(":date",date);
    return  query.exec();

}
QSqlQueryModel * PERSONNEL::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PERSONNEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("GRADE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRESENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATECONTRAT"));

    return model;

}
QSqlQuery PERSONNEL::tri_presence()
{
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by PRESENCE DESC");
        return request;

}
QSqlQuery PERSONNEL::tri_cin()
{
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by CIN DESC");
        return request;

}
bool PERSONNEL::modifier(int cin,QString grade,int presence,int salaire,QString date)
{
    QSqlQuery qry;
    qry.prepare("update PERSONNEL set GRADE=:Grade,PRESENCE=:Presence,SALAIRE=:Salaire,DATECONTRAT=:Date where CIN=:cin ");
    qry.bindValue(":cin",cin);
    qry.bindValue(":Grade",grade);
    qry.bindValue(":Presence",presence);
    qry.bindValue(":Salaire",salaire);
    qry.bindValue(":Date",date);
    return qry.exec();
}
bool PERSONNEL::supprimer(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("delete from PERSONNEL where CIN = :cin");
    query.bindValue(":cin",res);
    return query.exec();
}
QSqlQuery PERSONNEL::selectionner(QString val)
{
    QSqlQuery qry;
    qry.prepare("select * from PERSONNEL where CIN=:val or GRADE=:val or PRESENCE=:val or SALAIRE=:val or DATECONTRAT=:val");
    qry.bindValue(":val",val);
    return qry;
}
QSqlQuery PERSONNEL::recherche(QString type, QString val)
{
    QSqlQuery request;
   val="%"+val+"%";
   if (type=="CIN"){
       request.prepare("SELECT * FROM PERSONNEL WHERE CIN LIKE:val order by CIN");
   }else if (type=="GRADE"){
       request.prepare("SELECT * FROM PERSONNEL WHERE GRADE LIKE:val");
   }else if (type=="SALAIRE"){
       request.prepare("SELECT * FROM PERSONNEL WHERE SALAIRE LIKE:val");
   }else if (type=="DATE CONTRAT"){
       request.prepare("SELECT * FROM PERSONNEL WHERE DATECONTRAT LIKE:val");
   }
   request.bindValue(":val",val);
   return request;
}
int PERSONNEL::Salaire(int cin){
       QSqlQuery salaire;
       int Salaire;
       salaire.prepare("select SALAIRE from PERSONNEL where CIN=:cin");
       salaire.bindValue(":cin",cin);
       salaire.exec();
       if (salaire.exec()){
           while (salaire.next()){
               Salaire=salaire.value(0).toInt();
           }
       }
       return Salaire;
       }
bool PERSONNEL::updateSalaire(int Salaire,int cin){
    QSqlQuery update1;
    update1.prepare("update PERSONNEL set SALAIRE=:Salaire where CIN=:cin");
     update1.bindValue(":cin",cin);
     update1.bindValue(":Salaire",Salaire);
     return update1.exec();
     }
