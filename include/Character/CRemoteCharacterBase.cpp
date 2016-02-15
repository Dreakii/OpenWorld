// CRemoteCharacterBase.cpp

#include "CRemoteCharacterBase.hpp"

CRemoteCharacterBase::CRemoteCharacterBase()
{
    need_add = true;
}

void CRemoteCharacterBase::add(std::remove_reference<CRemoteCharacter>::type new_obj)
{
    //new_obj.download("data\\hero");
    base.push_back(std::move(new_obj));
    need_add = true;
    //base.back().download("data\\hero");
}

void CRemoteCharacterBase::refreshBase(CRemoteCharacterBase new_base)
{
    typedef list<CRemoteCharacter>::iterator iter;
    for(iter X = base.begin() , Y = new_base.base.begin() ; Y != new_base.base.end() ; X++ , Y++)//(CRemoteCharacter& X ; CRemoteCharacter& Y : other_characters.base ; new_base.base)
    {
        iter fit = std::find(base.begin(), base.end(), *Y);
        if(fit != base.end())
        {
            (*X).pos = (*Y).pos;
            (*X).angle = (*Y).angle;
            (*X).id = (*Y).id;
        }
        else
        {
            add(std::move(CRemoteCharacter((*Y).pos , (*Y).angle , (*Y).id)) );
            base.back().download("data/hero");
            need_add = true;
        }
    }
}

void CRemoteCharacterBase::refreshElement(CRemoteCharacter obj )
{
    for(CRemoteCharacter& X : base)
    {
        if(X.id == obj.id)
        {
            X.pos = obj.pos;
            X.angle = obj.angle;
        }
    }
}
