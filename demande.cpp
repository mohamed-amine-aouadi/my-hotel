#include "demande.h"

demande::demande()
{
    TYPE_DEMANDE="";
    DATEDEBUT="";
    QUANTITE_DEMANDE=0;
    REF_DEMANDE=0;
    CIN=0;
    ETAT=0;
}

demande::demande(int QUANTITE_DEMANDE,QString TYPE_DEMANDE,int CIN,int ETAT,QString DATEDEBUT)
{
   this->CIN=CIN;
    this->ETAT=ETAT;
    this->DATEDEBUT=DATEDEBUT;
    //this->REF_DEMANDE=REF_DEMANDE;
    this->TYPE_DEMANDE=TYPE_DEMANDE;
    this->QUANTITE_DEMANDE=QUANTITE_DEMANDE;
}
int demande::get_cin(){return CIN;}
int demande::get_etat(){return ETAT;}
int demande::get_ref(){return REF_DEMANDE;}
int demande::get_quantite(){return QUANTITE_DEMANDE;}
QString demande::get_type(){return TYPE_DEMANDE;}
QString demande::get_date(){return DATEDEBUT;}

bool demande::ajouter_demande()
{
    QSqlQuery query;
    QString res=QString::number(CIN);
    query.prepare("INSERT INTO DEMANDE (QUANTITE_DEMANDE, TYPE_DEMANDE, CIN, ETAT, DATEDEBUT) VALUES (:QUANTITE_DEMANDE, :TYPE_DEMANDE, :CIN, :ETAT, :DATEDEBUT)");
    query.bindValue(":QUANTITE_DEMANDE",QUANTITE_DEMANDE);
    query.bindValue(":TYPE_DEMANDE",TYPE_DEMANDE);
    query.bindValue(":CIN",res);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":DATEDEBUT",DATEDEBUT);
    return  query.exec();
}
QSqlQueryModel * demande::afficher_demande()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DEMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_DEMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_DEMANDE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_DEMANDE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEDEBUT"));

    return model;

}
bool demande::supprimer_demande(int REF)
{
    QSqlQuery query;
    QString res= QString::number(REF);
    query.prepare("delete from demande where REF_DEMANDE = :REF");
    query.bindValue(":REF",res);
    return query.exec();
}
QSqlQuery demande::selectionner(QString val)
{
    QSqlQuery qry;
    qry.prepare("select * from demande where REF_DEMANDE=:val ");
    qry.bindValue(":val",val);
    return qry;
}
bool demande::modifier(int cin,int ref,int quantite,QString type,int etat,QString date)
{
    QSqlQuery qry;
    qry.prepare("update demande set QUANTITE_DEMANDE=:Quantite,TYPE_DEMANDE=:Type,ETAT=:Etat,DATEDEBUT=:Date where REF_DEMANDE=:ref ");
    qry.bindValue(":cin",cin);
     qry.bindValue(":ref",ref);
    qry.bindValue(":Quantite",quantite);
    qry.bindValue(":Type",type);
    qry.bindValue(":Etat",etat);
    qry.bindValue(":Date",date);
     return qry.exec();
}
QSqlQuery demande::recherche(QString type, QString val)
{
    QSqlQuery request;
   val="%"+val+"%";
   if (type=="TYPE"){
       request.prepare("SELECT * FROM demande WHERE TYPE_DEMANDE LIKE:val ");
   }else if (type=="ETAT"){
       request.prepare("SELECT * FROM demande WHERE ETAT LIKE:val");
   }else if (type=="CIN"){
       request.prepare("SELECT * FROM demande WHERE CIN LIKE:val");
   }else if (type=="DATE"){
       request.prepare("SELECT * FROM demande WHERE DATEDEBUT LIKE:val");
   }
   request.bindValue(":val",val);
   return request;
}
bool demande::updateDemande(int ref){
       QSqlQuery update;
       update.prepare("update DEMANDE set ETAT=1 where REF_DEMANDE=:ref");
     update.bindValue(":ref",ref);
    return update.exec();
    }
