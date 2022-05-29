
// COS30008, Midterm, Problem 2, 2022

#include "Vigenere.h"

using namespace std;

void Vigenere::initializeTable()
{
	for ( char row = 0; row < CHARACTERS; row++ )
	{
		char lChar = 'B' + row;

		for ( char column = 0; column < CHARACTERS; column++ )
		{
            if ( lChar > 'Z' )
                lChar = 'A';

            fMappingTable[row][column] = lChar++;
		}
	}
}

Vigenere::Vigenere(const std::string& aKeyword): fKeyword(aKeyword), fKeywordProvider(KeyProvider(aKeyword))
{
	initializeTable();
}

std::string Vigenere::getCurrentKeyword()
{
	std::string result;

	for (size_t i = 0; i < fKeyword.length(); i++) {
		result += *fKeywordProvider;
		fKeywordProvider << *fKeywordProvider;
	}

	return result;
}

void Vigenere::reset()
{
	fKeywordProvider.initialize(fKeyword);
}

char Vigenere::encode(char aCharacter)
{
	if (isalpha(aCharacter))
	{
		bool isLower = std::islower(aCharacter);

		char encoded = fMappingTable[*fKeywordProvider - 'A'][std::toupper(aCharacter) - 'A'];

		fKeywordProvider << aCharacter;

		return isLower ? static_cast<char>(std::tolower(encoded)) : (encoded);
	}
	else
	{
		return aCharacter;
	}
}

char Vigenere::decode(char aCharacter)
{
	if (isalpha(aCharacter))
	{
		bool isLower = std::islower(aCharacter);
		char encoded = static_cast<char>(toupper(aCharacter));
		char decoded = 0;

		for (char column = 0; column < CHARACTERS; column++)
		{
			if (fMappingTable[*fKeywordProvider-'A'][column] == encoded)
			{
				decoded = static_cast<char>(column + 'A');
				break;
			}
		}
		fKeywordProvider << decoded;

		return isLower ? static_cast<char>(std::tolower(decoded)) : (decoded);
	}
	else
	{
		return aCharacter;
	}
}
