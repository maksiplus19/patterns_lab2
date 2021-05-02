#ifndef CHANGEPENSIZECOMMAND_H
#define CHANGEPENSIZECOMMAND_H

#include "command.h"

class ChangePenSizeCommand: public Command
{
private:
    int size;
public:
    ChangePenSizeCommand(int _size): size(_size){};
    void execute(Figure *fig) override;
    QString description() override;
    Command *copy() override;
};

#endif // CHANGEPENSIZECOMMAND_H
