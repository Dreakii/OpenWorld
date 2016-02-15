//CCharacter.cpp

#include"CCharacter.hpp"

CCharacter::CCharacter() : pos(0,0,40) , angle(0){}

void CCharacter::download( string filename)
{
	model.SetFromFile(filename);
}

CCharacter CCharacter::GetBasic()
{
    return *this;
}
