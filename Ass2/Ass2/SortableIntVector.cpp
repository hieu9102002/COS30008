#include "SortableIntVector.h"

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : IntVector(aArrayOfIntegers, aNumberOfElements)
{
}

void SortableIntVector::sort(Comparable aOrderFunction)
{
	for (size_t i = 0; i < size(); i++)
	{
		for (size_t j = size()-1; j > i ;j--)
		{
			if (aOrderFunction(get(j),get(j-1))) swap(j, j - 1);
		}
	}
}
