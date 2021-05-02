#include "resizecommand.h"
#include "figure.h"

void ResizeCommand::execute(Figure *fig)
{
    fig->setRadius(radius);
}

QString ResizeCommand::description()
{
    return "Изменение размера фигуры";
}

Command *ResizeCommand::copy()
{
    return new ResizeCommand(radius);
}
