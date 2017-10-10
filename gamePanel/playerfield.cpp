#include <QMouseEvent>
#include <QMessageBox>

#include "playerfield.h"
#include "nbattlefield.h"

playerField::playerField(
        int fieldSize, int fourDeck, int threeDeck, int twoDeck, int oneDeck, QWidget *parent
        ) : NBattleField(fieldSize, fourDeck, threeDeck, twoDeck, oneDeck, parent)
{

}

void playerField::addShip(NShip *ship, int x, int y)
{
    NShip::Orientation orientation = ship->getShipOrientation();
    int size = ship->getSize();
    ship->setLocation(x, y);

    for(int i=0, ix=x, iy=y; i<size; i++){
        this->buttons[ix][iy]->changeColor(Qt::green);
        orientation == NShip::Orientation::Horizontal ? iy++ : ix++;
    }

    shipsVector.push_back(ship);
}

void playerField::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        foreach(QVector<NButton*> buttonVector, this->buttons){
            foreach (NButton *button, buttonVector) {
                if(button->geometry().contains(event->pos())){
                    QMessageBox::information(
                                this, "tite",
                                QString("button %1 %2").arg(button->getX()).arg(button->getY())
                                );
                    return;
                }
            }

        }
    }
}
