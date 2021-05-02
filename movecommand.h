#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "command.h"

class MoveCommand : public Command
{
private:
    int x, y;
public:
    MoveCommand(int _x, int _y): x(_x), y(_y){};
    void execute(Figure* fig) override;
    Command *copy() override;
    QString description() override;
};

#endif // MOVECOMMAND_H
