//
// Created by anton on 15.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include "QueryInterface.h"

interface IX : IUnknown {
    virtual void _stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void _stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void _stdcall Fz() = 0;
};

class CA : public IX, public IY {
public:

    virtual ULONG _stdcall AddRef() { return 0; };
    virtual ULONG _stdcall Release() { return 0; };

    virtual HRESULT _stdcall QueryInterface(const IID &iid, void **ppv) {
        if (iid == IID_IUnknown1) {
            cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
            *ppv = static_cast<IX *>(this); // Используем static_cast для приведения указателя this к нужному типу интерфейса.
        } else if (iid == IID_IX) {
            cout << "QueryInterface: возвращаю указатель на IX" << endl;
            *ppv = static_cast<IX *>(this);
        } else if (iid == IID_IY) {
            cout << "QueryInterface: возвращаю указатель на IY" << endl;
            *ppv = static_cast<IY *>(this);
        } else {
            cout << "Интерфейс не поддерживается" << endl;
            *ppv = NULL;
            return E_NOINTERFACE;
        }
        reinterpret_cast<IUnknown*>(*ppv)->AddRef(); // Используется для приведения указателя на интерфейс к указателю на IUnknown.
        return S_OK;
    };

    virtual void _stdcall Fx() { std::cout << "CA::Fx" << std::endl; };
    virtual void _stdcall Fy() { std::cout << "CA::Fy" << std::endl; };

};

// Функция создания компонента
     IUnknown* CreateInstance() {
        IUnknown *pI = static_cast<IX*>(new CA); // Приводит указатель на CA к указателю на IX
        pI->AddRef();
        return pI;
    };

