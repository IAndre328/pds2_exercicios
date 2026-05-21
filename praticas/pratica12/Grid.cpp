#include "Grid.h"

Grid::Grid(int r, int c) :
    rows{r}, cols{c}, cells(r, std::vector<Organism*>(c, nullptr)) {}

Grid::~Grid(){
    Organism* org = nullptr;
    for (auto itRow = this->cells.begin(); itRow != cells.end(); itRow++){
        for (auto itCol = itRow->begin(); itCol != itRow->end(); itCol++){
            org = *itCol;
            if (org != nullptr)
                delete org;
        }
    }
}

bool Grid::inBounds(int x, int y) const{
    if (x < 0 || y < 0) return false;
    if (x > this->getRows() - 1) return false;
    if (y > this->getCols() - 1) return false;
    return true;
}

bool Grid::isEmpty(int x, int y) const{
    if (!this->inBounds(x, y)) return false;
    if (this->cells[x][y] != nullptr) return false;
    return true;

}

Organism* Grid::get(int x, int y) const{
    if (this->inBounds(x, y)) {
        return this->cells[x][y];
    }
    return nullptr;
}

void Grid::set(int x, int y, Organism* o){
    if (this->inBounds(x, y)){
        this->cells[x][y] = o;
        if (o != nullptr) {
            o->setPosition(x, y);
        }
    }
}

void Grid::set(Organism* o){
    if (this->inBounds(o->getX(), o->getY())) {
        this->cells[o->getX()][o->getY()] = o;
    }
}

void Grid::clear(int x, int y){
    if (this->inBounds(x, y) == true){
        this->cells[x][y] = nullptr;
    }
}

void Grid::remove(int x, int y){
    if (this->inBounds(x, y) == true && this->cells[x][y] != nullptr){
        delete this->cells[x][y];
        this->cells[x][y] = nullptr;
    }
}

int Grid::getRows() const{
    return this->rows;
}

int Grid::getCols() const{
    return this->cols;
}

void Grid::resetMoved(){
    Organism* org = nullptr;
    for (auto itRow = this->cells.begin(); itRow != cells.end(); itRow++){
        for (auto itCol = itRow->begin(); itCol != itRow->end(); itCol++){
            org = *itCol;
            if (org != nullptr){
                org->setMoved(false);
            }
                
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Grid& g){
    for (auto itRow = g.cells.begin(); itRow != g.cells.end(); itRow++){
        for (auto itCol = itRow->begin(); itCol != itRow->end(); itCol++){
            Organism* org = *itCol;
            os << (org != nullptr ? org->symbol() : '.');
        }
        os << "\n";
    }
    return os;
}


void Grid::simulateRound(char orgType){
    std::vector<Organism*> toAct;
    for (auto& row : this->cells)
        for (auto* org : row)
            if (org != nullptr && org->symbol() == orgType)
                toAct.push_back(org);

    for (auto* org : toAct)
        if (!org->hasMoved())
            org->move(*this);
}