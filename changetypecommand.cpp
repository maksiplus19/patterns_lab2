#include "changetypecommand.h"
#include "figure.h"

void ChangeTypeCommand::execute(Figure *fig)
{
    fig->setType(type);
}

QString ChangeTypeCommand::description()
{
    return "Изменение типа фигуры";
}

Command *ChangeTypeCommand::copy()
{
    return new ChangeTypeCommand(type);
}
