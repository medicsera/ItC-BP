//
// Created by anton on 13.03.2025.
//
#include <iostream>

class IX {
public:
    virtual void Fx1() = 0;
    virtual void Fx2() = 0;
    virtual void Fx3() = 0;
    virtual void Fx4() = 0;
};

class CA : public IX {
public:
    double m_Fx2;
    double m_Fx3;
    double m_Fx4;

    virtual void Fx1() { std::cout << "CA::Fx1" << std::endl; };
    virtual void Fx2() { std::cout << m_Fx2 << std::endl; };
    virtual void Fx3() { std::cout << m_Fx3 << std::endl; };
    virtual void Fx4() { std::cout << m_Fx4 << std::endl; };

    CA(double d) {
        m_Fx2 = d * d;
        m_Fx3 = d * d * d;
        m_Fx4 = d * d * d * d;
    };
};

class CB : public IX {
public:
    virtual void Fx1() { std::cout << "CB::Fx1" << std::endl; };
    virtual void Fx2() { std::cout << "CB::Fx2" << std::endl; };
    virtual void Fx3() { std::cout << "CB::Fx3" << std::endl; };
    virtual void Fx4() { std::cout << "CB::Fx4" << std::endl; };
};

void foo(IX* pIX) {
    pIX->Fx1();
    pIX->Fx2();
};

int main() {
    CA* pA = new CA(1.789);

    CB* pB = new CB;

    IX* pIX = pA;
    foo(pIX);

    pIX = pB;
    foo(pIX);

    return 0;
};