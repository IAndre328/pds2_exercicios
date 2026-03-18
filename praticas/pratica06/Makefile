CFLAGS=-std=c++11 -Wall
SRC_DIR=src
SRC_DIR_AUX=src/entidades
INCLUDE_DIR=include
OBJ_DIR=build

all: vpl_execution

$(OBJ_DIR)/Ponto.o: $(SRC_DIR_AUX)/Ponto.cpp $(INCLUDE_DIR)/Ponto.hpp
	g++ $(CFLAGS) -c ${SRC_DIR_AUX}/Ponto.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Ponto.o

$(OBJ_DIR)/Circulo.o: $(SRC_DIR_AUX)/Circulo.cpp $(INCLUDE_DIR)/Circulo.hpp
	g++ $(CFLAGS) -c ${SRC_DIR_AUX}/Circulo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Circulo.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Circulo.hpp $(SRC_DIR)/main.cpp
	g++ $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

vpl_execution: ${OBJ_DIR}/main.o ${OBJ_DIR}/Circulo.o $(OBJ_DIR)/Ponto.o
	g++ $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/Circulo.o $(OBJ_DIR)/Ponto.o -o vpl_execution

clear:
	rm -f build/*.o
	rm -f vpl_execution