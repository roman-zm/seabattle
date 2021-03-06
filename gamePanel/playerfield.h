#ifndef PLAYERFIELD_H
#define PLAYERFIELD_H

#include "nbattlefield.h"
#include "nship.h"

class playerField : public NBattleField
{
    Q_OBJECT
public:

    enum fieldPanel {
        AddMode,
        GameMode
    };

    playerField(int fieldSize, int fourDeck, int threeDeck, int twoDeck,
                          int oneDeck, QWidget *parent = 0);
    void addShip(NShip *ship, int x, int y);

    //void mouseMoveEvent(QMouseEvent *event);
protected:
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    QVector<NShip*> shipsVector;
};

#endif // PLAYERFIELD_H
