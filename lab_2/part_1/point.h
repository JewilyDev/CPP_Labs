#ifndef POINT_H
#define POINT_H
class QPainter;
class Point
{
public:
    Point(float x = -1, float y = -1,int size = 0);// Конструктор по-умолчанию задает "нерисуемую точку", чтобы при ошибке ввода не плодились точки в углу. При этом остается возможность нарисовать точку в (0,0)
    float getX() const;
    void setX(float newX);

    float getY() const;
    void setY(float newY);

    bool validate();

    int getWidth() const;
    void setWidth(int newWidth);

    int getSize() const;
    void setSize(int newSize);

    void draw(QPainter *painter);
private:
    float x;
    float y;
    int size;
    int width; // Я осознанно в конструктор не засунул толщину линии, т.к это побочный параметр. Размер - важнее, а толщина, ну а что толщина?


};


#endif // POINT_H
