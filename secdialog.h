#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_tri_clicked();

    void on_Csearch_clicked();

    void on_print_clicked();

    void on_pdf_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
