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

int main() {
    CA* pA1 = new CA(1.5);
    pA1->Fx1();
    pA1->Fx2();
    pA1->Fx3();
    pA1->Fx4();

    CA* pA2 = new CA(2.75);
    pA2->Fx1();
    pA2->Fx2();
    pA2->Fx3();
    pA2->Fx4();

    return 0;
}