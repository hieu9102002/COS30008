#include "SimpleString.h"

#include <cstring>

SimpleString::SimpleString():fCharacters(new char[1])
{
    *fCharacters = '\0';
}

SimpleString::~SimpleString()
{
    delete[] fCharacters;
}

SimpleString& SimpleString::operator+(const char aCharacter)
{
    char* temp = new char[strlen(fCharacters) + 2];
    size_t i = 0;
    for (; i < strlen((fCharacters)); i++)
        temp[i] = fCharacters[i];
    temp[i++] = aCharacter;
    temp[i] = '\0';

    delete[] fCharacters;
    fCharacters = temp;
	return *this;
}

const char* SimpleString::operator*() const
{
    return fCharacters;
}
