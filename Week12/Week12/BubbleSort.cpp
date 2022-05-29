#include "BubbleSort.h"
#include <iostream>
BubbleSort::BubbleSort(const int aArrayOfIntegers[], size_t aNumberOfElements):SortableIntVector(aArrayOfIntegers,aNumberOfElements)
{
}

void BubbleSort::sort(Comparable aOrderFunction)
{
	for (size_t i = 0; i < size(); i++) 
	{
		for (size_t j = size() - 1; j > i; j--)
			if (aOrderFunction(get(j), get(j - 1)))
				swap(j, j - 1);
		std::cout << "\tStage i = " << i << ": " << *this << std::endl;
	}
}
