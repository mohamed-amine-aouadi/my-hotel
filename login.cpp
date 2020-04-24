#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString log = ui->lineEdit->text();
    QString mdp = ui->lineEdit_2->text();
    if (log=="admin" && mdp=="admin")
    {
        M =new MainWindow(this);
        M->show();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("wrong admin or password.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


}
