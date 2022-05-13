#include "rect.hpp"
Rect::Rect(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

Rect::Rect(int x, int y, int x1, int y1)
{
   this->x = (x < x1 ? x : x1);
   this->y = (y < y1 ? y : y1);
   height = y - y1;
   width = x - x1;
   if (height < 0)
       height = height * (-1);
   if (width < 0)
       width = width * (-1);
}
bool Rect::contains(int x, int y)
{
    return ((x <= this->x + width) && (x >= this->x) && (y <= this->y + height) && (y >= this->y));
}
int Rect::getWidth() const
{
    return width;
}
int Rect::getHeight() const
{
    return height;
}
int Rect::getX() const
{
    return x;
}
int Rect::getY() const
{
    return y;
}
Rect Rect::intersect(Rect rect)
{
    int x1 = this->x > rect.x ? this->x : rect.x;
    int x2 = this->x + this->width  < rect.x + rect.width ? this->x + this->width : rect.x + rect.width;
    int y1 = this->y > rect.y ? this->y : rect.y;
    int y2 = this->y + this->height < rect.y + rect.height ? this->y + this->height : rect.y + rect.height;
    return Rect(x1,y1,x2,y2);
}

int Rect::getColor() const
{
    return color;
}

void Rect::setColor(int newColor)
{
    color = newColor;
}




