#include "changepencolorcommand.h"
#include "figure.h"

void ChangePenColorCommand::execute(Figure *fig)
{
    fig->getPen()->setColor(color);
}

QString ChangePenColorCommand::description()
{
    return "Изменение цвета обводки";
}

Command *ChangePenColorCommand::copy()
{
    return new ChangePenColorCommand(color);
}
