
// COS30008, Midterm, Problem 4, 2022

#pragma once

#include "iVigenereStream.h"

class VigenereForwardIterator
{
private:
    iVigenereStream& fIStream;
    char fCurrentChar;
    bool fEOF;
    
public:

    VigenereForwardIterator( iVigenereStream& aIStream );

    // forward iterator interface
    char operator*() const;
    VigenereForwardIterator& operator++();           // prefix increment
    VigenereForwardIterator operator++( int );       // postfix increment
    
    bool operator==( const VigenereForwardIterator& aOther ) const;
    bool operator!=( const VigenereForwardIterator& aOther) const;
    
    VigenereForwardIterator begin() const;
    VigenereForwardIterator end() const;
};
