#ifndef CWATER_HPP_INCLUDED
#define CWATER_HPP_INCLUDED

#include "CGenerator.hpp"
#include <stdlib.h>

class CWater : public CGenerator
{
 public:
    vector<int> array;
    int end;

    CWater(int a , int b , int c);
    void add(glm::ivec3 vec);
    void generate(glm::ivec3 source);
};

#endif // CWATER_HPP_INCLUDED
