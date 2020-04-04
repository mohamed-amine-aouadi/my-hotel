#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"
#include "affichagepersonnel.h"
#include "affichage.h"
#include "demande.h"
#include "dialogmateriaux.h"
#include "dialogevenement.h"
#include "statistique.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    affichagepersonnel *secPage;
    Affichage *secPag;
    PERSONNEL tmppersonnel;
    demande tmpdemande;
    dialogMateriaux *d;
    DialogEvenement *d2;
    Statistique *statistique ;


};
#endif // MAINWINDOW_H
