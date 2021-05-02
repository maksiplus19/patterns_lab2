#include "changecolorcommand.h"
#include "figure.h"

void ChangeMainColorCommand::execute(Figure *fig)
{
    fig->getBrush()->setColor(color);
}

QString ChangeMainColorCommand::description()
{
    return "Изменение основного цвета";
}

Command* ChangeMainColorCommand::copy()
{
    return new ChangeMainColorCommand(color);
}
