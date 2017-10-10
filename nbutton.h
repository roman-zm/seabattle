#ifndef NBUTTON_H
#define NBUTTON_H

#include <QPushButton>

class NButton : public QPushButton
{
    Q_OBJECT
public:
    NButton(int x, int y, QWidget *parent = Q_NULLPTR);

    enum state {
        mi
    };

    int getY() const;

    int getX() const;

    void changeColor(QColor color);
private:
    int x;
    int y;

    void mousePressEvent(QMouseEvent *event);
};

#endif // NBUTTON_H
