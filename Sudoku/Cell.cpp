#include "Cell.h"

Cell::Cell() : value(0), fixed(false) {}

int Cell::getValue() const
{
    return value;
}

void Cell::setValue(int val)
{
    value = val;
}

bool Cell::isFixed() const
{
    return fixed;
}

void Cell::setFixed(bool fix)
{
    fixed = fix;
}
