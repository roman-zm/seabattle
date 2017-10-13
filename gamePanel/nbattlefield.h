#ifndef NBATTLEFIELD_H
#define NBATTLEFIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>

#include "nship.h"
//#include "nbutton.h"
#include "nfieldbutton.h"

namespace Ui {
class NBattleField;
}

class NBattleField : public QWidget
{
    Q_OBJECT

public:
    explicit NBattleField(int fieldSize, int fourDeck, int threeDeck, int twoDeck,
                          int oneDeck, QWidget *parent = 0);

    ~NBattleField();

protected:
    QGridLayout *gridLayout;
    QVector< QVector<NFieldButton*> > buttons;
    int fieldSize;
    int fourDeck, threeDeck, twoDeck, oneDeck;
    Ui::NBattleField *ui;

private:
    void initField();

    //QVector<int> ships;

};

#endif // NBATTLEFIELD_H
