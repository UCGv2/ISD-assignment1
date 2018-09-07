// @author G. Hemingway, copyright 2018 - All rights reserved
//
// File name: SimpleArray.h
// Author: Christopher Glenn II
// VUnetid: glennca1
// Email: christopher.a.glenn@vanderbilt.edu
// Class: CS3251
// Date: 9/7/18
// Honor statement: I have neither given nor received unauthorized help on this assignment
// Assignment Number: 01
// Description: This is the declaration of a SimpleArray using AllocationTracker objects

#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H

// Just include the special AllocationTracker class
#include "AllocationTracker.h"
#include <stdexcept>
/**
 * @brief Simulates a simplified array structure
 * @details Simulates the referential nature of arrays by pointing an AllocationTracker* to an
 * array of AllocationTracker objects. SimpleArrays can be constructed but not assigned or copied.
 */
class SimpleArray {
public:
    /*** Add some constructors/destructor goodness here ***/

    /**
     * @brief Default constructor for the SimpleArray class
     */
    SimpleArray();

    /**
     * @brief Overloaded Constructor for the SimpleArray class
     */
    SimpleArray(AllocationTracker* a);

    /**
     *
     * @param noCopy
     */
    SimpleArray(SimpleArray& noCopy) = delete;

    /**
     * @brief Destructor for the Simple Array class
     */
    ~SimpleArray();

    /**
     *
     * @param noAssign
     * @return
     */
    SimpleArray& operator=(const SimpleArray& noAssign) = delete;

    /**
     *  getReference is const and returns a non-const type in order to mimic
     *  dereferencing raw pointers through the subscript operator as closely
     *  as possible. A pointer-that-is-const is permitted to alter the data
     *  where it points, but may never be pointed to a different address; the
     *  same should be true of SimpleArrays-that-are-const.
     */
    AllocationTracker& getReference(const uint32_t i) const;

    /*** Need to add some things here ***/

    /**
     * @brief Fetches mArray
     * @return mArray
     */
    const AllocationTracker* get() const;

    /**
     *@brief Returns a SimpleArray to its default settings
     * @details Returns a Simple Array to its default settings by freeing
     * any memory used by AllocationTracker objects that mArray points to and
     * sets mArray to nullptr
     */
    void reset();

    /**
     * @brief Deletes the current array in mArray and replaces it with parameter "r"
     * @param r is a new array or nullptr
     * @post mArray points to parameter "r"
     */
    void reset(AllocationTracker* next);
    /**
     * @brief Swaps the mArray fields of two different SimpleArrays
     * @details Swaps the mArray fields of two SimpleArrays provided their mArray fields
     * are pointing to different locations. If they are the same, nothing needs to happen.
     * @param a2 is a different SimpleArray
     */
    void swap(SimpleArray& a2);

    /**
     * @brief Returns the AllocationTracker* associated with mArray and mArray
     * is pointed to nullptr
     * @return Returns the former address that mArray referenced
     */
    AllocationTracker* release();
    /**
     * @brief returns whether or not mArray equals nullptr
     * @return the evaluation of the equivalence between mArray and nullptr
     */
    bool isNonNull() const;

private:
    /*** Maybe some things here too ***/

    // Data members
    /**
     * @brief a pointer that points to an AllocationTracker array
     */
    AllocationTracker* mArray;

    /**
     * @brief Deletes the array and assigns mArray to the appropriate next pointer
     * @param nextPtr is the next address that mArray will point to
     */
    void deleteOp(AllocationTracker* nextPtr);
};

#endif // SIMPLE_ARRAY_H
