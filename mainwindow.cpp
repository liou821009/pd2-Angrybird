#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    //Create block
    block[0] = new Block(10,6.8,1,2,QPixmap(":/image/Rock.png").scaled(width()/17.0,height()/3.7),world,scene,&timer);
    block[1] = new Block(20,6.8,1,2.2,QPixmap(":/image/oh.png").scaled(width()/17.0,height()/3.7),world,scene,&timer);
    block[2] = new Block(10,11.3,1,2.2,QPixmap(":/image/Rock.png").scaled(width()/17.0,height()/3.7),world,scene,&timer);
    block[3] = new Block(10,14.8,1,2.2,QPixmap(":/image/Rock.png").scaled(width()/17.0,height()/3.7),world,scene,&timer);
    block[4] = new Block(20,11.3,1,2,QPixmap(":/image/oh.png").scaled(width()/17.0,height()/3.7),world,scene,&timer);

    //Block *blockie = new Block(23.0f,10.0f,0.27f,&timer,QPixmap(":/image/Wood_Block_break1 .jpg").scaled(height()/6.0,height()/6.0),world,scene);
    // Create bird (You can edit here)
    //birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    srand(time(NULL));
    i = rand()%3;
    std::cout << i << std::endl ;
    birdtype = 0;
    if(i == 0)
    {
        birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
        birdtype = 0;
    }
    else if(i == 1)
    {
        birdie2 = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/image/yellowbird.png").scaled(height()/9.0,height()/9.0),world,scene);
        birdtype = 1;
    }
    else
    {
        birdie3= new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/image/bluebird.png").scaled(height()/9.0,height()/9.0),world,scene);
        birdtype = 2;
    }



    Bird1 *birdie1 = new Bird1(15.0f,5.0f,0.5f,&timer,QPixmap(":/image/pig.png").scaled(height()/9.0,height()/8.0),world,scene);

    // Setting the Velocity
    //birdie2->setLinearVelocity(b2Vec2(6,5));
    //birdie->setLinearVelocity(b2Vec2(6,5));

    //blockie->setLinearVelocity(b2Vec2(-5,5));
    itemList.push_back(birdie2);
    itemList.push_back(birdie1);

    //itemList.push_back(blockie);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    exit = new QGraphicsPixmapItem();
    QPixmap exit1;
    exit1.load(":/image/exit.jpg");
    exit1 = exit1.scaled(exit1.width()*1/8,exit1.height()*1/8,Qt::KeepAspectRatio);
    exit->setPixmap(exit1);
    exit->setPos(930,0);
    btn_w = (exit1.width()*3)/2 - 60;
    btn_h = (exit1.height()*3)/2 - 30;
    scene->addItem(exit);


}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x() > exit->pos().x() && event->scenePos().x() <= exit->pos().x()+btn_w)
    {
        if(event->scenePos().y() > exit->pos().y() && event->scenePos().y() <= exit->pos().y()+btn_h)
        {
            emit quitGame();

        }
    }

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        int i = rand()%4;
        if(birdtype == 0)
        {
            birdie->setLinearVelocity(b2Vec2(5,5));

        }
        else if(birdtype == 1)
        {
            birdie2->setLinearVelocity(b2Vec2(30,0));

        }
        else
        {
            birdie3->setLinearVelocity(b2Vec2(30,15));

        }


        /* TODO : add your code here */

        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event

    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
