#ifndef MULTICOMMAND_H
#define MULTICOMMAND_H

#include "command.h"

#include <QVector>

class MultiCommand : public Command
{
private:
    QVector<Command*> commands;
public:
    MultiCommand();
    MultiCommand(MultiCommand* com);
    MultiCommand(MultiCommand&& com);
    void execute(Figure *fig) override;
    void addCommand(Command*);
    int commandCount() const;
    QString description() override;
    ~MultiCommand();

    Command *copy() override;
};

#endif // MULTICOMMAND_H
