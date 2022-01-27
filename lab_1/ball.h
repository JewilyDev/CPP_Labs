#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball();
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
    int dx = -5;
    int dy = -5;
    int d = 20;
};


#endif // BALL_H
