#include "nbattlefield.h"
#include "ui_nbattlefield.h"
#include "nbutton.h"

#include <QPushButton>

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
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    initField();
}

NBattleField::~NBattleField()
{
    delete ui;
}

void NBattleField::initField()
{
    for(int i=0; i<fieldSize; i++) {
        QVector<NFieldButton*> buff;
        for(int j=0; j<fieldSize; j++) {
            buff.push_back(new NFieldButton(i, j, this));
            gridLayout->addWidget(buff[j], i, j, Qt::AlignCenter | Qt::AlignHCenter);
        }
        buttons.push_back(buff);
    }
    this->setFixedSize(buttons[0][0]->height()*fieldSize, buttons[0][0]->height()*fieldSize);
}
