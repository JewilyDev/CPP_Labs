#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(pointsCount)
         for(int i = 0; i < pointsCount;i++){
             Point *point = arPoints[i];
             point->draw(&painter);
         }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int prevPointSize = (pointsCount ? arPoints[pointsCount - 1]->getSize():3);
    int width = (pointsCount < 5 ? 1 : 2);
    Point *point = new Point(event->x(),event->y(),prevPointSize + 1);
    if(point->validate()){
        if(pointsCount < 10){
            point->setWidth(width);
            arPoints[pointsCount] = point;
            pointsCount++;
        }
    }
    else
        delete point;

    repaint();

}

void MainWindow::update(){

    repaint();
}
