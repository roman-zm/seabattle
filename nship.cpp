#include <QObject>
#include "nship.h"

NShip::NShip(int size, QObject *parent, Orientation orientation) : QObject(parent),
    size(size),
    shipOrientation(orientation)
{

}

bool NShip::woundedAt(int deck)
{
    return woundArray[deck] ? true : false;
}

NShip::Orientation NShip::getShipOrientation() const
{
    return shipOrientation;
}

int NShip::getSize() const
{
    return size;
}

bool NShip::isWounded() const
{
    return wounded;
}

bool NShip::isKilled() const
{
    return killed;
}

NShip::Location NShip::getLocation() const
{
    return location;
}

void NShip::setLocation(const Location &value)
{
    location = value;
}

void NShip::setLocation(int x, int y)
{
    location.x = x;
    location.y = y;
}
