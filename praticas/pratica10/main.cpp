#include "shapeFunctions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ios>
#include <unordered_map>

// g++ -std=c++11 main.cpp circle.cpp rectangle.cpp triangle.cpp shapeFunctions.cpp -o main

enum class CommandsEnum{
        CIRCLE,
        RECT,
        TRIANGLE,
        LIST,
        TOTAL,
        SORT,
        FILTER,
        COUNT,
        UNIQUE,
        CLEAR,
        TRAVERSABLE,
        DEFAULT
};

bool executeCommand(std::string mainCommand, std::vector<double> arguments,  std::vector<Shape*>& shapes){

    static const std::unordered_map<std::string, CommandsEnum> stringToEnumMap = {
        {"CIRCLE", CommandsEnum::CIRCLE},
        {"RECT", CommandsEnum::RECT},
        {"TRIANGLE", CommandsEnum::TRIANGLE},
        {"LIST", CommandsEnum::LIST},
        {"TOTAL", CommandsEnum::TOTAL},
        {"SORT", CommandsEnum::SORT},
        {"FILTER", CommandsEnum::FILTER},
        {"COUNT", CommandsEnum::COUNT},
        {"UNIQUE", CommandsEnum::UNIQUE},
        {"CLEAR", CommandsEnum::CLEAR},
        {"TRAVERSABLE", CommandsEnum::TRAVERSABLE}
    };

    CommandsEnum toBeExecuted;

    auto it = stringToEnumMap.find(mainCommand);
    if (it != stringToEnumMap.end()) toBeExecuted = it->second;
    else toBeExecuted = CommandsEnum::DEFAULT;


    switch (toBeExecuted) {
        case CommandsEnum::CIRCLE:{
            Circle* circle = new Circle(arguments[0]);
            shapes.push_back(circle);
            break;
        }
            
        case CommandsEnum::RECT:{
            Rectangle* rect = new Rectangle(arguments[0], arguments[1]);
            shapes.push_back(rect);
            break;
        }
        case CommandsEnum::TRIANGLE:{
            Triangle* tri = new Triangle(arguments[0], arguments[1], arguments[2]);
            shapes.push_back(tri);
            break;
        }
    
        case CommandsEnum::LIST:{
            ShapeFunctions::printShapes(shapes);
            break;
        }
    
        case CommandsEnum::TOTAL:{
            double sum = ShapeFunctions::totalArea(shapes);
            std::cout << "Total: " << sum << std::endl;
            break;
        }
    
        case CommandsEnum::SORT:{
            ShapeFunctions::sortShapesByArea(shapes);
            ShapeFunctions::printShapes(shapes);
            break;
        }
            
        case CommandsEnum::FILTER:{
           std::vector<Shape*> filteredShapes = ShapeFunctions::getShapesWithAreaGreaterThan(shapes, arguments[0]);
           ShapeFunctions::printShapes(filteredShapes);
            break;
        }
    
        case CommandsEnum::COUNT:{
            std::map<std::string, int> coutedShapes = ShapeFunctions::countShapesByName(shapes);
            for (auto s : coutedShapes){
                std::cout << s.first << ":" << s.second << std::endl;
            }
            break;
        }
    
        case CommandsEnum::UNIQUE:{
            std::set<double> uniqueAreaShapes = ShapeFunctions::uniqueAreas(shapes);
            for (auto it = uniqueAreaShapes.begin(); it != std::prev(uniqueAreaShapes.end()); it++){
                std::cout << *it << " ";
            }
            std::cout << *std::prev(uniqueAreaShapes.end()) << std::endl;
            break;
        }
            
        case CommandsEnum::CLEAR:{
            for (auto s : shapes){
                delete s;
            }
            shapes.clear();
            break;
        }
            
        case CommandsEnum::TRAVERSABLE:{
            
            ShapeFunctions::verificarTraversable(shapes, arguments[0], arguments[1]);
            break;
        }

        case CommandsEnum::DEFAULT:
        default: 
            for (auto s : shapes){
                delete s;
            }
            shapes.clear();
            return false;
        
        
        
        
    }
    

    return true;
}


int main()
{
    std::cout << std::fixed << std::setprecision(2);
    
    bool done = false;
    std::vector<Shape*> shapes;

    while (!done){

        std::string string_input;

        if (!std::getline(std::cin, string_input)) {
            break; 
        }

        std::stringstream stream_input(string_input);

        std::string mainCommand;
        if (!(stream_input >> mainCommand)) {
            continue;
        } 

        std::vector<double> arguments = {};
        double tempArgument = 0;
        while ((stream_input >> tempArgument)){
            arguments.push_back(tempArgument);
        }

        //std::cout << mainCommand << std::endl;
        
        // for (const auto& t : arguments){
        //     std::cout << t << std::endl;
        // }
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!executeCommand(mainCommand, arguments, shapes))
            done = true;

    }
    return 0;
}
