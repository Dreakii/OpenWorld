#ifndef CCHUNK_HPP_INCLUDED
#define CCHUNK_HPP_INCLUDED

#include"CObject.hpp"
#include"../BasicTypes.hpp"
#include"../Model/CModel.hpp"

class CChunk // klasa segmentu swiata
{
   public:
    vector<Cobject> zone;
    Cmodel plane; // model segmentu

    CChunk();
    ~CChunk();
    int uncode(glm::ivec3 vec);
    void change( glm::ivec3 vec , Cobject obj);
    const Cobject& GetObj( glm::ivec3 vec);
};

#endif // CCHUNK_HPP_INCLUDED
