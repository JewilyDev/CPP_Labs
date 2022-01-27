#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug("Paint");
    QPainter painter(this);
    /*
    painter.drawLine(x - 2,y,x + 2,y);
    painter.drawLine(x,y - 2,x,y + 2);
    */
    //painter.drawLine(0,0,100,100);
    painter.drawEllipse(bim.x -  (bim.r / 2),bim.y  - (bim.r / 2),bim.r,bim.r);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //qDebug("X = %d Y = %d",event->x(),event->y());
    bim.x = event->x();
    bim.y = event->y();
    bim.dx = -1;
    bim.dy = -1;
    bim.r = 20;
    repaint();
}

void MainWindow::update()
{
    //qDebug("Tick");
    QRect rect = contentsRect();
    int  height = rect.height();
    int  width = rect.width();
    if(bim.x - (bim.r / 2) <= 0 || (bim.x + (bim.r / 2)) >= width){
       bim.dx = bim.dx * - 1;
    }
    if(bim.y - (bim.r / 2) <= 0 || (bim.y + (bim.r / 2)) >= height){
        bim.dy = bim.dy * - 1;
    }
    bim.x += bim.dx;
    bim.y += bim.dy;
    repaint();
}
