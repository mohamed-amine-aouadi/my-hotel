#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animation.h"
#include "equipement.h"
#include "update.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QDialog>
#include <QSystemTrayIcon>
#include "qcustomplot.h"
#include "modif.h"
#include "pdf.h"
#include "modifier.h"




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
    //me
    void on_pb_ajouter_clicked();

    void on_pb_ajout_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier_clicked();



    void on_pb_modifier_2_clicked();

    void on_Rechercher_2_clicked();


    void on_trie_asc_clicked();

    void on_trie_desc_clicked();

   void on_Rechercher_3_clicked();


   void on_trie_asc_2_clicked();

   void on_trie_desc_2_clicked();

   void on_imprimer_paie_clicked();

   void on_commandLinkButton_2_clicked();

   void on_statistique_clicked();
   void on_pushButton_imprimer_4_clicked();
   void on_update_clicked();
   void on_pdf_clicked();
    void on_pdf_2_clicked();
    void on_resaisir_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_27_clicked();

    void on_actionPrint_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_Me_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionPrint_2_triggered();
     void makePlot();
     void on_updatee_clicked();

     void on_modifier_clicked();

     void on_modifier_2_clicked();

private:
    Ui::MainWindow *ui;
    Animation tmpanim;
    Animation tmpanime;

    Equipement tmpequip;
    Equipement tmpequipement;


    modif *up;
    pdf *go;
    modifier *yes;



};
#endif // MAINWINDOW_H
