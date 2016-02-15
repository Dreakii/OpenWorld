//CGenerator.cpp

#include"CGenerator.hpp"

#include <fstream>

CGenerator::CGenerator(int x , int y , int z) : X(x) , Y(y) , Z(z)
{
	field.reserve(X*Y*Z);
	field.insert( field.begin() , size() , 0 );
	null = 0;
}

short& CGenerator::GetObj(glm::ivec3 vec)
{
	int pos = vec.x + vec.y*X + vec.z*X*Y;

	if(pos >= 0 and pos < size())
		return field[pos].id;
	else
	{
		static short null(0);
		return null;
	}
}
int CGenerator::size()
{
	return X*Y*Z;
}
void CGenerator::clear()
{
	field.insert( field.begin() , size() , 0 );
}
void CGenerator::copy_vector(vector<Cobject> wektor)
{
	field=wektor;
}
bool CGenerator::surrounded(glm::ivec3 vec)
{
	if(vec.z == -1)
		return true;
	bool is = true;
		for(int k = -1 ; k < 2 ; k++)
			for(int l = -1 ; l < 2 ; l++)
				if( GetObj(glm::ivec3(vec.x+k,vec.y+l,vec.z)) != 1 )
					is = false;
	return is;
}

void CGenerator::fill(int from , int to , int id = 1 )
{
	for(int z = from ; z < to ; z++)
		for(int i = 0 ; i < X ; i++)
			for(int j = 0 ; j < Y ; j++)
				if(GetObj(glm::ivec3(i,j,z)) != 1)
					GetObj(glm::ivec3(i,j,z)) = id;
}

void CGenerator::smooth(int z , int id)
{
    bool start = false;
    for(int i = 1 ; i < X-1 ; i++)
    {
        for(int j = 1 ; j < Y-1 ; j++)
        {
            if(GetObj(glm::ivec3(i,j,z)) == id)
            {
                if(GetObj(glm::ivec3(i-1,j,z)) == 0 and GetObj(glm::ivec3(i-2,j,z)) == id)
                    GetObj(glm::ivec3(i-1,j,z)) = id;

                if(GetObj(glm::ivec3(i+1,j,z)) == 0 and GetObj(glm::ivec3(i+2,j,z)) == id)
                    GetObj(glm::ivec3(i+1,j,z)) = id;

                if(GetObj(glm::ivec3(i,j-1,z)) == 0 and GetObj(glm::ivec3(i,j-2,z)) == id)
                    GetObj(glm::ivec3(i,j-1,z)) = id;

                if(GetObj(glm::ivec3(i,j+1,z)) == 0 and GetObj(glm::ivec3(i,j+2,z)) == id)
                    GetObj(glm::ivec3(i,j+1,z)) = id;



                if(GetObj(glm::ivec3(i-1,j,z)) == 0 and GetObj(glm::ivec3(i-2,j,z)) == 0 and GetObj(glm::ivec3(i-3,j,z)) == id)
                {
                    GetObj(glm::ivec3(i-1,j,z)) = id;
                    GetObj(glm::ivec3(i-2,j,z)) = id;
                }
                if(GetObj(glm::ivec3(i+1,j,z)) == 0 and GetObj(glm::ivec3(i+2,j,z)) == 0 and GetObj(glm::ivec3(i+3,j,z)) == id)
                {
                    GetObj(glm::ivec3(i+1,j,z)) = id;
                    GetObj(glm::ivec3(i+2,j,z)) = id;
                }

                if(GetObj(glm::ivec3(i,j-1,z)) == 0 and GetObj(glm::ivec3(i,j-2,z)) == 0 and GetObj(glm::ivec3(i,j-3,z)) == id)
                {
                    GetObj(glm::ivec3(i,j-1,z)) = id;
                    GetObj(glm::ivec3(i,j-2,z)) = id;
                }

                if(GetObj(glm::ivec3(i,j+1,z)) == 0 and GetObj(glm::ivec3(i,j+2,z)) == 0 and GetObj(glm::ivec3(i,j+3,z)) == id)
                {
                    GetObj(glm::ivec3(i,j+1,z)) = id;
                    GetObj(glm::ivec3(i,j+2,z)) = id;
                }
            }
        }
    }
	/*int interval = 0;
	bool start = false;
	for(int i = 1 ; i < X-1 ; i++)
	{
		start = false;
		interval = 0;
		for(int j = 1 ; j < Y-1 ; j++)
		{
			if(GetObj(glm::ivec3(i,j,z)) == id)
			{
				if( (start) and (interval < 3) and (interval != 0))
				{
					GetObj(glm::ivec3(i,j-1,z)) = id;
					GetObj(glm::ivec3(i,j-2,z)) = id;
				}
				start = true;
				interval = -1;
			}
			interval++;
		}
	}
	for(int i = 1 ; i < X-1 ; i++)
	{
		start = false;
		interval = 0;
		for(int j = 1 ; j < Y-1 ; j++)
		{
			if(GetObj(glm::ivec3(j,i,z)) == id)
			{
				if( (start) and (interval < 3) and (interval != 0))
				{
					GetObj(glm::ivec3(j-1,i,z)) = id;
					GetObj(glm::ivec3(j-2,i,z)) = id;
				}
				start = true;
				interval = -1;
			}
			interval++;
		}
	}*/
}

void CGenerator::smoothing(int from , int to)
{
	for(int i = from ; i < to ; i++)
	{
		smooth(i,1);
		smooth(i,1);
		smooth(i,1);
	}
}

void CGenerator::round()
{
	for(int k = 0 ; k < Z ; k++)
		for(int i = 1 ; i < X-1 ; i++)
			for(int j = 1 ; j < Y-1 ; j++)
				if(GetObj(glm::ivec3(i,j,k)) == 0)
				{
					if(GetObj(glm::ivec3(i+1,j,k)) == 1)
					{
						if(GetObj(glm::ivec3(i,j+1,k)) == 1)
						{
								GetObj(glm::ivec3(i,j,k)) = 12;
								continue;
						}
							if(GetObj(glm::ivec3(i,j-1,k)) == 1)
						{
								GetObj(glm::ivec3(i,j,k)) = 13;
								continue;
						}
						GetObj(glm::ivec3(i,j,k)) = 5;
						continue;
					}
					if(GetObj(glm::ivec3(i-1,j,k)) == 1)
					{
						if(GetObj(glm::ivec3(i,j+1,k)) == 1)
						{
								GetObj(glm::ivec3(i,j,k)) = 11;
								continue;
						}
							if(GetObj(glm::ivec3(i,j-1,k)) == 1)
						{
								GetObj(glm::ivec3(i,j,k)) = 10;
								continue;
						}
						GetObj(glm::ivec3(i,j,k)) = 3;
						continue;
					}
					if(GetObj(glm::ivec3(i,j+1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 4;
						continue;
					}
					if(GetObj(glm::ivec3(i,j-1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 2;
						continue;
					}



					if(GetObj(glm::ivec3(i-1,j-1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 7;
						continue;
					}
					if(GetObj(glm::ivec3(i+1,j+1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 9;
						continue;
					}
					if(GetObj(glm::ivec3(i+1,j-1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 6;
						continue;
					}
					if(GetObj(glm::ivec3(i-1,j+1,k)) == 1)
					{
						GetObj(glm::ivec3(i,j,k)) = 8;
						continue;
					}
				}
}

void CGenerator::print()
{
	fstream swiat("swiat.txt",ios::out);
	for(int i = 0 ; i < X ; i++)
	{
		for(int j = 0 ; j < Y ; j++)
		{
			if(GetObj(glm::ivec3(i,j,0)) == 1)
			{
				int hight = 0;
				for(int k = 0 ; k < Z ; k++)
					if(GetObj(glm::ivec3(i,j,k)) == 1)
						hight++;
				swiat << hight%10;
			}
			else
				swiat << ".";
		}
		swiat << endl;
	}
}
void CGenerator::carve(glm::ivec3 vec , int r , int id)
{
	for(int x = vec.x-r-1 ; x < vec.x+r+1 ; x++)
		for(int y = vec.y-r-1 ; y < vec.y+r+1 ; y++)
			for(int z = vec.z-r-1 ; z < vec.z+r+1 ; z++)
			{
				if(pow(x-vec.x,2)+pow(y-vec.y,2)+pow(z-vec.z,2) <= pow(r,2))
					GetObj(glm::ivec3(x,y,z)) = id;
			}
}

bool CGenerator::inrange(glm::ivec3 vec)
{
	if(vec.x > 0 and vec.x < X-1 and vec.y > 0 and vec.y < Y-1 and vec.z > 0)
		return true;
	else
		return false;
}
