// CControllableCharacter.cpp

#include "CControllableCharacter.hpp"

CControllableCharacter::CControllableCharacter() : CCharacter()
{
    speed = 0;
    foward_x = 250;
    foward_y = 250;
    going_up = false;
    going_left = false;
    going_down = false;
    going_right = false;

    foward_right = false;
    foward_left = false;
}

void CControllableCharacter::proggress()
{
	static glm::ivec3 vec1 , vec2;
	vec1 = glm::ivec3(round(pos.x),round(pos.y),round(pos.z-1.50001));
	vec2 = glm::ivec3(round(pos.x),round(pos.y),round(pos.z-0.50001));
	if(world->GetObj(vec1).id != 0) ///!
	{
		if(world->GetObj(vec2).id != 0)
		{
			pos.z = world->Parameter[world->GetObj(vec2).id].layer.heightest(pos.x , pos.y) + (int)vec2.z+1;
		}
		if(falling)
			pos.z -= 0.5;
		if( pos.z <= world->Parameter[world->GetObj(vec1).id].layer.heightest(pos.x , pos.y) + (int)vec1.z+1 )
		{
			pos.z = world->Parameter[world->GetObj(vec1).id].layer.heightest(pos.x , pos.y) + (int)vec1.z+1;
			falling = false;
		}
		else
			falling = true;
	}
	else
	{
		pos.z -= 0.5;
	}
	if(going_up == true)
	{
		pos.y += cos(( angle * M_PI ) / 180.0f)/10;
		pos.x += sin(( angle * M_PI ) / 180.0f)/10;
		going_up = false;
	}
	if(going_down == true)
	{
		pos.y -= cos(( angle * M_PI ) / 180.0f)/10;
		pos.x -= sin(( angle * M_PI ) / 180.0f)/10;
		going_down = false;
	}
	if(going_left == true)
	{
		pos.y -= cos((( angle + 90.f ) * M_PI ) / 180.0f)/10;
		pos.x -= sin((( angle + 90.f ) * M_PI ) / 180.0f)/10;
		going_left = false;
	}
	if(going_right == true)
	{
		pos.y += cos((( angle + 90.f ) * M_PI ) / 180.0f)/10;
		pos.x += sin((( angle + 90.f ) * M_PI ) / 180.0f)/10;
		going_right = false;
	}
	if(foward_right == true)
	{
		angle += 3.0f;
		foward_right = false;
	}
	if(foward_left == true)
	{
		angle -= 3.0f;
		foward_left = false;
	}
	world->center = glm::ivec3(pos.x/16,pos.y/16,pos.z/16);///CSite::identify(glm::ivec3(pos)).first;
}
