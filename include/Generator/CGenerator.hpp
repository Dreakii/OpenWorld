#ifndef CGENERATOR_HPP_INCLUDED
#define CGENERATOR_HPP_INCLUDED

#include <glm/glm.hpp>
#include "../World/CObject.hpp"
#include "../BasicTypes.hpp"
#include <vector>
#include <iostream>


using namespace std;

class CGenerator
{
   public:
    vector<Cobject> field;
    int null;
    int X,Y,Z;

    CGenerator(int x , int y , int z);
    short& GetObj(glm::ivec3 vec);
    int size();
    void clear();
    void copy_vector(vector<Cobject> wektor);
    bool surrounded(glm::ivec3 vec);
    void fill(int from , int to , int id);
    void smooth(int z , int id);
    void smoothing(int from , int to);
    void round();
    void print();
    void carve(glm::ivec3 vec , int r , int id);
    bool inrange(glm::ivec3 vec);
};

#endif //CGENERATOR_HPP_INCLUDED
