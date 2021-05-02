#include "figureproxy.h"

MainWindow* FigureProxy::window;

void FigureProxy::setWindow(MainWindow *value)
{
    FigureProxy::window = value;
}

FigureProxy::FigureProxy(Figure *fig)
{
    figure = fig;
}

void FigureProxy::reciveCommand(Command *commmand, int x, int y)
{
    auto mem = figure->createMemento();
    if (x != 0 || y != 0) {
        mem.figureState->setX(x);
        mem.figureState->setY(y);
    }
    window->addMemory(commmand->description(), mem);
    figure->reciveCommand(commmand);
}
