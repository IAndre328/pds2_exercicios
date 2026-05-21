#include "Jaguar.h"
#include "Grid.h"


Jaguar::Jaguar(int x, int y)
    : Organism(x, y) {}

char Jaguar::symbol() const{ return 'O'; }

bool Jaguar::tryPredation(Grid& grid) {
    // Cima: x - 1
    if (grid.inBounds(this->getX() - 1, this->getY()) && !grid.isEmpty(this->getX() - 1, this->getY())) {
        Organism* org = grid.get(this->getX() - 1, this->getY());
        if (org != nullptr && org->symbol() == 'C') {
            grid.remove(this->getX() - 1, this->getY());
            grid.clear(this->getX(), this->getY());
            grid.set(this->getX() - 1, this->getY(), this);
            this->setMoved(true);
            return true;
        }
    }

    // Direita: y + 1
    if (grid.inBounds(this->getX(), this->getY() + 1) && !grid.isEmpty(this->getX(), this->getY() + 1)) {
        Organism* org = grid.get(this->getX(), this->getY() + 1);
        if (org != nullptr && org->symbol() == 'C') {
            grid.remove(this->getX(), this->getY() + 1);
            grid.clear(this->getX(), this->getY());
            grid.set(this->getX(), this->getY() + 1, this);
            this->setMoved(true);
            return true;
        }
    }

    // Baixo: x + 1
    if (grid.inBounds(this->getX() + 1, this->getY()) && !grid.isEmpty(this->getX() + 1, this->getY())) {
        Organism* org = grid.get(this->getX() + 1, this->getY());
        if (org != nullptr && org->symbol() == 'C') {
            grid.remove(this->getX() + 1, this->getY());
            grid.clear(this->getX(), this->getY());
            grid.set(this->getX() + 1, this->getY(), this);
            this->setMoved(true);
            return true;
        }
    }

    // Esquerda: y - 1
    if (grid.inBounds(this->getX(), this->getY() - 1) && !grid.isEmpty(this->getX(), this->getY() - 1)) {
        Organism* org = grid.get(this->getX(), this->getY() - 1);
        if (org != nullptr && org->symbol() == 'C') {
            grid.remove(this->getX(), this->getY() - 1);
            grid.clear(this->getX(), this->getY());
            grid.set(this->getX(), this->getY() - 1, this);
            this->setMoved(true);
            return true;
        }
    }

    return false;
}

void Jaguar::move(Grid &grid) {
    if (this->hasMoved() != true) {
        if (this->tryPredation(grid) == true)
            this->setMoved(true);
    
        else if (this->tryMoveToEmpty(grid) == true)
            this->setMoved(true);
    }
}