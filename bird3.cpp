#include "bird3.h"

Bird3::Bird3(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;//
    bodydef.type = b2_dynamicBody;//this will be a dynamic body
    bodydef.bullet = true;
    bodydef.position.Set(x,y);//set the starting position
    bodydef.userData = this;
    //bodydef.angle = 90;
    g_body = world->CreateBody(&bodydef);//set the body to the world

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD3_DENSITY;
    fixturedef.friction = BIRD3_FRICTION;
    fixturedef.restitution = BIRD3_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Bird3::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
