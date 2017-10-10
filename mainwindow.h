#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamePanel/nbattlefield.h"
#include "scorepanel.h"
#include "gamePanel/playerfield.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//    NBattleField *field;
    playerField *field;
    ScorePanel *panel;
    NBattleField *enemyField;
};

#endif // MAINWINDOW_H
