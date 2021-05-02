#include "changepensizecommand.h"

#include "figure.h"

void ChangePenSizeCommand::execute(Figure *fig)
{
    fig->getPen()->setWidth(size);
}

QString ChangePenSizeCommand::description()
{
    return "Изменение размера обводки";
}

Command* ChangePenSizeCommand::copy()
{
    return new ChangePenSizeCommand(size);
}
