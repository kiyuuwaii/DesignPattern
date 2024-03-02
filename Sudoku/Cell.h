#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int value;
    bool fixed;

public:
    Cell();
    int getValue() const;
    void setValue(int val);
    bool isFixed() const;
    void setFixed(bool fix);
};

#endif
