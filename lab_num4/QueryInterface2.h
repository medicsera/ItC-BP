//
// Created by anton on 20.03.2025.
//

#ifndef NEW_TARGET_QUERYINTERFACE2_H
#define NEW_TARGET_QUERYINTERFACE2_H

#pragma once
#include <iostream>
#include <unknwn.h>

using namespace std;

/// Объявления интерфейсов
interface IX : IUnknown {
    virtual void _stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void _stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void _stdcall Fz() = 0;
};

// Объявления идентификаторов интерфейсов
extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

// Объявления функций
IUnknown* CreateInstance();
BOOL SameComponents(IX* pIX, IY* pIY);
void f(IX* pIX);
void f2(IX* pIX);
void f3(IX* pIX);

#endif //NEW_TARGET_QUERYINTERFACE2_H
