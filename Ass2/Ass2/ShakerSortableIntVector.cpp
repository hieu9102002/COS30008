		#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers,aNumberOfElements)
{
}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
	size_t beginIndex = 0;
	size_t endIndex = size() - 1;

	while (beginIndex < endIndex)
	{
		for (size_t i = beginIndex; i < endIndex; i++)
		{
			if (aOrderFunction(get(i), get(i+1))) swap(i, i + 1);
		}
		endIndex--;
		for (size_t i = endIndex; i > beginIndex; i--)
		{
			if (aOrderFunction(get(i-1), get(i))) swap(i, i - 1);
		}
		beginIndex++;
	}
}
