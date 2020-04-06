#ifndef MODIFIER_H
#define MODIFIER_H

#include <QMainWindow>
#include "animation.h"
#include "equipement.h"
#include "update.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QDialog>
#include <QSystemTrayIcon>
#include "qcustomplot.h"

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();
    void rechercherequipement();
      void trieasc2();
      void triedesc2();
      void modifierequipement();

    private slots:
   void on_Rechercher_3_clicked();
   void on_trie_asc_2_clicked();

   void on_trie_desc_2_clicked();
   void on_pb_modifier_2_clicked();




private:
    Ui::modifier *ui;
    Animation tmpanim;
    Animation tmpanime;

    Equipement tmpequip;
    Equipement tmpequipement;
};

#endif // MODIFIER_H
