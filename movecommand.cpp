#include "movecommand.h"
#include "figure.h"


void MoveCommand::execute(Figure *fig)
{
    fig->setX(x);
    fig->setY(y);
}
