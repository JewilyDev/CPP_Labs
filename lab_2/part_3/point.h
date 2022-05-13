#ifndef POINT_H
#define POINT_H
class QPainter;
class QPoint;
class Point
{
public:
    Point(float x = -1, float y = -1,int size = 3,int thickness = 1,bool isDragged = false);// Конструктор по-умолчанию задает "нерисуемую точку", чтобы при ошибке ввода не плодились точки в углу. При этом остается возможность нарисовать точку в (0,0)
    float getX() const;
    void setX(float newX);

    float getY() const;
    void setY(float newY);

    bool validate();

    int getThickness() const;
    void setThickness(int newThickness);

    int getSize() const;
    void setSize(int newSize);

    void draw(QPainter *painter);
    void connectPoints(QPainter *painter,Point *point);

    float distance2(const QPoint &point);

    bool getIsDragged() const;
    void setIsDragged(bool newIsDragged);

private:
    float x;
    float y;
    int size;
    int thickness; // Теперь я осознанно занес толщину по-умолчанию в конструктор, т.к мне видится лишним городить кучу полей для дефолтного значения.
    bool isDragged;



};


#endif // POINT_H
