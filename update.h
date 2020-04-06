#ifndef UPDATE_H
#define UPDATE_H


#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class update;
}

class update : public QMainWindow
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    ~update();

private:
    Ui::update *ui;
};

#endif // UPDATE_H
