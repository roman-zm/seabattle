#include <QHBoxLayout>

#include "playerpanel.h"
#include "ui_playerpanel.h"
#include "nshipbutton.h"

playerPanel::playerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPanel)
{
    ui->setupUi(this);

    field = new playerField(10, 1, 2, 3, 4, this);
    ui->verticalLayout->addWidget(field);

    ui->verticalLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding, QSizePolicy::Minimum));

    for(int i=4; i>0; i--){
        NShipButton *shipB = new NShipButton(i, this);
        ui->verticalLayout->addWidget(shipB);
    }

    ui->verticalLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Minimum, QSizePolicy::Expanding));
    
}

playerPanel::~playerPanel()
{
    delete ui;
}
