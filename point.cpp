#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y){
    this -> x = x;
    this -> y = y;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::drawPoint(QPainter *painter)
{
    qDebug("drawPoint x = %d, y = %d", x, y);
    QPen mypen = painter->pen();
    mypen.setWidth(width);
    painter->setPen(mypen);
    painter->drawLine(x - offset, y - offset, x + offset, y + offset);// это из mainwindow
    painter->drawLine(x - offset, y + offset, x + offset, y - offset);// это из mainwindow

}


void Point::setOffset(int newOffset)
{
    offset = newOffset;
}

void Point::setCoords(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::setX(int x)
{
    this->x = x;
}

double Point::distance2(int x0, int y0)
{
    //qDebug("%d %d, %d %d", x0, y0, x, y);
    int dx = x0 - x;
    int dy = y0 - y;
    return (dx * dx) + (dy * dy);
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}

int Point::getOffset() const
{
    return offset;
}
