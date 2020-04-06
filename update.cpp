#include "update.h"
#include "ui_update.h"
#include"QSqlRecord"
#include"QSqlQuery"


update::update(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::update)
{
    ui->setupUi(this);
}

update::~update()
{
    delete ui;
}
