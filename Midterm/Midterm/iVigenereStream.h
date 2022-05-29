
// COS30008, Midterm, Problem 3, 2022

#pragma once

#include <fstream>
#include <functional>

#include "Vigenere.h"

using Cipher = std::function<char ( Vigenere& aCipherProvider, char aCharacter )>;

class iVigenereStream
{
private:
	std::ifstream fIStream;
	Vigenere fCipherProvider;
	Cipher fCipher;

public:
	iVigenereStream( Cipher aCipher, const std::string& aKeyword, const char* aFileName = nullptr );
	~iVigenereStream();

	void open( const char* aFileName );
	void close();
	void reset();

	// conversion operator to bool
	operator bool() { return !eof(); }

	// stream positioning
	uint64_t position() { return fIStream.tellg(); }
	void seekstart() { fIStream.clear(); fIStream.seekg( 0, std::ios_base::beg ); }

	bool good() const;
	bool is_open() const;
	bool eof() const;

	iVigenereStream& operator>>( char& aCharacter );
};
