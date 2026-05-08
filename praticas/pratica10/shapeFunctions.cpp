#include "shapeFunctions.hpp"

#include <algorithm>
#include <map>


void ShapeFunctions::printShapes(const std::vector<Shape*>& shapes){
    for (const auto& s : shapes){
        std::cout << *s << std::endl;
    }
}
double ShapeFunctions::totalArea(const std::vector<Shape*>& shapes) {
    double sum = 0.0;

    for (const auto& s : shapes){
        sum += s->area();
    }

    return sum;
}

std::vector<Shape*> ShapeFunctions::getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea){
    std::vector<Shape*> arrayFiltered = {};

    for (const auto& s : shapes){
        if (s->area() > minArea) 
            arrayFiltered.push_back(s);
    }
    return arrayFiltered;
}


void ShapeFunctions::sortShapesByArea(std::vector<Shape*>& shapes){
   
    std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b){
        return a->area() < b->area();
    });

}

std::map<std::string, int> ShapeFunctions::countShapesByName(const std::vector<Shape*>& shapes){
    std::map<std::string, int> mapCoutingShapes = {};
    
    for (const auto& s : shapes){
        if (mapCoutingShapes.find(s->name()) == mapCoutingShapes.end()){
            mapCoutingShapes.insert(std::pair<std::string, int>(s->name(), 0));
        }
        mapCoutingShapes[s->name()]++;
    }
    return mapCoutingShapes;
}

std::set<double> ShapeFunctions::uniqueAreas(const std::vector<Shape*>& shapes){
    std::set<double> tempSet = {};

    for (const auto& s : shapes){
        tempSet.insert(s->area());
    }

    return tempSet;
}

void ShapeFunctions::verificarTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia){
    double tempTotalArea = ShapeFunctions::totalArea(shapes);
    double area_livre = area_ambiente - tempTotalArea;

    if (area_livre > tolerancia){
        std::cout << "Ambiente trafegavel. Area livre: " << area_livre << std::endl;
    }
    else {
        std::cout << "Ambiente nao trafegavel. Area livre insuficiente: " << area_livre << std::endl;
    }
}
