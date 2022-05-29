#include "Polygon.h"

#include <stdexcept>

float Polygon::getSignedArea() const
{
    float Result = 0.0f;

    // There have to be at least three vertices
    if (fNumberOfVertices > 2)
    {
        for (size_t i = 0; i < fNumberOfVertices; i++) {
            size_t nextI = (i + 1) % fNumberOfVertices;
            Result += fVertices[i].getX() * fVertices[nextI].getY() - fVertices[i].getY() * fVertices[nextI].getX();
        }
    }
    Result /= 2;
    return Result;
}