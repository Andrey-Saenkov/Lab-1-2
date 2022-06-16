#ifndef POINT_H
#define POINT_H

#include <QPainter>

class Point
{
public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;

    void drawPoint(QPainter *painter);


    int getOffset() const;
    void setOffset(int newOffset);

    void setCoords(int x, int y);

    void setY(int y);

    void setX(int x);

    double distance2(int x, int y);



    int getWidth() const;
    void setWidth(int newWidth);

private:
    int x, y, offset = 10, width = 1; //offset = 2; // offset - отступ от центра крестика
};

#endif // POINT_H
