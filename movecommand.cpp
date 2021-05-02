#include "movecommand.h"
#include "figure.h"


void MoveCommand::execute(Figure *fig)
{
    fig->setX(x);
    fig->setY(y);
}

Command *MoveCommand::copy()
{
    return new MoveCommand(x, y);
}

QString MoveCommand::description()
{
    return "Перемещение фигуры";
}
