#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class statistique;
}

class statistique : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
    void makePolt();

private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H