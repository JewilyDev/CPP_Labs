#ifndef RECT_HPP
#define RECT_HPP

class Rect
{
public:
    Rect();
    Rect(int x, int y, int x1, int y1);
    bool contains(int x, int y);
    int getWidth() const;

    int getHeight() const;

    int getX() const;

    int getY() const;
    Rect intersect(Rect rect);

    int getColor() const;
    void setColor(int newColor);

private:

    int width;
    int height;
    int x;
    int y;
    int color = -1;


};

#endif // RECT_HPP
