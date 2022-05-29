#include "FisherAndYatesSort.h"
#include <iostream>

void FisherAndYatesSort::shuffle()
{
	size_t n = size();
	while (n > 1) {
		size_t k = rand() % n;
		swap(--n, k);
	}
}

FisherAndYatesSort::FisherAndYatesSort(const int aArrayOfIntegers[], size_t aNumberOfElements):SortableIntVector(aArrayOfIntegers,aNumberOfElements)
{
	srand((unsigned int)time(NULL));

}

void FisherAndYatesSort::sort(Comparable aOrderFunction)
{
	bool isSorted = true;
	do {
		isSorted = true;
		//std::cout << "Stage: " << *this << std::endl;
		for (size_t i = 0; i < size() - 1; i++)
			if (!aOrderFunction(get(i), get(i + 1))) 
			{
				isSorted = false;
				shuffle();
				break;
			}
	} while (!isSorted);
}
