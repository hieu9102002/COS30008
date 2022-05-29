
// COS30008, Midterm, Problem 1, 2022

#pragma once

#include <string>

class KeyProvider
{
private:
    char * fKeyword;    // keyword
    size_t fSize;       // length of keyword
    size_t fIndex;      // index to current keyword character
    
public:
    
    // Initialize key provider.
    // aKeyword is a string of letters.
    KeyProvider( const std::string& aKeyword );

    // Destructor, release resources.
    ~KeyProvider();
    
    // Initialize (or reset) keyword
    void initialize( const std::string& aKeyword );
    
    // Dereference, returns current keyword character.
    char operator*() const;
    
    // Push new keyword character.
    // aKeyCharacter is a letter (isalpha() is true).
    // aKeyCharacter replaces current keyword character.
    // Key provider advances to next keyword character.
    KeyProvider& operator<<( char aKeyCharacter );
};
