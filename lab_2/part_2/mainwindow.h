#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "point.h"
#include <QMainWindow>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    std::vector <Point*> arPoints;

};
#endif // MAINWINDOW_H
