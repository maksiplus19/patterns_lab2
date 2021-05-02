#include "newfigurecommand.h"
#include "figure.h"

//void NewFigureCommand::execute(Figure *fig)
//{
//    fig->setX(x);
//    fig->setY(y);
//}

Command *NewFigureCommand::copy()
{
    return new NewFigureCommand;
}

QString NewFigureCommand::description()
{
    return "Новая фигура";
}
