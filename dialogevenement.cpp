#include "dialogevenement.h"
#include "ui_dialogevenement.h"
#include "evenement.h"
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
#include <QCalendar>

#endif

DialogEvenement::DialogEvenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvenement)
{
    ui->setupUi(this);
}

DialogEvenement::~DialogEvenement()
{
    delete ui;
}
