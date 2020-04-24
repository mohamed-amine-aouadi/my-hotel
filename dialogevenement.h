#ifndef DIALOGEVENEMENT_H
#define DIALOGEVENEMENT_H

#include <QDialog>
#include "evenement.h"
#include "statevenement.h"

namespace Ui {
class DialogEvenement;
}

class DialogEvenement : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvenement(QWidget *parent = nullptr);
    ~DialogEvenement();

private slots:

private:
    Ui::DialogEvenement *ui;


};

#endif // DIALOGEVENEMENT_H
