#include "mainwindow.h"                                                                                                                                                                                                   #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent> // мы его подключаем, потому что используем его внутренности

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
   QPainter painter(this);
   qDebug("paintEvent size = %d", points.size());
   for (int g = 0; g < points.size(); g++){
       points[g].drawPoint(&painter);
       if (g != points.size() - 1){
           painter.drawLine(points[g].getX(),points[g].getY(),points[g + 1].getX(),points[g + 1].getY());
       }
   }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    bool hit = false;
    int g = 0;
    for (; g < points.size(); g++){
        if (points[g].distance2(event->pos().x(), event->pos().y()) < 144){
            hit = true;
            break;
        }
    }
    if (hit){
       hitPoint = Point(event->pos().x(), event->pos().y());
    }
    else{
        qDebug("Добавить");
        points.append(Point(event->pos().x(), event->pos().y()));
        qDebug("points = %f %f %d %d",points);
    }
    repaint();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)//event-> x(), event-> y()
{

}
