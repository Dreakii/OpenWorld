//CChunk.cpp

#include"CChunk.hpp"

CChunk::CChunk()
{
    for(int x = 0 ; x < 4096 ; x++)
        zone.push_back(Cobject(0));
    //cout << zone[0].id << endl;
}
CChunk::~CChunk()
{
}

int CChunk::uncode( glm::ivec3 vec)
{
    int a = vec.x+16*vec.y+256*vec.z;
    if(a < 0)
        a = -a;
    return a; // zwraca indeks tablicy na podstawie vectora
}
void CChunk::change( glm::ivec3 vec , Cobject obj)
{

    zone[uncode(vec)] = obj.id; // zmienia obiekt okreslony vectorem na inny
}

const Cobject& CChunk::GetObj( glm::ivec3 vec)
{
    return zone[uncode(vec)]; // zwraca obiekt okreslony vectorem
}
