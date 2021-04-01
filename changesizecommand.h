#ifndef CHANGESIZECOMMAND_H
#define CHANGESIZECOMMAND_H

#include "command.h"

class ChangeSizeCommand : public Command
{
private:
    int oldSize;
public:
    ChangeSizeCommand(Figure *fig, int oldSize);
    void undo() override;
};

#endif // CHANGESIZECOMMAND_H
