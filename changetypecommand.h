#ifndef CHANGETYPECOMMAND_H
#define CHANGETYPECOMMAND_H

#include "figtype.h"
#include "command.h"

class ChangeTypeCommand: public Command
{
private:
    FigType type;
public:
    ChangeTypeCommand(FigType _type): type(_type){};
    void execute(Figure *fig) override;
    QString description() override;
    Command *copy() override;
    virtual ~ChangeTypeCommand() = default;
};

#endif // CHANGETYPECOMMAND_H
