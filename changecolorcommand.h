#ifndef CHANGECOLORCOMMAND_H
#define CHANGECOLORCOMMAND_H

#include "command.h"

#include <QColor>

class ChangeMainColorCommand: public Command
{
private:
    QColor color;
public:
    ChangeMainColorCommand(QColor _color): color(_color){};
    void execute(Figure *fig) override;
    QString description() override;
    Command *copy() override;
};

#endif // CHANGECOLORCOMMAND_H
