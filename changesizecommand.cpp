#include "changesizecommand.h"

ChangeSizeCommand::ChangeSizeCommand(Figure *fig, int _oldSize): Command(fig), oldSize(_oldSize) {}

void ChangeSizeCommand::undo()
{
    figure->setRadius(oldSize);
}
