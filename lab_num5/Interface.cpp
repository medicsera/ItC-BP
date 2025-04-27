//
// Created by anton on 22.04.2025.
//
#include "Interface.h"
#include <cassert>

// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IX =
        {0x32bb8320, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IY =
        {0x32bb8321, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8322-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IZ =
        {0x32bb8322, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8323-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IUnknown1 =
        {0x32bb8323, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

CA::CA() : m_cRef(0) {
    cout << "CA: создан" << endl;
}

CA::~CA() {
    cout << "CA: уничтожен" << endl;
}

ULONG __stdcall CA::AddRef() {
    cout << "CA: AddRef = " << m_cRef + 1 << endl;
    return ++m_cRef;
};

ULONG __stdcall CA::Release() {
    cout << "CA: Release = " << m_cRef - 1 << endl;
    if (--m_cRef == 0) {
        delete this;
        return 0;
    }
    return m_cRef; // Было return --m_cRef
};

HRESULT __stdcall CA::QueryInterface(const IID &iid, void **ppv) {
    if (iid == IID_IUnknown1) {
        cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
        *ppv = static_cast<IX *>(this);
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
    reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    return S_OK;
};

void __stdcall CA::Fx() { cout << "CA::Fx" << endl; };

void __stdcall CA::Fy() { cout << "CA::Fy" << endl; };

IUnknown* CreateInstance() {
    IUnknown* pI = static_cast<IX*>(new CA);
    pI->AddRef();
    return pI;
};

BOOL SameComponents(IX* pIX, IY* pIY) {
    IUnknown* pI1 = NULL;
    IUnknown* pI2 = NULL;

    // Получить указатель на IUnknown через pIX
    pIX->QueryInterface(IID_IUnknown1, (void**)&pI1);

    // Получить указатель на IUnknown через pIY
    pIY->QueryInterface(IID_IUnknown1, (void**)&pI2);

    // Сравнить полученные указатели
    BOOL result = (pI1 == pI2);

    if (pI1) pI1->Release();
    if (pI2) pI2->Release();

    return result;
}

void f(IX* pIX) {
    IX* pIX2 = NULL;
    HRESULT hr = pIX->QueryInterface(IID_IX, (void**)&pIX2);
    assert(SUCCEEDED(hr)); // Запрос должен быть успешным

    if (pIX2) pIX2->Release();
}

void f2(IX* pIX) {
    HRESULT hr;

    IX* pIX2 = NULL;
    IY* pIY = NULL;

    // Получить IY через IX
    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        // Получить IX через IY
        hr = pIY->QueryInterface(IID_IX, (void**)&pIX2);

        assert(SUCCEEDED(hr));
    }

    if (pIX2) pIX2->Release();
    if (pIY) pIY->Release();
}

void f3(IX* pIX) {
    HRESULT hr;

    IY* pIY = NULL;

    // Запросить IY у IX
    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);

    if (SUCCEEDED(hr)) {
        IZ* pIZ = NULL;

        // Запросить IZ у IY
        hr = pIY->QueryInterface(IID_IZ, (void**)&pIZ);

        if (SUCCEEDED(hr)) {
            // Запросить IZ у IX
            hr = pIX->QueryInterface(IID_IZ, (void**)&pIZ);

            assert(SUCCEEDED(hr)); // Это должно работать
        }

        if (pIZ) pIZ->Release();
    }

    if (pIY) pIY->Release();
}