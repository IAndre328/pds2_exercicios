#ifndef GRID_H
#define GRID_H

#include <vector>
#include <ostream>
#include "Organism.h"

class Grid {
private:
    int rows, cols;
    std::vector<std::vector<Organism*>> cells;

public:
    Grid(int r, int c);
    ~Grid();
    
    bool inBounds(int x, int y) const;
    bool isEmpty(int x, int y) const;

    Organism* get(int x, int y) const;
    void set(int x, int y, Organism* o);
    void set(Organism* o);
    void clear(int x, int y);
    void remove(int x, int y);

    int getRows() const;
    int getCols() const;

    void resetMoved();
    friend std::ostream& operator<<(std::ostream& os, const Grid& g);

    void simulateRound(char orgType);
};

#endif