#ifndef CSITE_HPP_INCLUDED
#define CSITE_HPP_INCLUDED

#include <vector>
#include "CChunk.hpp"
#include "../Parameter/CParameter.hpp"

class CParameter;

class CSite
{
 public:
    vector<CParameter>& Parameter;
    vector<CChunk> Chunk;
    glm::ivec3 position;

    CSite(glm::ivec3 pos , vector<CParameter>& par);
    static glm::ivec3 decode(int pos);
    static glm::ivec3 GetPos(int pos);
    static int decode(glm::ivec3 vec);
    static pair<glm::ivec3 , glm::ivec3> identify(glm::ivec3 vec);
    glm::ivec3 transcode(glm::ivec3 vec);
    Cobject GetObj(glm::ivec3 main , glm::ivec3 relative);
    Cobject GetObj(glm::ivec3 vec);
    void addobj( Cobject obj , glm::ivec3 vec );
    void load(CGenerator obj , glm::ivec3 vec);
    void change(Cobject obj , glm::ivec3 vec , bool mod = true );
    void build();
};

#endif // CSITE_HPP_INCLUDED
