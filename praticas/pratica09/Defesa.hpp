#ifndef DEFESA_HPP
#define DEFESA_HPP

class Defesa
{
private:
    int _id;
    double _energia;


protected:
    void _consumirEnergia(double qtd);

public:
    Defesa(int id, double energia);

    bool isEnergySuficient(double custo);
    virtual void atacar(double &danoAcumulado) = 0;

    int get_id();
    double get_energia();


    virtual ~Defesa();
};

#endif