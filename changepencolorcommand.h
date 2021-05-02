#ifndef CHANGEPENCOLORCOMMAND_H
#define CHANGEPENCOLORCOMMAND_H

#include "command.h"

#include <QColor>

class ChangePenColorCommand : public Command
{
private:
    QColor color;
public:
    ChangePenColorCommand(QColor _color): color(_color){};
    void execute(Figure *fig) override;
    QString description() override;
    Command* copy() override;
};

#endif // CHANGEPENCOLORCOMMAND_H
