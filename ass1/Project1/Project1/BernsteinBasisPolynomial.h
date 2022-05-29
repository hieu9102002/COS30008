
// COS30008, Problem Set 1/4, 2022

#pragma once

#include "Combination.h"

// https://en.wikipedia.org/wiki/Bernstein_polynomial
class BernsteinBasisPolynomial
{
private:
    Combination fFactor;
    
public:
    
    // constructor for b(v,n) with defaults
    BernsteinBasisPolynomial( unsigned int aV = 0, unsigned int aN = 0);
    
    // call operator to calculate Berstein base
    // polynomial for a given x (i.e., aX)
    double operator()( double aX ) const;
};
