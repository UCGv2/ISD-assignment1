// @author G. Hemingway, copyright 2018 - All rights reserved
//
#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H

// Just include the special AllocationTracker class
#include "AllocationTracker.h"

class SimpleArray {
public:
    /*** Add some constructors/destructor goodness here ***/

    /**
     *  getReference is const and returns a non-const type in order to mimic
     *  dereferencing raw pointers through the subscript operator as closely
     *  as possible. A pointer-that-is-const is permitted to alter the data
     *  where it points, but may never be pointed to a different address; the
     *  same should be true of SimpleArrays-that-are-const.
     */
    AllocationTracker& getReference(const uint32_t i) const;

    /*** Need to add some things here ***/

private:
    /*** Maybe some things here too ***/

    // Data members
    AllocationTracker* mArray;
};

#endif // SIMPLE_ARRAY_H
