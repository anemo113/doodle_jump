#include "View.h"
#include "Button.h"

View::View() : QGraphicsView()
{
    // ceate viewController
    viewController = new Controller();

    // create scene
    setScene(viewController->scene);

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    //set fixed size
    setFixedSize(550,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

View::~View()
{
    delete viewTimer;
    delete viewController;
}

void View::menu()
{
    //clear the screen
    viewController->scene->clear();

    //doodler picture
    QGraphicsPixmapItem * menuPic = new QGraphicsPixmapItem();
    menuPic->setPixmap(QPixmap(":/images/menuPic.png"));
    menuPic->setPos(0, 20);
    viewController->scene->addItem(menuPic);

    //play button
    Button * playButton = new Button("Play");
    playButton->setPos(200, 375);
    connect(playButton, SIGNAL(clicked()), this, SLOT(intro()));
    viewController->scene->addItem(playButton);

    //help button
    Button * helpButton = new Button("Help");
    helpButton->setPos(200, 475);
    connect(helpButton, SIGNAL(clicked()), this, SLOT(help()));
    viewController->scene->addItem(helpButton);

    //exit button
    Button * exitButton = new Button("Exit");
    exitButton->setPos(200, 575);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    viewController->scene->addItem(exitButton);
}

void View::intro()
{
    //clear the screen
    viewController->scene->clear();

    //back button
    Button * backButton = new Button("Back");
    backButton->setPos(0, 0);
    connect(backButton, SIGNAL(clicked()), this, SLOT(menu()));
    viewController->scene->addItem(backButton);

    //singleplayer button
    Button * singleButton = new Button("SinglePlayer");
    singleButton->setPos(200, 475);
    connect(singleButton, SIGNAL(clicked()), this, SLOT(singleMode()));
    viewController->scene->addItem(singleButton);

    //multiplayer button
    Button * multiButton = new Button("MultiPlayer");
    multiButton->setPos(200, 575);
    connect(multiButton, SIGNAL(clicked()), this, SLOT(multiMode()));
    viewController->scene->addItem(multiButton);

}

void View::help()
{
    //clear the screen
    viewController->scene->clear();

    //help picture
    QGraphicsPixmapItem * helpPic = new QGraphicsPixmapItem();
    helpPic->setPixmap(QPixmap(":/images/helpPic.jpg"));
    viewController->scene->addItem(helpPic);

    //back button
    Button * backButton = new Button("Back");
    backButton->setPos(235, 670);
    connect(backButton, SIGNAL(clicked()), this, SLOT(menu()));
    viewController->scene->addItem(backButton);
}

void View::singleMode()
{
    //clear the screen
    viewController->scene->clear();

    //back button
    Button * backButton = new Button("Back");
    backButton->setPos(0, 0);
    connect(backButton, SIGNAL(clicked()), this, SLOT(menu()));
    viewController->scene->addItem(backButton);
}

void View::multiMode()
{
    //clear the screen
    viewController->scene->clear();

    //back button
    Button * backButton = new Button("Back");
    backButton->setPos(0, 0);
    connect(backButton, SIGNAL(clicked()), this, SLOT(menu()));
    viewController->scene->addItem(backButton);
}
