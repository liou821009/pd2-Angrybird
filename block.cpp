#include "block.h"

Block::Block(float x, float y, float w, float h,QPixmap pixmap, b2World *world, QGraphicsScene *scene, QTimer *timer):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);

    // Create body


        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.userData = this;
        bodyDef.position.Set(x,y);
        g_body = world->CreateBody(&bodyDef);
        b2PolygonShape bodyBox;
        bodyBox.SetAsBox(w,h);
        b2FixtureDef fixturedef;
        fixturedef.shape = &bodyBox;
        fixturedef.density = 10;
        fixturedef.friction = 0.2;
        fixturedef.restitution = 0.5;
        g_body->SetAngularDamping(3);
        //setTransformOriginPoint(w/2,h/2);
        g_body->CreateFixture(&fixturedef);
        scene->addItem(&g_pixmap);
        connect(timer, SIGNAL(timeout()), this,SLOT(paint()));



    //g_body->CreateFixture(&bodyBox,9.0f);



    //g_body->SetTransform(b2Vec2(bodyDef.position.x,bodyDef.position.y),a*3.141592/180);
}
