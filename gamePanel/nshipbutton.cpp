#include "nshipbutton.h"
#include <QSpacerItem>
#include <QLabel>
#include <QMessageBox>
#include <QDrag>
#include <QMimeData>
#include "nship.h"

NShipButton::NShipButton(int x, QWidget *parent) : QWidget(parent),
    x(x)
{
    hLayout = new QHBoxLayout(this);

    hLayout->setSpacing(0);
    hLayout->setMargin(0);

    this->setLayout(hLayout);

    for(int i=0; i<x; i++){
        decks.push_back(new NButton(this));
        decks.last()->changeColor(Qt::green);
        //decks.last()->setDisabled(true);
        hLayout->addWidget(decks.last());
    }

    this->setFixedWidth(decks[x-1]->width()*x);


}

void NShipButton::mousePressEvent(QMouseEvent *event)
{
    bool rotate = event->button() == Qt::LeftButton ? false : true;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData();

//    mimeData->setText(QString::number(x) + ", " +
//                      QString::number(rotate ? NShip::Vertical : NShip::Horizontal));
     mimeData->setText(QString::number(x) + "," +
                      (rotate ? "Vertical" : "Horizontal"));
   drag->setMimeData(mimeData);
    QPixmap px = this->grab();
    if(rotate){
        QPoint center = px.rect().center();
        QMatrix matrix;
        matrix.translate(center.x(), center.y());
        matrix.rotate(90);
        px = px.transformed(matrix);
    }
    drag->setPixmap(px);

    Qt::DropAction dropAction = drag->exec();
    return;
}
