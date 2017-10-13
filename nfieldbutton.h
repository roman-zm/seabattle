#ifndef NFIELDBUTTON_H
#define NFIELDBUTTON_H

#include "nbutton.h"

class NFieldButton : public NButton
{
    Q_OBJECT
public:
    explicit NFieldButton(int x, int y, QWidget *parent = nullptr);

    enum State {
        miss,
        empty
    };

    int getX() const;

    int getY() const;

signals:

public slots:
private:
    int x;
    int y;
};

#endif // NFIELDBUTTON_H
