#ifndef PLAYERPANEL_H
#define PLAYERPANEL_H

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

    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);

private:
    QVector<NShip*> shipsVector;
};

#endif // PLAYERPANEL_H
