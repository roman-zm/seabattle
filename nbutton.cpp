#include "nbutton.h"

#include <QMouseEvent>
#include <QPushButton>

NButton::NButton(int x, int y, QWidget *parent) : QPushButton(parent),
    x(x),
    y(y)
{
    QColor bgColor = this->palette().color(QPalette::Base);
    this->setFixedSize(30,30);
    this->setStyleSheet(
                QString("background-color: %1; border: 1px solid black;").arg(bgColor.name())
                );
    this->setFlat(true);

}

int NButton::getY() const
{
    return y;
}

int NButton::getX() const
{
    return x;
}

void NButton::changeColor(QColor color)
{
    this->setStyleSheet(QString("background-color: %1; border: 1px solid black;").arg(color.name()));
}

void NButton::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
}
