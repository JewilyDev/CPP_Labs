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
    if(arPoints.size())
         for(int i = 0; i <(int)arPoints.size();i++){
             Point *point = arPoints.at(i);//Лишняя проверка, но мне кажется противорелигиозным - обращаться через [i] к вектору.
             point->draw(&painter);
             if(i){
                 point->connectPoints(&painter,arPoints.at(i - 1));
             }
         }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int size = arPoints.size();
    QPoint clickPoint;
    clickPoint.setX(event->x());
    clickPoint.setY(event->y());
    bool doNotCreate = false;
    for(int i = 0; i < size; i++){
       if(arPoints.at(i)->distance2(clickPoint) <= 5){
          arPoints.erase(arPoints.begin() + i);
          doNotCreate = true;
          break;
        }
     }
        if(!doNotCreate){
            Point *point = new Point(event->x(),event->y());
            arPoints.push_back(point);
        }
        repaint();
    }  

void MainWindow::update(){

    repaint();
}
