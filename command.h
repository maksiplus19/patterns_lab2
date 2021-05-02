#ifndef COMMAND_H
#define COMMAND_H

#ifdef FIGURE_H
#include "figure.h"
#endif

#include <QString>

class Figure;

class Command
{
public:
    virtual void execute(Figure* fig) = 0;
    virtual QString description() = 0;
    virtual Command* copy() = 0;
    virtual ~Command() = default;
};

#endif // COMMAND_H
