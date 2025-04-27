//
// Created by anton on 22.04.2025.
//

#ifndef NEW_TARGET_INTERFACE_H
#define NEW_TARGET_INTERFACE_H

#include <iostream>
#include <unknwn.h>
#include <objbase.h>

using namespace std;

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

// Интерфейсы
interface IX : IUnknown {
    virtual void __stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void __stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void __stdcall Fz() = 0;
};

class CA : public IX, public IY {
public:
    // Конструктор
    CA();

    // Деструктор
    ~CA();

    // Реализация методов класса IUnknown
    virtual ULONG __stdcall AddRef() override;
    virtual ULONG __stdcall Release() override;

    virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv) override;

    virtual void __stdcall Fx() override;
    virtual void __stdcall Fy() override;

private:
    // Счетчик ссылок
    long m_cRef;
};

IUnknown* CreateInstance();

// Функция определяет, указывают ли pIX и pIY на интерфейсы одного компонента
BOOL SameComponents(IX* pIX, IY* pIY);

void f(IX* pIX);

void f2(IX* pIX);

void f3(IX* pIX);

#endif //NEW_TARGET_INTERFACE_H
