#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamePanel/nbattlefield.h"
#include "scorepanel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    field = new NBattleField(10, 1, 2, 3, 4, this);
    panel = new ScorePanel(this);
    enemyField = new NBattleField(10, 1, 2, 3, 4, this);

    ui->horizontalLayout->addWidget(field);
    ui->horizontalLayout->addWidget(panel);
    ui->horizontalLayout->addWidget(enemyField);
}

MainWindow::~MainWindow()
{
    delete ui;
}
