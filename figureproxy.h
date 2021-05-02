#ifndef FIGUREPROXY_H
#define FIGUREPROXY_H

#include "figure.h"
#include "mainwindow.h"


class FigureProxy
{
private:
    Figure* figure;
    static MainWindow* window;
public:
    FigureProxy(Figure* fig);

    void reciveCommand(Command *commmand, int x=0, int y=0);
    static void setWindow(MainWindow *value);
};

#endif // FIGUREPROXY_H
