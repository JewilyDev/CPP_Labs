#ifndef RECT_H
#define RECT_H


class Rect
{
public:
    Rect();
    Rect(int x, int y, int x1, int y1);
    int getOriginX() const;


    int getOriginY() const;


    int getHeight() const;

    int getWeidth() const;
    bool contains(int x, int y);

private:
    int originX = 0, originY = 0, height = 0, weidth = 0;
};

#endif // RECT_H
