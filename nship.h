#ifndef NSHIP_H
#define NSHIP_H

#include <QObject>

class NShip : public QObject
{
    Q_OBJECT
public:
    NShip(QObject *parent);

    struct Location{
        int x;
        int y;
    };

    enum Orientation {
        Horizontal,
        Vertical
    };

    bool woundedAt(int deck);

    Orientation getShipOrientation() const;

    int getSize() const;

    bool isWounded() const;

    bool isKilled() const;

    Location getLocation() const;
    void setLocation(const Location &value);

private:
    Location location;
    int size;
    bool wounded = false;
    int woundArray[4] = {0, 0, 0, 0};
    bool killed = false;
    Orientation shipOrientation;

};

#endif // NSHIP_H
