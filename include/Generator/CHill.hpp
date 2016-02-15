#ifndef CHILL_HPP_INCLUDED
#define CHILL_HPP_INCLUDED

#include "CGenerator.hpp"
#include <stdlib.h>

class CHill : public CGenerator
{
 public:
    CHill(int x , int y , int z);
    int LayerSize(int z);
    int generate(int power , float severity );
    void level( int power , int z);
};

#endif // CHILL_HPP_INCLUDED
