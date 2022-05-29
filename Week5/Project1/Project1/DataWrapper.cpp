#include "DataWrapper.h"
#include "iostream"
#include "fstream"
#include "stdexcept"

DataWrapper::DataWrapper() : fSize(0), fData(nullptr)
{
}

DataWrapper::~DataWrapper()
{
	delete[] fData;
}

bool DataWrapper::load(const std::string& aFileName)
{
	std::ifstream lInput(aFileName, std::ifstream::in);

	if (!lInput.good()) return false;

	lInput >> fSize;

	fData = new DataMap[fSize];

	for (size_t i = 0; i < fSize; i++)
	{
		lInput >> fData[i].fIndex >> fData[i].fDatum;
	}

	return true;
}

size_t DataWrapper::size() const
{
	return fSize;
}

const DataMap& DataWrapper::operator[](size_t aIndex) const
{
	if (aIndex >= fSize) throw std::out_of_range("Index is out of range");
	return fData[aIndex];
}

const char DataWrapper::get(size_t aIndex, Callable aSelector)
{
	return aSelector(aIndex);
}
