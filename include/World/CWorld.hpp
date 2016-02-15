#ifndef CWORLD_HPP_INCLUDED
#define CWORLD_HPP_INCLUDED

#include "CChunk.hpp"
#include "../Generator.hpp"
#include "../Parameter/CParameter.hpp"
#include "CSite.hpp"
#include <map>

class CParameter;
class CSite;

class CWorld
{
   public:
    ///vector<CChunk> Chunk;
    vector<CParameter> Parameter;
    ///vector<CSite> Site;
    map<long long int,CSite> Site;
    glm::ivec3 center;

    struct Position
    {
        int SiteIndex;
        int ChunkIndex;
        glm::ivec2 Site;
    };
    CWorld();
    ~CWorld();
    static vector<Position> region(glm::ivec3 centre);
    static vector<glm::ivec2> shift(glm::ivec3 centre);
    static long long decode(glm::ivec2 vec);
    Cobject GetObj(glm::ivec3 vec);
    void build();
    void generate();
    void load(CGenerator obj , glm::ivec3 vec);
};

#endif // CWORLD_HPP_INCLUDED
