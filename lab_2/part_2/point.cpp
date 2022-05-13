#include "point.h"
#include <QPainter>
Point::Point(float x,float y, int size,int thickness,bool isDragged)
    : x(x),y(y),size(size),thickness(thickness),isDragged(isDragged)
{}
float Point::getX() const
{
    return x;
}

void Point::setX(float newX)
{
    x = newX;
}

float Point::getY() const
{
    return y;
}

void Point::setY(float newY)
{
    y = newY;
}

bool Point::validate(){
    return (this->getX() > 0 && this->getY() > 0);
}

int Point::getThickness() const
{
    return thickness;
}

void Point::setThickness(int newThickness)
{
    thickness = newThickness;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

float Point::distance2(const QPoint &point){
     float xQuad = ((point.x() - this->getX()) * (point.x() - this->getX()));
     float yQuad = ((point.y() - this->getY()) * (point.y() - this->getY()));
     return (xQuad + yQuad);
}

bool Point::getIsDragged() const
{
    return isDragged;
}

void Point::setIsDragged(bool newIsDragged)
{
    isDragged = newIsDragged;
}


     ;
void Point::draw(QPainter *painter){
    float x = this->getX();
    float y = this->getY();
    int sizeModif = this->getSize() / 2;// Если 'this' не лучшее, что есть в программировании, тогда что - лучшее?
    int thickness = this->getThickness();
    QPen pen;
    pen.setWidth(thickness);
    painter->setPen(pen);
    painter->drawLine(x - sizeModif,y,x + sizeModif,y);
    painter->drawLine(x,y - sizeModif ,x,y + sizeModif);
}

void Point::connectPoints(QPainter *painter,Point *point){
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(point->getX(),point->getY(),this->getX(),this->getY());
}


