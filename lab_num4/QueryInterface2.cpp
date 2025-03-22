//
// Created by anton on 20.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include <cassert>
#include "QueryInterface2.h"

using namespace std;

// Интерфейсы
interface IX : IUnknown {
    virtual void _stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void _stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void _stdcall Fz() = 0;
};

// Компонент
class CA : public IX, public IY {
public:
    // Реализация методов класса IUnknown
    virtual ULONG _stdcall AddRef() { return 0; };
    virtual ULONG _stdcall Release() { return 0; };

    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** ppv) {
        if (iid == IID_IUnknown1) {
            cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
            *ppv = static_cast<IX*>(this);
        }
        else if (iid == IID_IX) {
            cout << "QueryInterface: возвращаю указатель на IX" << endl;
            *ppv = static_cast<IX*>(this);
        }
        else if (iid == IID_IY) {
            cout << "QueryInterface: возвращаю указатель на IY" << endl;
            *ppv = static_cast<IY*>(this);
        }
        else {
            cout << "Интерфейс не поддерживается" << endl;
            *ppv = NULL;
            return E_NOINTERFACE;
        }
        reinterpret_cast<IUnknown*>(*ppv)->AddRef();
        return S_OK;
    }

    // Реализация интерфейса IX
    virtual void _stdcall Fx() { std::cout << "CA::Fx" << std::endl; };

    // Реализация интерфейса IY
    virtual void _stdcall Fy() { std::cout << "CA::Fy" << std::endl; };

};

// // Функция создания компонента
IUnknown* CreateInstance() {
    IUnknown* pI = static_cast<IX*>(new CA);
    pI->AddRef();
    return pI;
}

BOOL SameComponents(IX* pIX, IY* pIY)
{
    IUnknown* pI1 = NULL;
    IUnknown* pI2 = NULL;

    // получить указатели на IUnknown через pIX
    pIX->QueryInterface(IID_IUnknown1, (void**)&pI1);

    // получить указатели на IUnknown через pIY
    pIY->QueryInterface(IID_IUnknown1, (void**)&pI2);

    // сравнить полученные указатели
    return pI1 == pI2;
}

void f(IX* pIX)
{
    IX* pIX2 = NULL;

    // Запросить IX через IX
    HRESULT hr = pIX->QueryInterface(IID_IX, (void**)&pIX2);

    assert(SUCCEEDED(hr)); // Запрос должен быть успешным
}

void f2(IX* pIX)
{
    HRESULT hr;

    IX* pIX2 = NULL;
    IY* pIY = NULL;

    // Получить IY через IX
    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);

    if (SUCCEEDED(hr))
    {
        // Получить IX через IY
        hr = pIY->QueryInterface(IID_IX, (void**)&pIX2);

        // QueryInterface должна отработать успешно
        assert(SUCCEEDED(hr));
    }
}

void f3(IX* pIX)
{
    HRESULT hr;
    IY* pIY = NULL;

    // Запросить IY у IX
    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);

    if (SUCCEEDED(hr))
    {
        IZ* pIZ = NULL;

        // Запросить IZ у IY
        hr = pIY->QueryInterface(IID_IZ, (void**)&pIZ);

        if (SUCCEEDED(hr))
        {
            // Запросить IZ у IX
            hr = pIX->QueryInterface(IID_IZ, (void**)&pIZ);
            assert(SUCCEEDED(hr)); // Это должно работать
        }
    }
}