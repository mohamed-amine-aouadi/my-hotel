#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "materiaux.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "evenement.h"
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabWidget->setTabText(0,"Hebergement");
ui->tabWidget->setTabText(1,"Restauration");
ui->tabWidget->setTabText(2,"Resources humaines");
ui->tabWidget->setTabText(3,"Evenements");
ui->tabWidget->setTabText(4,"Loisirs");
ui->tabWidget_2->setTabText(0,"Reservation");
ui->tabWidget_2->setTabText(1,"Hebergement");
ui->tabWidget_3->setTabText(0,"");
ui->tabWidget_3->setTabText(1,"");
ui->tabWidget_4->setTabText(0,"Personnel");
ui->tabWidget_4->setTabText(1,"Demande");
ui->tabWidget_5->setTabText(0,"Materiaux");
ui->tabWidget_5->setTabText(1,"Evenements");
ui->tabWidget_6->setTabText(0,"Animation");
ui->tabWidget_6->setTabText(1,"Equipe");
ui->NomPrenom_2->setPlaceholderText("Nom et prenom");
ui->CIIN_2->setPlaceholderText("CIN");
ui->NBpersonnes_2->setPlaceholderText("Nombre de personnes");
ui->TypeCH->setPlaceholderText("Type de chambre");
ui->TypePT->setPlaceholderText("Type de pension");
ui->payer_2->setPlaceholderText("Somme a payer ...");
ui->Num->setPlaceholderText("Numero de chambre");
ui->Etat->setPlaceholderText("Etat");
ui->NbPr->setPlaceholderText("Nombre de personnes");
ui->Type->setPlaceholderText("Type");
ui->CIINP_2->setPlaceholderText("CIN");
ui->Ref->setPlaceholderText("Reference");
ui->QNT->setPlaceholderText("Quantité");
ui->etatM->setPlaceholderText("Etat");
ui->TypeEVE->setPlaceholderText("Type");
ui->NBpEVE->setPlaceholderText("Nombre de personnes");
ui->IdANIM->setPlaceholderText("ID");
ui->LieuANIM->setPlaceholderText("Lieu");
ui->TypeANIM->setPlaceholderText("Type");
ui->IdANIM_2->setPlaceholderText("ID");
ui->etatANIM->setPlaceholderText("etat");
ui->quantiteANIM->setPlaceholderText("Quantite");
ui->TypeANIM2->setPlaceholderText("Type");

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_4_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_7_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_11_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_14_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_20_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_23_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_27_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_16_clicked()
{
    QString ref=ui->Ref->text();
    int nbr = ui->QNT->text().toInt();
    QString etat = ui->etatM->text();
    materiaux M(ref,nbr,etat);
    bool test=M.ajout();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_19_clicked()
{
    int id = ui->idEVE->text().toInt();
    QString type = ui->TypeEVE->text();
    QString date =ui->calendarWidget_5->selectedDate().toString();
    int nbrE = ui->NBpEVE->text().toInt();
    evenement E(id,type,date,nbrE);
    bool test = E.ajoutE();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }


}



void MainWindow::on_pushButton_38_clicked()
{
    d =new Dialog(this);
    d->show();
}

void MainWindow::on_pushButton_21_clicked()
{
    d2 =new Dialog2(this);
    d2->show();
}
