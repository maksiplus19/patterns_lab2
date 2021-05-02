#include "memento.h"
#include "figure.h"

Memento::Memento(Figure *ptr, Figure *state)
{
    figurePtr = ptr;
    figureState = state;
}

void Memento::restore()
{
    figurePtr->restore(figureState);
    delete figureState;
}
