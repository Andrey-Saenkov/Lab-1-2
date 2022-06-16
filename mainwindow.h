#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <point.h>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    //Point points[10];
    QVector<Point> points;
    Point p;
    //int movingPointInd = -1;
    Point hitPoint;
};
#endif // MAINWINDOW_H
