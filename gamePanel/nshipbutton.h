#ifndef NSHIPBUTTON_H
#define NSHIPBUTTON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMouseEvent>

#include "nbutton.h"

class NShipButton : public QWidget
{
    Q_OBJECT
public:
    explicit NShipButton(int x, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
private:
    int x;
    QHBoxLayout *hLayout;
    QGridLayout *gLayout;
    QVector<NButton*> decks;

};

#endif // NSHIPBUTTON_H
