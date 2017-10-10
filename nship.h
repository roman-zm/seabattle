#ifndef NSHIP_H
#define NSHIP_H

#include <QObject>

class NShip : public QObject
{
    Q_OBJECT
public:
    enum Orientation {
        Horizontal,
        Vertical
    };

    NShip(int size, QObject *parent, Orientation orientation = Orientation::Horizontal);

    struct Location{
        int x;
        int y;
    };

    bool woundedAt(int deck);

    Orientation getShipOrientation() const;

    int getSize() const;

    bool isWounded() const;

    bool isKilled() const;

    Location getLocation() const;
    void setLocation(const Location &value);
    void setLocation(int x, int y);

private:
    Location location;
    int size;
    bool wounded = false;
    int woundArray[4] = {0, 0, 0, 0};
    bool killed = false;
    Orientation shipOrientation;

};

#endif // NSHIP_H
