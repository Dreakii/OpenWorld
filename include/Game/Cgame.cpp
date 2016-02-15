//Cgame.cpp

#include"Cgame.hpp"

CGame::CGame() : Rudder( &graphic.cam , &hero ) , graphic()
{
	rendering = false;
	adding = false;

	hero.world = &World;
	hero.download("data/hero");
	graphic.add_model( &hero );
}

void CGame::generate()
{
    for(int i = 0 ; i < World.Site.size() ; i++)
        for(int j = 0 ; j < 4096*8; j++)
        {
            if(World.Site.at(i).Chunk[j].plane.mesh.size()!= 0)
            {
                graphic.add(&World.Site.at(i).Chunk[j].plane , glm::vec3(CSite::decode(j))*glm::vec3(16,16,16)+glm::vec3(World.Site.at(i).position*glm::ivec3(512,512,512))); ///!+ glm::ivec3(World[i].Site*512,0));
            }
        }
	adding = false;
	rendering = true;
}

void CGame::GameTool()
{

    if(other_characters.need_add == true)
    {
        for(CRemoteCharacter& X : other_characters.base)
        {
            if(X.added == false)
            {
                graphic.add_model(&X);
                X.added = true;
            }
        }
        other_characters.need_add = false;
    }
	if(rendering)
		graphic.render();
}
void CGame::Reactor()
{
	Rudder.Reaction();
    hero.proggress();
}
