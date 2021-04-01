#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Figure* newFigure();

private slots:
    void on_brushColorButton_clicked();

    void on_penColorButton_clicked();

private:
    QColor penColor, brushColor;
    Ui::MainWindow *ui;
//    FigureFactory *factory;
};
#endif // MAINWINDOW_H
