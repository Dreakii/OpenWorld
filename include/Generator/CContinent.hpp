#ifndef CCONTINENT_HPP_INCLUDED
#define CCONTINENT_HPP_INCLUDED

#include "CGenerator.hpp"
#include "CHill.hpp"
#include <fstream>

class CContinent : public CGenerator
{
    int area_size;
    int x_max , y_max , x_min , y_min;
    glm::ivec2 continent_size;
    vector<int> surface;
 public:
    int superficies;
    void border(int x , int y);
    CContinent(int area_size , glm::ivec2 continent_size);
    int GetUnit(glm::ivec2 vec);
    void genContinents(int power , int seeds);
    CGenerator GetContinent();
};


#endif // CCONTINENT_HPP_INCLUDED
