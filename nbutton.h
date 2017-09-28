#ifndef NBUTTON_H
#define NBUTTON_H

#include <QPushButton>

class NButton : public QPushButton
{
    Q_OBJECT
public:
    NButton(int x, int y, QWidget *parent = Q_NULLPTR);
    int getY() const;

    int getX() const;

private:
    int x;
    int y;
};

#endif // NBUTTON_H
