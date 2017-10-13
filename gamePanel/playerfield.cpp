#include <QMouseEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QStringList>

#include "playerfield.h"
#include "nbattlefield.h"

playerField::playerField(
        int fieldSize, int fourDeck, int threeDeck, int twoDeck, int oneDeck, QWidget *parent
        ) : NBattleField(fieldSize, fourDeck, threeDeck, twoDeck, oneDeck, parent)
{
    setAcceptDrops(true);
}

void playerField::addShip(NShip *ship, int x, int y)
{
    NShip::Orientation orientation = ship->getShipOrientation();
    int size = ship->getSize();

    if(orientation == NShip::Horizontal){
        if(y+size-1 >= this->fieldSize)
            return;
    } else if(orientation == NShip::Vertical) {
        if(x+size-1 >= this->fieldSize)
            return;
    }

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
        foreach(QVector<NFieldButton*> buttonVector, this->buttons){
            foreach (NFieldButton *button, buttonVector) {
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

void playerField::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void playerField::dropEvent(QDropEvent *event)
{
    foreach(QVector<NFieldButton*> buttonVector, this->buttons){
        foreach (NFieldButton *button, buttonVector) {
            if(button->geometry().contains(event->pos())){
                QStringList params = event->mimeData()->text().split(",");
                NShip::Orientation orient = params.at(1) == "Vertical" ? NShip::Vertical : NShip::Horizontal;
                this->addShip(new NShip(params.at(0).toInt(), this, orient), button->getX(), button->getY());
            }
        }
    }
}
