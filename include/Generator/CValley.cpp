//CValley.cpp

#include"CValley.hpp"

CValley::CValley(int a , int b , int c) : CGenerator(a,b,c)
{

}
void CValley::generate(int r)
{
	vector<int> path;
	x = rand()%50+225;
	y = rand()%50+225;
	z = 0;
	while(GetObj(glm::ivec3(x,y,z)) == 1)
		z++;
	source = glm::ivec3(x,y,z);
	for(int i = y ; i < 500 ; i++)
	{
		while(GetObj(glm::ivec3(x,i,z-1)) != 1)
			z--;
		x += (rand()%2 == 0)?(-1):(1);
		path.push_back(x);
		path.push_back(i);
		path.push_back(z+r/2);
	}
	for(int i = 0 ; i < path.size() ; i +=3)
	{
		carve(glm::ivec3(path[i],path[i+1],path[i+2]),r,0);
	}
}
glm::ivec3 CValley::GetSource()
{
	return source;
}
