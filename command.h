#ifndef COMMAND_H
#define COMMAND_H

#ifdef FIGURE_H
#include "figure.h"
#endif

class Figure;

class Command
{
public:
    virtual void execute(Figure* fig) = 0;
};

#endif // COMMAND_H
