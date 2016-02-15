#ifndef CREMOTECHARACTERBASE_HPP_INCLUDED
#define CREMOTECHARACTERBASE_HPP_INCLUDED

#include <vector>

#include "CRemoteCharacter.hpp"

using namespace std;

class CRemoteCharacterBase
{
 public:
    list<CRemoteCharacter> base;
    bool need_add;

    CRemoteCharacterBase();
    void add(std::remove_reference<CRemoteCharacter>::type new_obj);
    void refreshBase(CRemoteCharacterBase new_base);
    void refreshElement(CRemoteCharacter obj );
};

#endif // CREMOTECHARACTERBASE_HPP_INCLUDED
