
// COS30008, Midterm, Problem 2, 2022

#pragma once

#include "KeyProvider.h"

#define CHARACTERS 26

class Vigenere
{
private:
	char fMappingTable[CHARACTERS][CHARACTERS];
    const std::string fKeyword;
	KeyProvider fKeywordProvider;

    // Initialize the mapping table
    // Row 1:   B - A
    // Row 26:  A - Z
	void initializeTable();
    
public:

    // Initialize Vigenere scrambler
    Vigenere( const std::string& aKeyword );

    // Return the current keyword.
    // This method scans the keyword provider and copies the keywor characters
    // into a result string.
	std::string getCurrentKeyword();

    // Reset Vigenere scrambler.
    // This method has to initialize the keyword provider.
	void reset();

    // Encode a character using the current keyword character and update keyword.
    char encode( char aCharacter );

    // Decode a character using the current keyword character and update keyword.
    char decode( char aCharacter );
};
