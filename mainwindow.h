#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <bird1.h>
#include <block.h>
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void closeEvent(QCloseEvent *);
    Block *block[15];
    QGraphicsPixmapItem *exit;
    int btn_w,btn_h,i;
    Bird *birdie,*birdie2,*birdie3;
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    int birdtype;
};

#endif // MAINWINDOW_H
