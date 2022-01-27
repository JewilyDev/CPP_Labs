#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class Ball;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void update();

private:
    Ui::MainWindow *ui;
    Ball *bim = nullptr;
};

#endif // MAINWINDOW_H
