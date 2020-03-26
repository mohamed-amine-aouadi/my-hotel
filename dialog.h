#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "materiaux.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_18_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_36_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Dialog *ui;
    materiaux tmpM ;

};

#endif // DIALOG_H
