#ifndef RESIZECOMMAND_H
#define RESIZECOMMAND_H

#include "command.h"

class ResizeCommand : public Command
{
private:
    int radius;
public:
    ResizeCommand(int _radius): radius(_radius){};
    void execute(Figure *fig) override;
    QString description() override;
    Command *copy() override;
};

#endif // RESIZECOMMAND_H
