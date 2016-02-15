#ifndef CVALLEY_HPP_INCLUDED
#define CVALLEY_HPP_INCLUDED

#include "CGenerator.hpp"
#include <stdlib.h>

class CValley : public CGenerator
{
 public:
    int x, y, z;
    glm::ivec3 source;

    CValley(int a , int b , int c);
    void generate(int r);
    glm::ivec3 GetSource();
};

#endif // CVALLEY_HPP_INCLUDED
