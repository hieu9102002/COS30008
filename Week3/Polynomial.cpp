#include "Polynomial.h"
#include <stdexcept>

Polynomial::Polynomial() : fDegree(0), fCoeffs() {}

Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
	Polynomial resultPoly;
	resultPoly.fDegree = fDegree + aRHS.fDegree;

	for (int i = 0; i <= fDegree; i++) {
		for (int j = 0; j <= aRHS.fDegree; j++) {
			resultPoly.fCoeffs[i+j] += fCoeffs[i] * aRHS.fCoeffs[j];
		}
	}

	return resultPoly;
}

bool Polynomial::operator==(const Polynomial& aRHS) const
{
	if (fDegree != aRHS.fDegree) return false;

	for (int i = 0; i <= fDegree; i++)
		if (fCoeffs[i] != aRHS.fCoeffs[i]) return false;
	return true;
}

std::istream& operator>>(std::istream& aIStream, Polynomial& aObject)
{
	aIStream >> aObject.fDegree;

	if (aObject.fDegree > MAX_POLYNOMIAL) throw new std::out_of_range("Order of polynomial is over 10");

	for (int i = aObject.fDegree; i >= 0; i--)
		aIStream >> aObject.fCoeffs[i];

	return aIStream;
}

std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject)
{
	aOStream << aObject.fCoeffs[aObject.fDegree] << "x^" << aObject.fDegree;

	for (int i = aObject.fDegree-1; i >= 0; i--) {
		if (aObject.fCoeffs[i] != 0)
			aOStream << " + " << aObject.fCoeffs[i] << "x^" << i;
	}
	return aOStream;
}
