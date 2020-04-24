#include "dialogmateriaux.h"
#include "ui_dialogmateriaux.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
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

dialogMateriaux::dialogMateriaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogMateriaux)
{
    ui->setupUi(this);
}

dialogMateriaux::~dialogMateriaux()
{
    delete ui;
}
