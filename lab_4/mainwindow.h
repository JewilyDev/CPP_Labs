#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>

#include <vector>

#include "rect.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Rect> arRect;
    static void colorSort(std::vector<Rect> &rects);
    static std::vector<QColor> arColors;
    int initialX = 0;
    int initialY = 0;
};
#endif // MAINWINDOW_H
