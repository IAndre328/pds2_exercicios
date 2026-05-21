#include "Organism.h"
#include "Grid.h"

Organism::Organism(int x, int y) 
    : x{x}, y{y}, moved{false} {}

bool Organism::tryMoveToEmpty(Grid& grid){
    Organism* org = this;

    if (grid.isEmpty(this->getX() - 1, this->getY())) {   // cima
    grid.clear(this->getX(), this->getY());
    grid.set(this->getX() - 1, this->getY(), this);
    return true;    
    }

    if (grid.isEmpty(this->getX(), this->getY() + 1)) {   // direita
        grid.clear(this->getX(), this->getY());
        grid.set(this->getX(), this->getY() + 1, this);
        return true;
    }
    if (grid.isEmpty(this->getX() + 1, this->getY())) {   // baixo
        grid.clear(this->getX(), this->getY());
        grid.set(this->getX() + 1, this->getY(), this);
        return true;
    }
    if (grid.isEmpty(this->getX(), this->getY() - 1)) {   // esquerda
        grid.clear(this->getX(), this->getY());
        grid.set(this->getX(), this->getY() - 1, this);
        return true;
    }

    

    return false;
}

bool Organism::tryPredation(Grid& grid) { return false; }
bool Organism::isPreyFor(const Organism* predator) const { return false; }

void Organism::setMoved(bool m){ this->moved = m; }
bool Organism::hasMoved() const{ return this->moved; }

int Organism::getX() const{ return this->x; }
int Organism::getY() const{ return this->y; }
void Organism::setPosition(int nx, int ny){
    this->x = nx;
    this->y = ny;
}