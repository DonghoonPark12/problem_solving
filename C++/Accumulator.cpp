#include "AccumulatorClass.h"

Accumulator::Accumulator(int myvalue)
	:value(myvalue)
{ }

Accumulator& Accumulator::add(int n)
{
	value += n;
	return *this;
}

int Accumulator::get()
{
	return value;
}
