//
// Created by fours on 8/29/2018.
//
#include "SimpleArray.h"


SimpleArray::SimpleArray() : mArray(nullptr)
{}

SimpleArray::SimpleArray(AllocationTracker* a)
{
    if(a!=nullptr) {
        mArray = a;
    }
}

SimpleArray::~SimpleArray()
{
    delete mArray;
}
