#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(bim != nullptr)
    {
        int d = bim->getD();
        painter.drawEllipse(bim->getX() - (d / 2), bim->getY() - (d / 2),d,d);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    bim = new Ball();
    bim->setX(event->x());
    bim->setY(event->y());
    bim->setDy(-1);
    bim->setDx(-1);
    bim->setD(20);
    repaint();
}

void MainWindow::update()
{
    if(!bim)
        return;
    int d = bim->getD();
    int x = bim->getX();
    int y = bim->getY();
    int dy = bim ->getDy();
    int dx = bim->getDx();
    QRect rect = contentsRect();
    int  height = rect.height();
    int  width = rect.width();
    if(x - (d / 2) <= 0 || (x + (d / 2)) >= width)
    {
       bim->setDx(dx * - 1);
       dx = bim->getDx();
    }
    if(y - (d / 2) <= 0 || (y + (d / 2)) >= height)
    {
        bim->setDy(dy * - 1);
         dy = bim->getDy();
    }
    bim->setX(dx + x);
    bim->setY(dy + y);
    repaint();
}
