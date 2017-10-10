#include "playerpanel.h"
#include "ui_playerpanel.h"

playerPanel::playerPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPanel)
{
    ui->setupUi(this);
}

playerPanel::~playerPanel()
{
    delete ui;
}
