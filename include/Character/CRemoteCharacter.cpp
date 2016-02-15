// CRemoteCharacter.cpp

#include "CRemoteCharacter.hpp"

CRemoteCharacter::CRemoteCharacter() : CCharacter()
{
    added = false;
    download("data/hero");
}
CRemoteCharacter::CRemoteCharacter(glm::vec3 pos_ , float angle_ , int id_ ) : CCharacter()
{
    download("data/hero");
    added = false;
    pos = pos_;
    angle = angle_;
    id = id_;
}

bool operator==(CRemoteCharacter a ,CRemoteCharacter b )
{
    if(a.id == b.id)
        return true;
    else
        return false;
}
bool operator!=(CRemoteCharacter a ,CRemoteCharacter b )
{
    if(a.id != b.id)
        return true;
    else
        return false;
}
bool operator<(CRemoteCharacter a ,CRemoteCharacter b )
{
    if(a.id < b.id)
        return true;
    else
        return false;
}

void CRemoteCharacter::proggress()
{

}
