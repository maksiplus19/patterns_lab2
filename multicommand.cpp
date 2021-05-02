#include "multicommand.h"

MultiCommand::MultiCommand()
{

}


MultiCommand::MultiCommand(MultiCommand &&com)
{
    commands = QVector<Command*>(com.commandCount());
    for (int i = 0; i < com.commandCount(); i++){
        std::swap(commands[i], com.commands[i]);
    }
}

void MultiCommand::execute(Figure *fig)
{
    foreach(auto c, commands) c->execute(fig);
}

void MultiCommand::addCommand(Command *c)
{
    commands.push_back(c);
}

int MultiCommand::commandCount() const
{
    return commands.size();
}

QString MultiCommand::description()
{
    return "Мультикоманда";
}

MultiCommand::~MultiCommand()
{
    foreach(auto c, commands) {
        if (c != nullptr)
            delete c;
    }
}

Command *MultiCommand::copy()
{
    auto cop = new MultiCommand;
    foreach(auto c,  commands){
        cop->addCommand(c->copy());
    }
    return cop;
}
