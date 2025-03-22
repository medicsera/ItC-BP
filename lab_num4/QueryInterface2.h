//
// Created by anton on 20.03.2025.
//

#ifndef NEW_TARGET_QUERYINTERFACE2_H
#define NEW_TARGET_QUERYINTERFACE2_H

#pragma once
#include <iostream>
#include <unknwn.h>

using namespace std;

// Предварительное объявление идентификаторов интерфейсов
extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

// определение IID
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IX =
        { 0x32bb8320, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IY =
        { 0x32bb8321, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

// {32bb8322-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IZ =
        { 0x32bb8322, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

// {32bb8323-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IUnknown1 =
        { 0x32bb8323, 0xb41b, 0x11cf,
          {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

#endif //NEW_TARGET_QUERYINTERFACE2_H
