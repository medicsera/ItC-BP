//
// Created by anton on 13.03.2025.
//
#include <iostream>

class IX
{
public:
    virtual void Fx1() = 0;
    virtual void Fx2() = 0;
};

class IY {
public:
    virtual void Fy1() = 0;
    virtual void Fy2() = 0;
};

class CA : public IX, public IY
{
public:
    //Реализация абстрактного базового класса IX
    virtual void Fx1() {std::cout << "Fx1" << std::endl; }
    virtual void Fx2() {std::cout << "Fx2" << std::endl; }
    //Реализация абстрактного базового класса IY
    virtual void Fy1() {std::cout << "Fy1" << std::endl; }
    virtual void Fy2() {std::cout << "Fy2" << std::endl; }
};

int main(){
    std::cout << "Client create an example of component" << std::endl;
    CA* pA = new CA;

    // Получить указатель IX

    IX* pIX = pA;

    std::cout << "Client: using interface IX" << std::endl;
    pIX->Fx1();
    pIX->Fx2();

    // Получить указатель IY

    IY* pIY = pA;

    std::cout << "Client: using interface IY" << std::endl;
    pIY->Fy1();
    pIY->Fy2();

    std::cout << "Client: deleting component" << std::endl;
    delete pA;

    return 0;
};