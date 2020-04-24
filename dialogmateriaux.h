#ifndef DIALOGMATERIAUX_H
#define DIALOGMATERIAUX_H

#include <QDialog>
#include "materiaux.h"

namespace Ui {
class dialogMateriaux;
}

class dialogMateriaux : public QDialog
{
    Q_OBJECT

public:
    explicit dialogMateriaux(QWidget *parent = nullptr);
    ~dialogMateriaux();

private slots:

private:
    Ui::dialogMateriaux *ui;
    materiaux tmpM ;

};

#endif // DIALOGMATERIAUX_H
