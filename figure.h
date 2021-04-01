#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#ifndef COMMAND_H
#include "command.h"
#endif
#include "figtype.h"

class Figure : public QGraphicsItem
{

protected:
    int x, y, radius;
    QBrush *brush;
    QPen *pen;
    FigType ft;

    void setX(int value);
    void setY(int value);
    void setRadius(int value);
    void setBrush(QBrush *value);
    void setPen(QPen *value);
    void setType(const FigType &value);
public:
    Figure(QGraphicsItem *parent=nullptr);
    Figure(Figure &fig);
    Figure(Figure &&fig);
    ~Figure();

    int getX() const;
    int getY() const;
    int getRadius() const;
    FigType getFType() const;

    void reciveCommand(Command *commmand);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    friend class MoveCommand;
    friend class ResizeCommand;
    friend class ChangeMainColorCommand;
    friend class ChangePenColorCommand;
    friend class ChangePenSozeCommand;
    friend class ChangeTypeCommand;
};

#endif // FIGURE_H
