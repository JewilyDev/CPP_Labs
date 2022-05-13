#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //qDebug
    count++;
    if (count == 1){
        x = event->x();
        y = event->y();
    }
    if (count == 2){
        //qDebug("ttt");
        rect = new Rect(x, y, event->x(), event->y());
//        rect-> originX = x;
//        rect-> originY = y;
//        rect-> weidth = abs(x - event->x());
//        rect-> height = abs(y - event->y());
    }
    if (count > 2){
        //if ((rect->getOriginX() + rect->getWeidth())>= event->x()&& event->x() >= getOriginX() && rect->getOriginY() + rect->getWeidth())
          if (rect->contains(event->x(), event->y())){
              qDebug("Попадание");
          }
          else
              qDebug("Промах");
    }
    //qDebug("%d", count);
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   if (rect != nullptr){
       QPainter painter(this);
       painter.drawLine(rect->getOriginX(), rect->getOriginY(), rect->getOriginX() + rect->getWeidth(), rect->getOriginY());
       painter.drawLine(rect->getOriginX(), rect->getOriginY() +  rect->getHeight(), rect->getOriginX() + rect->getWeidth(), rect->getOriginY() +rect->getHeight());
       painter.drawLine(rect->getOriginX(), rect->getOriginY(), rect->getOriginX(), rect->getOriginY() + rect->getHeight());
       painter.drawLine(rect->getOriginX() + rect->getWeidth(), rect->getOriginY(), rect->getOriginX() + rect->getWeidth(), rect->getOriginY() + rect->getHeight());
   }

}

