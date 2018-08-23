// @author G. Hemingway, copyright 2017
//
#include "AllocationTracker.h"

uint32_t AllocationTracker::mCount = 0;

std::ostream& operator<<(std::ostream& stream, const AllocationTracker&)
{
    stream << AllocationTracker::getCount() << std::endl;
    return stream;
}
