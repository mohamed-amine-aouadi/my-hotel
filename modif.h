#ifndef MODIF_H
#define MODIF_H

#include <QMainWindow>
#include "animation.h"
#include "equipement.h"
#include "update.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QDialog>
#include <QSystemTrayIcon>
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class modif;
}
QT_END_NAMESPACE

class modif : public QDialog
{
    Q_OBJECT

public:
    explicit modif(QWidget *parent = nullptr);
    ~modif();

void fonctionrechercher();
void fonctionasc();
void fonctiondesc();
void  modifierfonction();

private slots:
     void on_Rechercher_2_clicked();
     void on_trie_asc_clicked();
     void on_trie_desc_clicked();
     void on_pb_modifier_clicked();



private:
    Ui::modif *ui;
    Animation tmpanim;
    Animation tmpanime;

    Equipement tmpequip;
    Equipement tmpequipement;

};

#endif // MODIF_H
