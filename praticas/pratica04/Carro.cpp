#include "Carro.hpp"
#include <iostream>

Carro::Carro(){
    this->x = -1.69;
    this->y = -1.69;
    this->th = -1.69;
}

Carro::Carro(double x, double y, double th){
    this->x = x;
    this->y = y;
    this->th = th;
}


double Carro::getX(){
    return this->x;
};

double Carro::getY(){
    return this->y;
};

double Carro::getTH(){
    return this->th;
}

void Carro::girar(double w, double t){
    double rotacao_total = w * t;
    this->th += rotacao_total;
};

void Carro::mover(double v, double t){
    double distancia = v * t;

    double decomporX = distancia * cos(this->getTH());
    double decomporY = distancia * sin(this->getTH());

    this->x += decomporX;
    this->y += decomporY;
};

//Refazer com ATAN2
double Carro::calcular_angulo_pessoa(Pessoa* pessoa){
    // cos(a) = b² + c² - a² / 2bc

    double deltaX = pessoa->getX() - this->getX();
    double deltaY = pessoa->getY() - this->getY();

    double anguloResultado = atan2(deltaY, deltaX);

    anguloResultado -= this->getTH();

    while (anguloResultado > M_PI) anguloResultado -= 2 * M_PI;
    while (anguloResultado < -M_PI) anguloResultado += 2 * M_PI;

    return anguloResultado;
};

double Carro::calcular_distancia_pessoa(Pessoa* pessoa){
    // distancia é igual à raiz de (x2 - x1)² + (y2 - y1)²
    double distanciaX =  (pessoa->getX() - this->getX()) * (pessoa->getX() - this->getX());
    double distanciaY = (pessoa->getY() - this->getY()) * (pessoa->getY() - this->getY());
    double dist_euclidiana = sqrt(distanciaX + distanciaY);
    return dist_euclidiana;
};

bool Carro::movimentacao_permitida(Pessoa** pessoas, int n){
    bool pode_mover = true;
    

    for (int i = 0; i < n; i++){
        double distancia = calcular_distancia_pessoa(pessoas[i]);
        double angulo = calcular_angulo_pessoa(pessoas[i]);

        if (
            distancia < 5 &&
            angulo > -ANGULO_SEGURANCA &&
            angulo < ANGULO_SEGURANCA
        ){
            pode_mover = false;
            std::cout << "Alerta! " << i << "\t" << convertor_rad_para_grau(angulo) << "\t" << distancia << std::endl;     
        }
    }

    return pode_mover;
};

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t){
    
    if (this->movimentacao_permitida(pessoas, n) == true){
        this->girar(w, t);
        this->mover(v, t);
    }

};