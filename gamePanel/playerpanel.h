#ifndef PLAYERPANEL_H
#define PLAYERPANEL_H

#include <QWidget>

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
};

#endif // PLAYERPANEL_H
