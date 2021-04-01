#include "figure.h"
#include <QtMath>

Figure::Figure(QGraphicsItem *parent): QGraphicsItem(parent) {}

Figure::Figure(Figure &fig)
{
    x = fig.x;
    y = fig.y;
    radius = fig.radius;

    brush = new QBrush(*fig.brush);
    pen = new QPen(*fig.pen);
}

Figure::Figure(Figure &&fig)
{
    x = fig.x;
    y = fig.y;
    radius = fig.radius;

    delete brush;
    delete pen;
    brush = fig.brush;
    pen = fig.pen;
    fig.brush = nullptr;
    fig.pen = nullptr;
}

Figure::~Figure()
{
    delete brush;
    delete pen;
}

FigType Figure::getFType() const
{
    return ft;
}

void Figure::reciveCommand(Command *commmand)
{
    commmand->execute(this);
}

void Figure::setType(const FigType &value)
{
    this->ft = value;
}

int Figure::getX() const
{
    return x;
}

void Figure::setX(int value)
{
    x = value;
}

int Figure::getY() const
{
    return y;
}

void Figure::setY(int value)
{
    y = value;
}

int Figure::getRadius() const
{
    return radius;
}

void Figure::setRadius(int value)
{
    radius = value;
}

void Figure::setBrush(QBrush *value)
{
    brush = value;
}

void Figure::setPen(QPen *value)
{
    pen = value;
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(*pen);
    painter->setBrush(*brush);
    switch (this->ft) {
    case FigType::Circle:
        painter->drawEllipse(x-radius, y-radius, 2*radius, 2*radius);
        break;
    case FigType::Triangle: {
        QVector<QPoint> l = {QPoint(x, y-radius), QPoint(x+radius*cos(7./6 * M_PI), y+radius/2), QPoint(x+radius*cos(11./6 * M_PI), y+radius/2)};
        painter->drawPolygon(l);
        break;
    }
    case FigType::Square:
        painter->drawRect(x-radius, y-radius, 2*radius, 2*radius);
        break;
    case FigType::Pentagon: {
        QVector<QPoint> l{
                    QPoint(x+radius*cos(M_PI/10), y+radius*sin(M_PI/10)),
                    QPoint(x+radius*cos(M_PI/2), y + radius*sin(M_PI/2)),
                    QPoint(x+radius*cos(9*M_PI/10), y+radius*sin(9*M_PI/10)),
                    QPoint(x+radius*cos(13*M_PI/10), y+radius*sin(13*M_PI/10)),
                    QPoint(x+radius*cos(17*M_PI/10), y+radius*sin(17*M_PI/10))
        };
        painter->drawPolygon(l);
        break;
    }
    case FigType::Hexagon: {
        QVector<QPoint> l{
                    QPoint(x+radius, y),
                    QPoint(x+radius*cos(M_PI/3), y+radius*sin(M_PI/3)),
                    QPoint(x+radius*cos(2*M_PI/3), y + radius*sin(2*M_PI/3)),
                    QPoint(x-radius, y),
                    QPoint(x+radius*cos(4*M_PI/3), y+radius*sin(4*M_PI/3)),
                    QPoint(x+radius*cos(5*M_PI/3), y+radius*sin(5*M_PI/3))
        };
        painter->drawPolygon(l);
        break;
    }
    }
}

QRectF Figure::boundingRect() const
{
    QPointF lTop = mapToScene(x-radius, y-radius), rBottom = mapToScene(x+radius, y+radius);
    return QRectF(lTop, rBottom);
}
