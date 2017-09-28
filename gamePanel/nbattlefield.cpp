#include "nbattlefield.h"
#include "ui_nbattlefield.h"

#include <QToolButton>

NBattleField::NBattleField(
        int fieldSize, int fourDeck, int threeDeck,
        int twoDeck, int oneDeck, QWidget *parent
    ) : QWidget(parent),
    ui(new Ui::NBattleField),
    fieldSize(fieldSize),
    fourDeck(fourDeck),
    threeDeck(threeDeck),
    twoDeck(twoDeck),
    oneDeck(oneDeck)
{
    ui->setupUi(this);
    gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
    initField();
}

NBattleField::~NBattleField()
{
    delete ui;
}

void NBattleField::initField()
{
    for(int i=0; i<fieldSize; i++) {
        QPixmap px(20,20);
        //px.fill(QColor(80,80,80));
        px.fill(Qt::red);
        QVector<QToolButton*> buff;
        for(int j=0; j<fieldSize; j++) {
            buff.push_back(new QToolButton(this));
            gridLayout->addWidget(buff[j], i, j, Qt::AlignCenter | Qt::AlignHCenter);
            buff.last()->setIcon(QIcon(px));
        }
        buttons.push_back(buff);
    }
}
