//
// Created by anton on 20.03.2025.
//

#include <iostream>
#include "QueryInterface2.h"
using namespace std;

int main() {

    system("chcp 65001");

    HRESULT hr;

    cout << "Клиент: получаем указатель на IUnknown" << endl;
    IUnknown* pIUnknown = CreateInstance();

    cout << "\nКлиент: получаем указатель на IX" << endl;
    IX* pIX = NULL;
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: IX успешно получен" << endl;
        pIX->Fx(); // Используем интерфейс IX
    }

    cout << "\nКлиент: получаем указатель на IY" << endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: IY успешно получен" << endl;
        pIY->Fy(); // Используем интерфейс IY
    }

    cout << "\nКлиент: получаем неподдерживаемый интерфейс" << endl;
    IZ* pIZ = NULL;
    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: интерфейс IZ успешно получен" << endl;
    }
    else {
        cout << "Клиент: невозможно получить интерфейс IZ" << endl;
    }

    cout << "\nКлиент: получаем указатель на IY через IX" << endl;
    IY* pIYfromIX = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IY успешно получен" << endl;
        pIYfromIX->Fy();
    }
    else {
        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
    }

    cout << "\nКлиент: получаем указатель на IUnknown через IY" << endl;
    IUnknown* pIUnknownFromIY = NULL;
    hr = pIY->QueryInterface(IID_IUnknown1, (void**)&pIUnknownFromIY);
    if (SUCCEEDED(hr)) {
        cout << "Равны ли два указателя?" << endl;
        if (pIUnknownFromIY == pIUnknown) {
            cout << "ДА" << endl;
        }
        else {
            cout << "НЕТ" << endl;
        }
    }

    // Тест функции f
    cout << "\nТест f()" << endl;
    try {
        f(pIX);
        cout << "f() выполнена успешно" << endl;
    }
    catch (...) {
        cout << "Ошибка при выполнении f()" << endl;
    }

    // Тест функции f2
    cout << "\nТест f2()" << endl;
    try {
        f2(pIX);
        cout << "f2() выполнена успешно" << endl;
    }
    catch (...) {
        cout << "Ошибка при выполнении f2()" << endl;
    }

    // Тест функции f3
    cout << "\nТест f3()" << endl;
    try {
        f3(pIX);
        cout << "f3() выполнена успешно" << endl;
    }
    catch (...) {
        cout << "Ошибка при выполнении f3()" << endl;
    }

    // Тест функции SameComponents
    cout << "\nТест SameComponents()" << endl;
    bool result = SameComponents(pIX, pIY);
    cout << "Результат сравнения компонентов: "
         << (result ? "указатели совпадают" : "указатели различаются")
         << endl;

    // Очистка памяти после тестов
    if (pIX != NULL) pIX->Release();
    if (pIY != NULL) pIY->Release();

    // Удаление компонента
    delete pIUnknown;

    return 0;
}