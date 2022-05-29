#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequence& aSequenceObject, uint64_t aStart) :fSequenceObject(aSequenceObject), fIndex(aStart)
{
}

FibonacciSequenceIterator::FibonacciSequenceIterator(uint64_t aLimit, uint64_t aStart) : fSequenceObject(FibonacciSequence(aLimit)), fIndex(aStart)
{
}

const uint64_t& FibonacciSequenceIterator::operator*() const
{
	return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
	fSequenceObject.advance();
	fIndex++;
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator lTmp = *this;
	++(*this);
	return lTmp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return (aOther.fIndex == this->fIndex);
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	FibonacciSequenceIterator lResult = *this;
	lResult.fSequenceObject.reset();
	lResult.fIndex = 1;
	return lResult;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	FibonacciSequenceIterator lResult = *this;
	lResult.fIndex = fSequenceObject.getLimit() == 0? 0: fSequenceObject.getLimit() + 1;
	return lResult;
}