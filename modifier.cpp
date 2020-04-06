#include "modifier.h"
#include "ui_modifier.h"
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


modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
    ui->tabequipement->setModel(tmpequipement.afficherasc_2());

    ui->lineEdit_idmodif->setPlaceholderText("IDEQUIPEMENT");
    ui->lineEdit_typemodif->setPlaceholderText("TYPEEQUIPEMENT");
    ui->lineEdit_nbmodif->setPlaceholderText("NOMBRE");
    ui->lineEdit_idanimationmodif->setPlaceholderText("IDEANIMATION");

    QPixmap pixele("C:/Users/ASUS/Desktop/youssefselmi/imagees/modif");
    int qqq = ui->label_10->width();
    int sss = ui->label_10->height();
    ui->label_10->setPixmap(pixele.scaled(qqq,sss,Qt::KeepAspectRatio));
}

modifier::~modifier()
{
    delete ui;
}


void modifier::rechercherequipement()
{
    QString ide=ui->lineEdit_idrechercher->text();
    ui->tab_ab_rech_3->setModel(tmpequip.recherche_2(ide));
}



void modifier::on_Rechercher_3_clicked()
{
rechercherequipement();
}


void modifier::on_trie_asc_2_clicked()
{
    trieasc2();
}
void modifier::on_trie_desc_2_clicked()
{
 triedesc2();
}

void modifier::trieasc2()
{

    ui->tabequipement->setModel(tmpequipement.afficherasc_2());
}



void modifier::triedesc2()
{

    ui->tabequipement->setModel(tmpequipement.afficherdesc_2());
}








void modifier::on_pb_modifier_2_clicked()
{
    modifierequipement();
}



void modifier::modifierequipement()
{
    int ide = ui->lineEdit_idmodif->text().toInt();
    QString type= ui->lineEdit_typemodif->text();
     int nb= ui->lineEdit_nbmodif->text().toInt();
    int idanimation= ui->lineEdit_idanimationmodif->text().toInt();



    Equipement equip(ide,type,nb,idanimation);
    bool test=equip.modifier_2(ide);
  if(test)
{
     // ui->tabequip->setModel(tmpequip.afficher_2());

      ui->tabequipement->setModel(tmpequip.afficherasc_2());
       ui->tabequipement->setModel(tmpequip.afficherdesc_2());


   // MainWindow::makePlot();
QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Equipement modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}






