#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "personnel.h"
#include <QMessageBox>
#include "dialog.h"
#include "demande.h"
#include "dialogmateriaux.h"
#include "materiaux.h"
#include "evenement.h"
#include "login.h"

#include "ui_statevenement.h"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include "statevenement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    login L;
    L.close();
    ui->setupUi(this);
    makePolt();

   ui->tabWidget->setTabText(0,"Hebergement");
      ui->tabWidget->setTabText(1,"Restauration");
         ui->tabWidget->setTabText(2,"Resources humaines");
            ui->tabWidget->setTabText(3,"Evenements");
            ui->tabWidget->setTabText(4,"Loisirs");
ui->tabWidget_2->setTabText(0,"Reservation");
ui->tabWidget_2->setTabText(1,"Hebergement");
ui->tabWidget_3->setTabText(0,"");
ui->tabWidget_3->setTabText(1,"");
ui->tabWidget_4->setTabText(0,"Personnel");
ui->tabWidget_4->setTabText(1,"Demande");
ui->tabWidget_5->setTabText(0,"Materiaux");
ui->tabWidget_5->setTabText(1,"Evenements");
ui->tabWidget_6->setTabText(0,"Animation");
ui->tabWidget_6->setTabText(1,"Equipe");


ui->NomPrenom_2->setPlaceholderText("Nom et prenom");
ui->CIIN_2->setPlaceholderText("CIN");
ui->NBpersonnes_2->setPlaceholderText("Nombre de personnes");
ui->TypeCH->setPlaceholderText("Type de chambre");
ui->TypePT->setPlaceholderText("Type de pension");
ui->payer_2->setPlaceholderText("Somme a payer ...");
ui->Num->setPlaceholderText("Numero de chambre");
ui->Etat->setPlaceholderText("Etat");
ui->NbPr->setPlaceholderText("Nombre de personnes");
ui->Type->setPlaceholderText("Type");
ui->cin->setPlaceholderText("CIN");
ui->grade->setPlaceholderText("Grade");
ui->salaire->setPlaceholderText("Salaire");
ui->CIINP_2->setPlaceholderText("CIN");

ui->QUANTITE_DEMANDE->setPlaceholderText("Quantite Demande");
ui->Ref->setPlaceholderText("Reference");
ui->QNT->setPlaceholderText("Quantité");
ui->etatM->setPlaceholderText("Etat");
ui->NomEVE->setPlaceholderText("id ");
ui->TypeEVE->setPlaceholderText("Type");
ui->NBpEVE->setPlaceholderText("Nombre de personnes");
ui->IdANIM->setPlaceholderText("ID");
ui->LieuANIM->setPlaceholderText("Lieu");
ui->TypeANIM->setPlaceholderText("Type");
ui->IdANIM_2->setPlaceholderText("ID");
ui->etatANIM->setPlaceholderText("etat");
ui->quantiteANIM->setPlaceholderText("Quantite");
ui->TypeANIM2->setPlaceholderText("Type");
/*ui->recherche_cin->setPlaceholderText("CIN");
ui->recherche_grade->setPlaceholderText("GRADE");
ui->recherche_salaire->setPlaceholderText("SALAIRE");
ui->recherche_date->setPlaceholderText("DATE");
ui->recherche_presence->setPlaceholderText("PRESENCE");*/
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_4_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_7_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_11_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_14_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_20_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_23_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_27_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_10_clicked()
{
    int CIN = ui->cin->text().toInt();
    QString GRADE = ui->grade->text();
    int SALAIRE = ui->salaire->text().toInt();
    QString DATECONTRAT = ui->date->selectedDate().toString();
    PERSONNEL p(CIN,GRADE,0,SALAIRE,DATECONTRAT);
    bool test=p.ajouter();
    if (test)
    {

        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                              QObject::tr("personnel ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



/*
void MainWindow::on_pushButton_12_clicked()
{

  secPage =new affichagepersonnel(this);
      secPage->show();

}
*/
void MainWindow::on_pushButton_13_clicked()
{
  int CIN = ui->CIINP_2->text().toInt();
  QString TYPE_DEMANDE = ui->TYPE_DEMANDE->currentText();
  int QUANTITE_DEMANDE = ui->QUANTITE_DEMANDE->text().toInt();
   QString DATEDEBUT = ui->DATEDEBUT->selectedDate().toString();
   demande d(0,QUANTITE_DEMANDE,TYPE_DEMANDE,CIN,0,DATEDEBUT);
   bool test=d.ajouter_demande();
   if (test)
   {

       QMessageBox::critical(nullptr, QObject::tr("database is open"),
                             QObject::tr("demande ajouter.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }




}
/*
void MainWindow::on_pushButton_15_clicked()
{
    secPag =new Affichage(this);
        secPag->show();
}
*/

void MainWindow::on_pushButton_16_clicked()
{
    QString ref=ui->Ref->text();
    int nbr = ui->QNT->text().toInt();
    QString etat = ui->etatM->text();
    materiaux M(ref,nbr,etat);
    bool test=M.ajout();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_19_clicked()
{
    int id = ui->NomEVE->text().toInt();
    QString type = ui->TypeEVE->text();
    QString date =ui->calendarWidget_5->selectedDate().toString();
    int nbrE = ui->NBpEVE->text().toInt();
    evenement E(id,type,date,nbrE);
    bool test = E.ajoutE();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

/*void MainWindow::on_pushButton_21_clicked()
{
    d2 =new DialogEvenement(this);
    d2->show();
}
*/
/*void MainWindow::on_pushButton_clicked()
{
    statistique = new Statistique (this);
    statistique->show();
}*/

void MainWindow::on_pushButton_18_clicked()
{
    ui->tableView->setModel(tmpM.afficher());
}

void MainWindow::on_pushButton_31_clicked()
{
    QString ref=ui->Ref_3->text();
    int nbr = ui->QNT_3->text().toInt();
    QString etat = ui->etatM_3->text();
    materiaux M(ref,nbr,etat);
    bool test=M.modif(ref,nbr);
    bool test2=M.modifEtat(ref,etat);
    if (test || test2)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString  val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM MATERIEL WHERE REF_MAT=:num");
        qry.bindValue(":num",val);
        if (qry.exec())
        {
            while (qry.next()) {
                ui->Ref_3->setText(qry.value(0).toString());
                ui->QNT_3->setText(qry.value(1).toString());
                ui->etatM_3->setText(qry.value(2).toString());
                }

        }
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->idMS->text().toInt();
    bool test = tmpM.supp(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("materiaux supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_28_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

       QPrinter printer ;
       QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
        if (daddy->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;



}

void MainWindow::on_pushButton_33_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;

       doc.setHtml(document->toPlainText());
        doc.print(&printer);

}

void MainWindow::on_pushButton_36_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox->currentText();
       QString val=ui->rechercheM->text();
       val="%"+val+"%";
       if (type=="reference"){
           request.prepare("SELECT * FROM MATERIEL WHERE REF_MAT LIKE:val order by REF_MAT");
       }else if (type=="nbr"){
           request.prepare("SELECT * FROM MATERIEL WHERE NBR_MAT LIKE:val order by NBR_MAT");
       }else if (type=="etat"){
           request.prepare("SELECT * FROM MATERIEL WHERE ETAT_MAT LIKE:val order by ETAT_MAT");
       }

       request.bindValue(":val",val);
       request.exec();
       modal->setQuery(request);
       ui->tableView->setModel(modal);
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->tableView->setModel(tmpM.afficher());

}

void MainWindow::on_pushButton_21_clicked()
{
    ui->tableView_2->setModel(tmpE.afficherE());

}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->idES_2->text().toInt();
    bool test = tmpE.suppE(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("evenement supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}
/*
void MainWindow::on_pushButton_29_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
           // out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;

       doc.setHtml(document->toPlainText());
        doc.print(&printer);

}
*/
void MainWindow::on_pushButton_30_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

QPrinter printer ;
       QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
        if (daddy->exec() == QDialog::Accepted) {
            document->print(&printer);

        }

        delete document;


}

/*void MainWindow::on_pushButton_36_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox->currentText();
       QString val=ui->rechercheM_3->text();
       val="%"+val+"%";
       if (type=="id"){
           request.prepare("SELECT * FROM EVENEMENT WHERE IDEVE LIKE:val order by IDEVE");
       }else if (type=="type"){
           request.prepare("SELECT * FROM EVENEMENT WHERE TYPEEVE LIKE:val order by TYPEEVE");
       }else if (type=="date"){
           request.prepare("SELECT * FROM EVENEMENT WHERE DATEEVE LIKE:val order by DATEEVE");
       }else if (type=="nbr"){
           request.prepare("SELECT * FROM EVENEMENT WHERE NBEVE LIKE:val order by NBEVE");
       }

       request.bindValue(":val",val);
       request.exec();
       modal->setQuery(request);
       ui->tableView_2->setModel(modal);
}*/

/*void MainWindow::on_pushButton_33_clicked()
{
    int id = ui->idEVE_3->text().toInt();
    QString type = ui->TypeEVE_3->text();
    QString date =ui->calendarWidget_8->selectedDate().toString();
    int nbrE = ui->NBpEVE_3->text().toInt();
    evenement E(id,type,date,nbrE);
    bool test = E.modifE(id,type,date,nbrE);
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement modifiée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_2->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM EVENEMENT WHERE IDEVE=:num");
        qry.bindValue(":num",val);
        if (qry.exec())
        {
            while (qry.next()) {
                ui->idEVE_3->setText(qry.value(0).toString());
                ui->TypeEVE_3->setText(qry.value(1).toString());
                ui->NBpEVE_3->setText(qry.value(3).toString());
                }

        }
}*/
/*
void MainWindow::on_pushButton_37_clicked()
{
    secPage =new statevenement(this);
            secPage->show();
}

*/

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->idMS->text().toInt();
    bool test = tmpM.supp(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("materiaux supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_32_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
           // out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;

       doc.setHtml(document->toPlainText());
        doc.print(&printer);

}
void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_2->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM EVENEMENT WHERE IDEVE=:num");
        qry.bindValue(":num",val);
        if (qry.exec())
        {
            while (qry.next()) {
                ui->idEVE_3->setText(qry.value(0).toString());
                ui->TypeEVE_3->setText(qry.value(1).toString());
                ui->NBpEVE_3->setText(qry.value(3).toString());
                }

        }
}

void MainWindow::on_pushButton_34_clicked()
{
    int id = ui->idEVE_3->text().toInt();
    QString type = ui->TypeEVE_3->text();
    QString date =ui->calendarWidget_8->selectedDate().toString();
    int nbrE = ui->NBpEVE_3->text().toInt();
    evenement E(id,type,date,nbrE);
    bool test = E.modifE(id,type,date,nbrE);
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement modifiée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_37_clicked()
{

        QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox_2->currentText();
           QString val=ui->rechercheM_3->text();
           val="%"+val+"%";
           if (type=="id"){
               request.prepare("SELECT * FROM EVENEMENT WHERE IDEVE LIKE:val order by IDEVE");
           }else if (type=="type"){
               request.prepare("SELECT * FROM EVENEMENT WHERE TYPEEVE LIKE:val order by TYPEEVE");
           }else if (type=="date"){
               request.prepare("SELECT * FROM EVENEMENT WHERE DATEEVE LIKE:val order by DATEEVE");
           }else if (type=="nbr"){
               request.prepare("SELECT * FROM EVENEMENT WHERE NBEVE LIKE:val order by NBEVE");
           }

           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tableView_2->setModel(modal);
    }




void MainWindow::makePolt()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Stat pandoud");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;

    labels << ">100 personne" << "<100 personne" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int nbr;
int he;
QSqlQuery query1("select count(*) from EVENEMENT where NBEVE > 100 ");
while (query1.next()) {

                        he = query1.value(0).toInt();

                                                    }

    QSqlQuery query2("select count(*) from EVENEMENT where NBEVE < 100 ");
    while (query2.next()) {
                           nbr = query2.value(0).toInt();

                             }


    regenData << he << nbr ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
