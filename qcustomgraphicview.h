#ifndef QCUSTOMGRAPHICVIEW_H
#define QCUSTOMGRAPHICVIEW_H

#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include "commands.h"
#include "headers.h"

class MainWindow;

class QCustomGraphicView : public QGraphicsView
{
private:
    QGraphicsScene *inner_scene;
    MainWindow *window;

    int getType(QGraphicsItem* item);

    Figure *fig = nullptr;
    bool isPressed, isMoved = false;
    int saveX, saveY;
public:
    QCustomGraphicView(QWidget *parent=nullptr);

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    Figure* getLastFigure();
};

#endif // QCUSTOMGRAPHICVIEW_H
