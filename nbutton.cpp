#include "nbutton.h"
#include <QToolButton>

NButton::NButton(int x, int y, QWidget *parent) : QToolButton(parent),
    x(x),
    y(y)
{

}

int NButton::getY() const
{
    return y;
}

int NButton::getX() const
{
    return x;
}
