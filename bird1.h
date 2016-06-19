#ifndef BIRD1_H
#define BIRD1_H


#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD1_DENSITY 10.0f
#define BIRD1_FRICTION 0.2f
#define BIRD1_RESTITUTION 0.5f

class Bird1 : public GameItem
{
public:
    Bird1(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
};



#endif // BIRD1_H
