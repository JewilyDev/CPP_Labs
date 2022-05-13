#include "point.h"
#include <QPainter>
Point::Point(float x,float y, int size)
    : x(x),y(y),size(size)
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

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

void Point::draw(QPainter *painter){
    float x = this->getX();
    float y = this->getY();
    int sizeModif = this->getSize() / 2;// Если 'this' не лучшее, что есть в программировании, тогда что - лучшее?
    int width = this->getWidth();
    QPen pen;
    pen.setWidth(width);
    painter->setPen(pen);
    painter->drawLine(x - sizeModif,y,x + sizeModif,y);
    painter->drawLine(x,y - sizeModif ,x,y + sizeModif);
}


