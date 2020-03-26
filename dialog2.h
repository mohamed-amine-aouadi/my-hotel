#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "evenement.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void on_pushButton_21_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

private:
    Ui::Dialog2 *ui;
    evenement tmpE ;

};

#endif // DIALOG2_H
