#include "mainwindow.h"
#include "ui_mainwindow.h"
std::vector<QColor> MainWindow::arColors = {Qt::red,Qt::yellow,Qt::green,Qt::blue,Qt::black};

void MainWindow::colorSort(std::vector<Rect> &rects)
{
  for (int i = 0; i < (int)rects.size() - 1; i++) {
    for (int j = 0; j < (int)rects.size() - i - 1; j++) {
      if (rects[j].getColor() > rects[j + 1].getColor()) {
        Rect tmpR = rects[j];
        rects[j] = rects[j +1];
        rects[j + 1] = tmpR;
       }
    }
  }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
   if(event->modifiers() & Qt::AltModifier)
   {
      if(!initialX && !initialY){
          initialX = event->x();
          initialY = event->y();
      }
      else{
          Rect rect = Rect(initialX,initialY,event->x(),event->y());
          arRect.push_back(rect);
          initialX = 0;
          initialY = 0;
      }
   }
   else
   {
       Rect curRect = Rect();
       int intersections = 0;
       for(int i = 0; i < (int)arRect.size(); i++){ // каст в инт чтобы кьют не ругался, очень раздражают подчеркивания.
           Rect rect = arRect.at(i);
           if(rect.contains(event->x(),event->y())){
               if(rect.getX() != curRect.getX() && rect.getY() != curRect.getY())
               {
                   if(intersections)
                       curRect = rect.intersect(curRect);
                   else
                       curRect = rect;
                   intersections++;
               }else{
                   // Закоментировать для того, чтобы фрагмент можно было перекрасить
                   intersections = 0;
                   break;
               }
           }
       }
       if(intersections > 1) {
         curRect.setColor(intersections - 2);
         arRect.push_back(curRect);
       }
   };
   MainWindow::colorSort(arRect);
   repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(arRect.size() > 0)
    {
     for(int i = 0; i < (int)arRect.size(); i++)
     {
         Rect rect = arRect.at(i);
         painter.drawRect(rect.getX(),rect.getY(),rect.getWidth(),rect.getHeight());
         if(rect.getColor() > -1){
           painter.fillRect(rect.getX() + 1 ,rect.getY() + 1,rect.getWidth()- 1,rect.getHeight() - 1,arColors[rect.getColor()]);
         }
     }     
   }
}
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

