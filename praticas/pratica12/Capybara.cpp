#include "Capybara.h"

Capybara::Capybara(int x, int y)
    : Organism(x, y) {}

char Capybara::symbol() const{ return 'C'; }

bool Capybara::isPreyFor(const Organism* predator) const{
    if (predator->symbol() == 'O') return true;
    return false;
}

void Capybara::move(Grid& grid){
    if (this->hasMoved() != true)
        this->setMoved(this->tryMoveToEmpty(grid));
}