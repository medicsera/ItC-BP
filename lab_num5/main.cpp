//
// Created by anton on 22.04.2025.
//
#include <iostream>
#include <unknwn.h>
#include "Interface.h"

using namespace std;

int main () {

    system("chcp 65001");

    HRESULT hr;

    cout << "Клиент: получить указатель на IUnknown" << endl;
    IUnknown* pIUnknown = CreateInstance();

    cout << "\nКлиент: получить указатель на IX" << endl;
    IX* pIX = NULL;
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IX успешно получен" << endl;
        pIX->Fx(); // Использовать интерфейс IX

        cout << "\nКлиент: вызвать функцию f(IX*)" << endl;
        f(pIX); // Вызов функции f

        cout << "\nКлиент: вызвать функцию f2(IX*)" << endl;
        f2(pIX); // Вызов функции f2

        cout << "\nКлиент: вызвать функцию f3(IX*)" << endl;
        f3(pIX); // Вызов функции f3

        IX* pIX2 = pIX;
        pIX2->AddRef();
        pIX2->Fx();
        pIX2->Release();

        pIX->Release();
    };

    cout << "\nКлиент: получить указатель на IY" << endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IY успешно получен" << endl;
        pIY->Fy(); // Использовать интерфейс IY
        pIY->Release(); // Завершить работу с pIY
    };

    cout << "\nКлиент: получить неподдерживаемый интерфейс" << endl;
    IZ* pIZ = NULL;
    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
    if(SUCCEEDED(hr)) {
        cout << "Клиент: интерфейс IZ успещно получен" << endl;
        pIZ->Release(); // Завершить работу с pIZ
    } else {
        cout << "Клиент: Не удается получить доступ к интерфейсу IZ" << endl;
    };


    cout << "\nКлиент: получить указатель на IY через IX" << endl;
    IY* pIYfromIX = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
    if(SUCCEEDED(hr)) {
        cout<< "Клиент: указатель на IY успешно получен" << endl;
        pIYfromIX->Fy();
        pIYfromIX->Release(); // Завершить работу с pIYfromIX
    } else {
        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
    }

    cout << "\nКлиент: получить указатель на IUnknown через IY" << endl;
    IUnknown *pIUnknownFromIY = NULL;
    hr = pIY->QueryInterface(IID_IUnknown1, (void **) &pIUnknownFromIY);
    if (SUCCEEDED(hr)) {
        cout << "Равны два ли два указателя?" << endl;
        if (pIUnknownFromIY == pIUnknown) {
            cout << "ДА" << endl;
        } else {
            cout << "НЕТ" << endl;
        }
        pIUnknownFromIY->Release(); // Завершить работу с pIUnknownFromIY
    }

    cout << "\nКлиент: проверить, являются ли IX и IY одним и тем же объектом" << endl;
    if (SameComponents(pIX, pIY)) {
        cout << "Клиент: IX и IY указывают на один и тот же объект" << endl;
    } else {
        cout << "Клиент: IX и IY указывают на разные объекты" << endl;
    }

    // Удалить компонент
    pIUnknown->Release();

    return 0;
};