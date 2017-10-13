#include "nfieldbutton.h"

NFieldButton::NFieldButton(int x, int y, QWidget *parent) : NButton(parent),
    x(x),
    y(y)
{

}

int NFieldButton::getX() const
{
    return x;
}

int NFieldButton::getY() const
{
    return y;
}
