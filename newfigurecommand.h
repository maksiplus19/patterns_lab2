#ifndef NEWFIGURECOMMAND_H
#define NEWFIGURECOMMAND_H

#include "command.h"

class NewFigureCommand : public Command
{
public:
    NewFigureCommand() = default;
    void execute(Figure *fig){};
    Command *copy() override;
    QString description() override;
};

#endif // NEWFIGURECOMMAND_H
