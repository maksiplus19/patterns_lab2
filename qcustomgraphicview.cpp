#include "figdialog.h"
#include "figureproxy.h"
#include "multicommand.h"
#include "qcustomgraphicview.h"
#include <QBrush>
#include <QPen>


QCustomGraphicView::QCustomGraphicView(QWidget *parent): QGraphicsView(parent){
    window = static_cast<MainWindow*>(parent);
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
        auto figp = FigureProxy(fig);
        figp.reciveCommand(new NewFigureCommand());
        inner_scene->addItem(fig);
        this->scene()->update(this->sceneRect());
        this->repaint();
    } else {
        auto i = static_cast<Figure*>(item);
        auto *d = new FigDialog(i);
//        Command* command;
        MultiCommand* command = new MultiCommand();
        bool edited = false;
        if (d->exec() == QDialog::Accepted) {
            if (i->getFType() != d->getType()){
                command->addCommand(new ChangeTypeCommand(d->getType()));
                edited = true;
            }
            if (i->getRadius() != d->getRadius()){
                command->addCommand(new ResizeCommand(d->getRadius()));
                edited = true;
            }
            if (i->getBrush()->color() != d->getBrushColor()){
                command->addCommand(new ChangeMainColorCommand(d->getBrushColor()));
                edited = true;
            }
            if (i->getPen()->color() != d->getPenColor()){
                command->addCommand(new ChangePenColorCommand(d->getPenColor()));
                edited = true;
            }
            if (i->getPen()->width() != d->getPenSize()){
                command->addCommand(new ChangePenSizeCommand(d->getPenSize()));
                edited = true;
            }
            if (edited){
                auto f = FigureProxy(i);
                f.reciveCommand(command);
            }

//            i->setType(d->getType());
//            i->setRadius(d->getRadius());
//            i->setBrush(new QBrush(d->getBrushColor()));
//            i->setPen(new QPen(QBrush(d->getPenColor()), d->getPenSize()));
        }
        delete d;
    }
}

void QCustomGraphicView::mousePressEvent(QMouseEvent *event)
{
    auto pos = mapToScene(event->pos());
    auto item = inner_scene->itemAt(pos, QTransform());
    if (item != nullptr){
        isPressed = true;
        fig = static_cast<Figure*>(item);
        saveX = pos.x();
        saveY = pos.y();
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
        isMoved = true;
    }
}

void QCustomGraphicView::mouseReleaseEvent(QMouseEvent *event)
{
    if (isPressed && fig != nullptr && isMoved){
            auto pos = mapToScene(event->pos());
            auto f = FigureProxy(fig);
            f.reciveCommand(new MoveCommand(pos.x(), pos.y()), saveX, saveY);
//            fig->setX(pos.x());
//            fig->setY(pos.y());
            this->scene()->update(this->sceneRect());
            this->repaint();
            isMoved = false;
    }
    isPressed = false;
}

Figure *QCustomGraphicView::getLastFigure()
{
    return fig;
}
