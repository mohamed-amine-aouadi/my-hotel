#include "statevenement.h"
#include "ui_statevenement.h"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
statevenement::statevenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statevenement)
{
    ui->setupUi(this);
    this->setWindowTitle("statevenement");
           //makePolt();
}

statevenement::~statevenement()
{
    delete ui;
}
