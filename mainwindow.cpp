#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "animation.h"
#include "equipement.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include"QDate"
#include <iostream>
#include "statistique.h"
#include "modif.h"
#include "pdf.h"
#include "modifier.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabanim->setModel(tmpanim.afficher());
ui->tabequip->setModel(tmpequip.afficher_2());




//ui->tabanime->setModel(tmpanime.afficherasc());
//ui->tabequipement->setModel(tmpequipement.afficherasc_2());
// MainWindow::makePlot();

QPixmap pix("C:/Users/ASUS/Desktop/youssefselmi/imagees/equip");
int W = ui->label_pic->width();
int H = ui->label_pic->height();
ui->label_pic->setPixmap(pix.scaled(W,H,Qt::KeepAspectRatio));

QPixmap pixe("C:/Users/ASUS/Desktop/youssefselmi/imagees/animation");
int q = ui->label_anim->width();
int s = ui->label_anim->height();
ui->label_anim->setPixmap(pixe.scaled(q,s,Qt::KeepAspectRatio));









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
ui->tabWidget_6->setTabText(1,"Equipement");





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
ui->CIINP->setPlaceholderText("CIN");
ui->Grade->setPlaceholderText("Grade");
ui->Salaire->setPlaceholderText("Salaire");
ui->CIINP_2->setPlaceholderText("CIN");
ui->TypeP->setPlaceholderText("Type ");
ui->Demande->setPlaceholderText("Demande");
ui->Ref->setPlaceholderText("Reference");
ui->QNT->setPlaceholderText("Quantité");
ui->etatM->setPlaceholderText("Etat");
ui->NomEVE->setPlaceholderText("Nom ");
ui->TypeEVE->setPlaceholderText("Type");
ui->NBpEVE->setPlaceholderText("Nombre de personnes");



ui->lineEdit_idanim->setPlaceholderText("ID");
ui->lineEdit_typeanim->setPlaceholderText("Lieu");
ui->lineEdit_lieu->setPlaceholderText("Type");
ui->lineEdit_duree->setPlaceholderText("DUREE EN MINUTE");
//ui->lineEdit_dateanim->setPlaceholderText("Date");
ui->lineEdit_cin->setPlaceholderText("CIN");



ui->lineEdit_id->setPlaceholderText("IDEQUIPEMENT");
ui->lineEdit_type->setPlaceholderText("TYPEEQUIPEMENT");
ui->lineEdit_nb->setPlaceholderText("NOMBRE");
ui->lineEdit_idanimation->setPlaceholderText("IDEANIMATION");

}








MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_resaisir_clicked()
{
        //reset champ
        ui->lineEdit_idanim->clear();
        ui->lineEdit_typeanim->clear();
        ui->lineEdit_lieu->clear();
        ui->lineEdit_dateanim->clear();
        ui->lineEdit_duree->clear();
        ui->lineEdit_cin->clear();


}


void MainWindow::on_pb_ajouter_clicked()
{


    if(ui->lineEdit_idanim->text()=="" || ui->lineEdit_idanim->text()=="*champ obligatoire")
        ui->lineEdit_idanim->setText("**champ obligatoire**");

    {
        QMessageBox::critical(nullptr, QObject::tr("champ obligatoire"),
                    QObject::tr("champ obligatoire !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    if(ui->lineEdit_duree->text()=="" || ui->lineEdit_duree->text()=="*champ obligatoire")
    {
        QMessageBox::critical(nullptr, QObject::tr("champ obligatoire"),
                    QObject::tr("champ obligatoire !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }




    if(ui->lineEdit_typeanim->text()=="" || ui->lineEdit_typeanim->text()=="*Type obligatoire*")
        ui->lineEdit_typeanim->setText("*Type obligatoire*");

    if(ui->lineEdit_lieu->text()=="" || ui->lineEdit_lieu->text()=="*Lieux obligatoire")
        ui->lineEdit_lieu->setText("*Lieux obligatoire*");


    if(ui->lineEdit_cin->text().toInt()==0 || ui->lineEdit_cin->text()=="*CIN obligatoire*" || ui->lineEdit_cin->text()=="")
        ui->lineEdit_cin->setText("*CIN obligatoire*");



    int id = ui->lineEdit_idanim->text().toInt();
    QString typeanim= ui->lineEdit_typeanim->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString dateanim= ui->lineEdit_dateanim->text();
    int duree= ui->lineEdit_duree->text().toInt();
    int cin= ui->lineEdit_cin->text().toInt();




  Animation e(id,typeanim,lieu,dateanim,duree,cin);
  bool test=e.ajouter();
  if(test)
{

      ui->tabanim->setModel(tmpanim.afficher());//refresh
      //ui->tabanime->setModel(tmpanime.afficherasc());//refresh

       //ui->tabanime->setModel(tmpanime.afficherdesc());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une animation"),
                  QObject::tr("Animation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une animation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_supprimer_5_clicked()
{
int idanim = ui->lineEdit_id_7->text().toInt();
bool test=tmpanim.supprimer(idanim);
if(test)
{ui->tabanim->setModel(tmpanim.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une animation"),
                QObject::tr("Animation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une animation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}





/*void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_idanim_2->text().toInt();
    QString typeanim= ui->lineEdit_typeanim_2->text();
    QString lieu= ui->lineEdit_lieu_2->text();
     QString dateanim= ui->lineEdit_dateanim_2->text();
      int duree= ui->lineEdit_duree_2->text().toInt();
      int cin= ui->lineEdit_cin_2->text().toInt();

    Animation anim(id,typeanim,lieu,dateanim,duree,cin);
  bool test=anim.modifier(id);
  if(test)
{ui->tabanim->setModel(tmpanim.afficher());
     // ui->tabanime->setModel(tmpanime.afficherasc());
     // ui->tabanime->setModel(tmpanime.afficherdesc());
//ui->table_tick_5->setModel(tmptick.calcul_prix());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Animation modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

*/



/*void MainWindow::on_Rechercher_2_clicked()
{
    QString id=ui->lineEdit_id_3->text();
    ui->tab_ab_rech_2->setModel(tmpanim.recherche(id));
}
*/

/*void MainWindow::on_trie_asc_clicked()
{

    ui->tabanime->setModel(tmpanime.afficherasc());
}


void MainWindow::on_trie_desc_clicked()
{

    ui->tabanime->setModel(tmpanime.afficherdesc());
}

*/























void MainWindow::on_pb_ajout_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString type= ui->lineEdit_type->text();
    int nb= ui->lineEdit_nb->text().toInt();
    int idanimation= ui->lineEdit_idanimation->text().toInt();


    Equipement e(id,type,nb,idanimation);
  bool test=e.ajout();
  if(test)
{

     ui->tabequip->setModel(tmpequip.afficher_2());//refresh
     //  ui->tabanime->setModel(tmpanime.afficherasc());//refresh

       //ui->tabanime->setModel(tmpanime.afficherdesc());//refresh
    // MainWindow::makePlot();
QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                  QObject::tr("Equipement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_supprimer_3_clicked()
{
int id = ui->lineEdit_idsuprime_2->text().toInt();


bool test=tmpequip.supprimer_2(id);
if(test)
{ui->tabequip->setModel(tmpequip.afficher_2());//refresh
  //  MainWindow::makePlot();
    QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                QObject::tr("Equipement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}








/*void MainWindow::on_pb_modifier_2_clicked()
{
    int ide = ui->lineEdit_idmodif->text().toInt();
    QString type= ui->lineEdit_typemodif->text();
     int nb= ui->lineEdit_nbmodif->text().toInt();
    int idanimation= ui->lineEdit_idanimationmodif->text().toInt();



    Equipement equip(ide,type,nb,idanimation);
    bool test=equip.modifier_2(ide);
  if(test)
{
      ui->tabequip->setModel(tmpequip.afficher_2());

      //ui->tabequip->setModel(tmpequip.afficherasc());
      // ui->tabequip->setModel(tmpequip.afficherdesc());


   // MainWindow::makePlot();
QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Equipement modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

*/


/*void MainWindow::on_Rechercher_3_clicked()
{
    QString ide=ui->lineEdit_idrechercher->text();
    ui->tab_ab_rech_3->setModel(tmpequip.recherche_2(ide));
}

*/


/*void MainWindow::on_trie_asc_2_clicked()
{

    ui->tabequipement->setModel(tmpequipement.afficherasc_2());
}


void MainWindow::on_trie_desc_2_clicked()
{

    ui->tabequipement->setModel(tmpequipement.afficherdesc_2());
}

*/



















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




void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_Me_triggered()
{
   QMessageBox::information(this,"About Me","This is about Me");
}

void MainWindow::on_actionAbout_QT_triggered()
{
QApplication::aboutQt();
}






void MainWindow::on_imprimer_paie_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabanim->model()->rowCount();
            const int columnCount = ui->tabanim->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES Factures ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabanim->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabanim->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabanim->isColumnHidden(column)) {
                        QString data =ui->tabanim->model()->data(ui->tabanim->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}


void MainWindow::on_statistique_clicked()
{


        statistique *a=new statistique();
        a->show();


}

void MainWindow::on_modifier_clicked()
{
    up = new modif(this);
    up->show();


}

void MainWindow::on_modifier_2_clicked()
{
    yes = new modifier(this);
    yes->show();
}



void MainWindow::on_pdf_clicked()
{
    go = new pdf(this);
    go->show();


}

void MainWindow::on_pdf_2_clicked()
{
    go = new pdf(this);
    go->show();


}



























/*void MainWindow::on_pushButton_imprimer_4_clicked()
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/ASUS/Desktop/XteamV00/MonPDF.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        QString code=ui->lineEdit_code_pdf_3->text();
        QSqlQuery query;
        QString typeanim_pdf,id_pdf,nb_pdf,type_pdf,idanimation_pdf,lieu_pdf,dateanim_pdf,duree_pdf,cin_pdf;


        if (ui->comboBox_type_pdf_3->currentText()=="equipement")
        {
            query.prepare("select * from equipement where id='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                    nb_pdf=query.value(1).toString();
                    type_pdf=query.value(3).toString();
                    idanimation_pdf=query.value(2).toString();

                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"Equipement");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"Type: ");
            painter.drawText(20,500,"Nombre:");
            painter.drawText(20,650,"IDanimation:");


            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawText(300,500,type_pdf);
            painter.drawText(300,300,nb_pdf);
            painter.drawText(300,650,idanimation_pdf);

        }
        else
        {
            query.prepare("select * from animation where idanim='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                    typeanim_pdf=query.value(1).toString();
                    lieu_pdf=query.value(2).toString();
                    dateanim_pdf=query.value(3).toString();
                    duree_pdf=query.value(4).toString();
                    cin_pdf=query.value(5).toString();
                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"Animation");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"Type de l'animation: ");
            painter.drawText(20,500,"Lieu de l'animation:");
            painter.drawText(20,650,"Date de l'animation:");
            painter.drawText(20,850,"Duree de l'animation:");
            painter.drawText(20,1000,"CIN de l'animateur:");




            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);



            painter.drawText(400,500,typeanim_pdf);
            painter.drawText(400,300,lieu_pdf);
            painter.drawText(400,650,dateanim_pdf);
             painter.drawText(400,850,duree_pdf);
             painter.drawText(400,1000,cin_pdf);



            //painter.drawText(150,350,taux_pdf+"%");
        }

        QImage image("C:/Users/ASUS/Desktop/XteamV00/icon");
        painter.drawImage(-30,-100,image);

        painter.end();

        qDebug()<<"le pdf a ete cree";
        QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}



*/



/*void MainWindow::on_pushButton_22_clicked()
{
       SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
       smtp.setUser("youssefselmi99@gmail.com");
       smtp.setPassword("info2018");
       MimeMessage message;
       message.setSender(new EmailAddress("youssefselmi99@gmail.com", "YOUSSEF"));
       message.addRecipient(new EmailAddress("youssef.selmi@esprit.tn", "Selmi Youssef"));
       //message.setSubject(ui->lineEdit_2->text());
        message.setSubject("hola");
       MimeText text;
       text.setText(ui->lineEdit_3->text());
       message.addPart(&text);
       smtp.connectToHost();
       smtp.login();


       if(smtp.sendMail(message))
       {
           QMessageBox::information(nullptr, QObject::tr("Mail envoyé"),
                             QObject::tr("Mail envoyé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

       }else

           QMessageBox::critical(nullptr, QObject::tr("Envoie mail"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       smtp.quit();
}

*/








