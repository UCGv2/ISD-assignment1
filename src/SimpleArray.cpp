// File name: SimpleArray.cpp
// Author: Christopher Glenn II
// VUnetid: glennca1
// Email: christopher.a.glenn@vanderbilt.edu
// Class: CS3251
// Date: 9/7/18
// Honor statement: I have neither given nor received unauthorized help on this assignment
// Assignment Number: 01
// Description: This is an implementation of a SimpleArray using AllocationTracker objects

#include "SimpleArray.h"
/**
 * @brief Default constructor for the SimpleArray class
 */
SimpleArray::SimpleArray()
    : mArray(nullptr)
{
}

/**
 * @brief Overloaded Constructor for the SimpleArray class
 */
SimpleArray::SimpleArray(AllocationTracker* a)
    : mArray(nullptr)
{
    if (a != nullptr) {
        mArray = a;
    }
}
/**
 * @brief Destructor for the Simple Array class
 */
SimpleArray::~SimpleArray()
{
    deleteOp(nullptr);
}

/**
 * @brief Returns the reference to the array member
 * @details Returns the reference to the member that corresponds to "i" in the array that
 * mArray points to
 * @param i functions like the index of an array
 * @return Returns the reference to the AllocationTracker Array member
 * that corresponds to parameter "i"
 * @throws std::out_of_range- i tries to access members outside of the range of the array
 */
AllocationTracker& SimpleArray::getReference(const uint32_t i) const
{
    if (i >= mArray->getCount()) {
        throw std::out_of_range("Out of Range ERROR");
    } else {
        return mArray[i];
    }
}

/**
 * @brief Fetches mArray as a pointer and it is left const because it should not be changed
 * @return mArray
 */
const AllocationTracker* SimpleArray::get() const
{
    return mArray;
}

/**
 *@brief Returns a SimpleArray to its default settings
 * @details Returns a Simple Array to its default settings by freeing
 * any memory used by AllocationTracker objects that mArray points to and
 * sets mArray to nullptr
 */
void SimpleArray::reset()
{
    deleteOp(nullptr);
}
/**
 * @brief Deletes the current array in mArray and replaces it with parameter "r"
 * @param r is a new array or nullptr
 * @post mArray points to parameter "r"
 */
void SimpleArray::reset(AllocationTracker* r)
{
    deleteOp(r);
}

/**
 * @brief Swaps the mArray fields of two different SimpleArrays
 * @details Swaps the mArray fields of two SimpleArrays provided their mArray fields
 * are pointing to different locations. If they are the same, nothing needs to happen.
 * @param a2 is a different SimpleArray
 */
void SimpleArray::swap(SimpleArray& a2)
{
    if (a2.mArray != mArray) {
        AllocationTracker* holder = mArray;
        mArray = a2.mArray;
        a2.mArray = holder;
    }
}
/**
 * @brief Returns the AllocationTracker* associated with mArray and mArray
 * is pointed to nullptr
 * @return Returns the former address that mArray referenced
 */
AllocationTracker* SimpleArray::release()
{
    AllocationTracker* copy = mArray;
    mArray = nullptr;
    return copy;
}
/**
 * @brief returns whether or not mArray equals nullptr
 * @return the evaluation of the equivalence between mArray and nullptr
 */
bool SimpleArray::isNonNull() const
{
    return mArray != nullptr;
}
/**
 * @brief Deletes the array and assigns mArray to the appropriate next pointer
 * @param nextPtr is the next address that mArray will point to
 */
void SimpleArray::deleteOp(AllocationTracker* nextPtr)
{
    delete[](mArray);
    mArray = nextPtr;
}
