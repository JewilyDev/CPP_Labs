#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball();
    Ball(int x, int y, int d,int dx = 0, int dy = 0);

    int getDy() const;
    void setDy(int value);

    int getDx() const;
    void setDx(int value);

    int getY() const;
    void setY(int value);

    int getX() const;
    void setX(int value);

    int getD() const;
    void setD(int value);

private:
    int x;
    int y;
    int dx;
    int dy;
    int d;
};


#endif // BALL_H
