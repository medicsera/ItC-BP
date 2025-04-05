//
// Created by anton on 15.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include "QueryInterface.h"

const IID IID_IX =
        { 0x32bb8320, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

const IID IID_IY =
        { 0x32bb8321, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

const IID IID_IZ =
        { 0x32bb8322, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

const IID IID_IUnknown1 =
        { 0x32bb8323, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

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

