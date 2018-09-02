//
// Created by fours on 8/29/2018.
//
#include "SimpleArray.h"


SimpleArray::SimpleArray() : mArray(nullptr) {}

SimpleArray::SimpleArray(AllocationTracker *a) : mArray(nullptr) {
    if (a != nullptr) {
        mArray = a;
    }
}

SimpleArray::~SimpleArray() {
    deleteOp(nullptr);
}

AllocationTracker* SimpleArray::get() const {
    return mArray;
}
bool SimpleArray::isNonNull() const {
    return mArray != nullptr;
}
void SimpleArray::swap(SimpleArray& a2){
    if (a2.mArray != mArray) {
        AllocationTracker *holder = mArray;
        mArray = a2.mArray;
        a2.mArray = holder;
    }
}
void SimpleArray::reset() {
    deleteOp(nullptr);
}
void SimpleArray::reset(AllocationTracker* r) {
    deleteOp(r);
}
AllocationTracker* SimpleArray::release(){
    AllocationTracker* copy = mArray;
    mArray = nullptr;
    return copy;
}

void SimpleArray::deleteOp(AllocationTracker * a) {
    delete[](mArray);
    mArray = a;
}
