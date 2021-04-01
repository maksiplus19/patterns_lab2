#include "figdialog.h"
#include "qcustomgraphicview.h"


QCustomGraphicView::QCustomGraphicView(MainWindow *parent): QGraphicsView(parent){
    window = parent;
    inner_scene = new QGraphicsScene(x(), y(), 1000, 1000, this);
    setScene(inner_scene);
};

void QCustomGraphicView::mouseDoubleClickEvent(QMouseEvent *event)
{
    auto pos = mapToScene(event->pos());

    auto item = inner_scene->itemAt(pos, QTransform());
    if (item == nullptr) {
        Figure* fig = window->newFigure();
        fig->setX(pos.x());
        fig->setY(pos.y());
        inner_scene->addItem(fig);
        this->scene()->update(this->sceneRect());
        this->repaint();
    } else {
        auto i = static_cast<Figure*>(item);
        auto *d = new FigDialog(i->getFType());
        if (d->exec() == QDialog::Accepted) {
            i->setType(d->getType());
            i->setRadius(d->getRadius());
            i->setBrush(new QBrush(d->getBrushColor()));
            i->setPen(new QPen(QBrush(d->getPenColor()), d->getPenSize()));
        }
        delete d;
    }
}

void QCustomGraphicView::mousePressEvent(QMouseEvent *event)
{
    auto item = inner_scene->itemAt(mapToScene(event->pos()), QTransform());
    if (item != nullptr){
        isPressed = true;
        fig = static_cast<Figure*>(item);
    }
}

void QCustomGraphicView::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressed){
        auto pos = mapToScene(event->pos());
        fig->setX(pos.x());
        fig->setY(pos.y());
        this->scene()->update(this->sceneRect());
        this->repaint();
    }
}

void QCustomGraphicView::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed = false;
}
