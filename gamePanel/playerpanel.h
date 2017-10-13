#ifndef PLAYERPANEL_H
#define PLAYERPANEL_H

#include <QWidget>
#include <QMouseEvent>

#include "playerfield.h"

namespace Ui {
class playerPanel;
}

class playerPanel : public QWidget
{
    Q_OBJECT

public:
    explicit playerPanel(QWidget *parent = 0);
    ~playerPanel();

private:
    Ui::playerPanel *ui;
    playerField *field;
};

#endif // PLAYERPANEL_H
