#pragma once
#include <string>

struct Item {
    std::string nome;
    int quantidade;
    Item(const std::string& nome, int quantidade) : nome(nome), quantidade(quantidade) {}
};
