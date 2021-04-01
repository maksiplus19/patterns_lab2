#ifndef QCUSTOMGRAPHICVIEW_H
#define QCUSTOMGRAPHICVIEW_H

#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include "figure.h"

class QCustomGraphicView : public QGraphicsView
{
private:
    QGraphicsScene *inner_scene;
    MainWindow *window;

    int getType(QGraphicsItem* item);

    Figure *fig;
    bool isPressed;
public:
    QCustomGraphicView(MainWindow *parent=nullptr);

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // QCUSTOMGRAPHICVIEW_H
