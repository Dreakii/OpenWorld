#ifndef CREMOTECHARACTER_HPP_INCLUDED
#define CREMOTECHARACTER_HPP_INCLUDED

#include "CCharacter.hpp"

class CRemoteCharacter : public CCharacter
{
 public:
    bool added;
    int id;
    CRemoteCharacter();
    CRemoteCharacter(glm::vec3 pos , float angle , int id);
    friend bool operator==(CRemoteCharacter a ,CRemoteCharacter b );
    friend bool operator!=(CRemoteCharacter a ,CRemoteCharacter b );
    friend bool operator<(CRemoteCharacter a ,CRemoteCharacter b );
    void proggress();
};

#endif // CREMOTECHARACTER_HPP_INCLUDED
