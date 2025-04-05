//
// Created by anton on 15.03.2025.
//
#pragma once
#ifndef NEW_TARGET_QUERYINTERFACE_H
#define NEW_TARGET_QUERYINTERFACE_H

#include <iostream>
#include <unknwn.h>

using namespace std;

// Предварительное объявление идентификаторов интерфейсов
extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

// Объявления интерфейсов
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

// Объявление функции создания экземпляра
IUnknown* CreateInstance();




#endif //NEW_TARGET_QUERYINTERFACE_H
