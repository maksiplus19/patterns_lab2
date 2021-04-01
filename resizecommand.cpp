#include "resizecommand.h"
#include "figure.h"

void ResizeCommand::execute(Figure *fig)
{
    fig->setRadius(radius);
}
