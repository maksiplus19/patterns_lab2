#ifndef MEMENTO_H
#define MEMENTO_H


//#include "headers.h"

class Figure;

class Memento
{
private:
    Figure* figurePtr;
    Figure* figureState;
public:
    Memento() = default;
    Memento(Figure* ptr, Figure *state);
    void restore();

    friend class FigureProxy;
};

#endif // MEMENTO_H
