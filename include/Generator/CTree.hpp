#ifndef CTREE_HPP_INCLUDED
#define CTREE_HPP_INCLUDED

#include "CGenerator.hpp"
#include <stdlib.h>

class CTree : public CGenerator
{
 public:
    CTree(int x , int y , int z);
    void generate(int power);
};


#endif // CTREE_HPP_INCLUDED
