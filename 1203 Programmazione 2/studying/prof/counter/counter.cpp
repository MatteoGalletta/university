/*
 * counter.cpp
 */

#include "counter.h"

std::ostream & operator<<(std::ostream & output, GenericCounter & c)
{
	output << c.get_value();
	return output;
}



