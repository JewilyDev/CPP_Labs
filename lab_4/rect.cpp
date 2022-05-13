#include "rect.h"

Rect::Rect()
{

}

Rect::Rect(int x, int y, int x1, int y1)
{
   originX = (x < x1 ? x : x1);
   originY = (y < y1 ? y : y1);
   height = y - y1;
   weidth = x - x1;
   if (height < 0)
       height = height * (-1);
   if (weidth < 0)
       weidth = weidth * (-1);
}

int Rect::getOriginX() const
{
    return originX;
}

int Rect::getOriginY() const
{
    return originY;
}

int Rect::getHeight() const
{
    return height;
}

int Rect::getWeidth() const
{
    return weidth;
}

bool Rect::contains(int x, int y)
{
    if ((x <= originX + weidth) && (x >= originX) && (y <= originY + height) && (y >= originY))
        return true;
    return false;
}
