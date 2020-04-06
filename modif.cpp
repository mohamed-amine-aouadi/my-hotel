#include "modif.h"
#include "ui_modif.h"
#include <QTabWidget>
#include "animation.h"
#include "equipement.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include"QDate"
#include <iostream>
#include "statistique.h"
#include "modif.h"
#include "mainwindow.h"


modif::modif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif)
{
    ui->setupUi(this);
   // ui->tabanim->setModel(tmpanim.afficher());
    ui->tabanime->setModel(tmpanime.afficherasc());
    ui->tabanime->setModel(tmpanime.afficherdesc());



    ui->lineEdit_idanim_2->setPlaceholderText("ID");
    ui->lineEdit_typeanim_2->setPlaceholderText("Lieu");
    ui->lineEdit_lieu_2->setPlaceholderText("Type");
    ui->lineEdit_duree_2->setPlaceholderText("DUREE EN MINUTE");
    ui->lineEdit_dateanim_2->setPlaceholderText("Date");
    ui->lineEdit_cin_2->setPlaceholderText("CIN");


    QPixmap pixel("C:/Users/ASUS/Desktop/youssefselmi/imagees/gym");
    int qq = ui->label_24->width();
    int ss = ui->label_24->height();
    ui->label_24->setPixmap(pixel.scaled(qq,ss,Qt::KeepAspectRatio));
}

modif::~modif()
{
    delete ui;
}



void modif::fonctionrechercher()
{
    QString id=ui->lineEdit_id_3->text();
    ui->tab_ab_rech_2->setModel(tmpanim.recherche(id));
}





void modif::on_Rechercher_2_clicked()
{
 fonctionrechercher();
}





void modif::fonctionasc()
{
     ui->tabanime->setModel(tmpanime.afficherasc());
}

void modif::on_trie_asc_clicked()
{

    fonctionasc();
}



void modif::fonctiondesc()
{
     ui->tabanime->setModel(tmpanime.afficherdesc());
}

void modif::on_trie_desc_clicked()
{

    fonctiondesc();
}



void modif::modifierfonction()
{
    int id = ui->lineEdit_idanim_2->text().toInt();
    QString typeanim= ui->lineEdit_typeanim_2->text();
    QString lieu= ui->lineEdit_lieu_2->text();
     QString dateanim= ui->lineEdit_dateanim_2->text();
      int duree= ui->lineEdit_duree_2->text().toInt();
      int cin= ui->lineEdit_cin_2->text().toInt();

    Animation anim(id,typeanim,lieu,dateanim,duree,cin);
  bool test=anim.modifier(id);
  if(test)
{
      //ui->tabanim->setModel(tmpanim.afficher());
      ui->tabanime->setModel(tmpanime.afficherasc());
      ui->tabanime->setModel(tmpanime.afficherdesc());
//ui->table_tick_5->setModel(tmptick.calcul_prix());//refresh


QMessageBox::information(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Animation modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void modif::on_pb_modifier_clicked()
{
  modifierfonction();
}











