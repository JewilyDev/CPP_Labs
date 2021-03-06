#include "ball.h"

Ball::Ball()
    :
      x(0),y(0),d(1),dx(1),dy(1)
{}

Ball::Ball(int x, int y, int d,int dx,int dy)
{
    this->x = x;
    this->y = y;
    this->d = d;
    this->dx = dx;
    this->dy = dy;

}

int Ball::getDy() const
{
    return dy;
}

void Ball::setDy(int value)
{
    dy = value;
}

int Ball::getDx() const
{
    return dx;
}

void Ball::setDx(int value)
{
    dx = value;
}

int Ball::getY() const
{
    return y;
}

void Ball::setY(int value)
{
    y = value;
}

int Ball::getX() const
{
    return x;
}

void Ball::setX(int value)
{
    x = value;
}

int Ball::getD() const
{
    return d;
}

void Ball::setD(int value)
{
    d = value;
}
