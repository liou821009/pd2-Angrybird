#ifndef BLOCK_H
#define BLOCK_H

#include <gameitem.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>

class Block : public GameItem
{
public:
    Block(float x, float y, float w, float h,QPixmap pixmap, b2World *world, QGraphicsScene *scene, QTimer *timer);
};

#endif // LAND_H
