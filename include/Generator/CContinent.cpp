#include "CContinent.hpp"

CContinent::CContinent(int _area_size , glm::ivec2 _continent_size) : CGenerator(_continent_size.x , _continent_size.y , 1)
{
    area_size = _area_size;
    continent_size = _continent_size;
    surface.reserve(area_size*area_size);
    surface.insert( surface.begin() , size() , 0 );
    superficies = 0;
}

int CContinent::GetUnit(glm::ivec2 vec)
{
    return vec.x + vec.y*area_size;
}

void CContinent::border(int x , int y)
{
    if(x > x_max)
        x_max = x;
    if(x < x_min)
        x_min = x;
    if(y > y_max)
        y_max = y;
    if(y < y_min)
        y_min = y;
}

void CContinent::genContinents(int power , int seeds)
{
    int x = 0,y = 0;
    vector<int> array;
    int end = 0;
    for(int i = 0 ; i < seeds ; i++)
    {
        x = rand()%(area_size-2)+1;
        y = rand()%(area_size-2)+1;
        surface[GetUnit(glm::ivec2(x,y))] = 1;
        array.push_back(x+1);
        array.push_back(y);
        array.push_back(x);
        array.push_back(y+1);
        array.push_back(x-1);
        array.push_back(y);
        array.push_back(x);
        array.push_back(y-1);
        surface[GetUnit(glm::ivec2(x+1,y))] = 2;
        surface[GetUnit(glm::ivec2(x,y+1))] = 2;
        surface[GetUnit(glm::ivec2(x-1,y))] = 2;
        surface[GetUnit(glm::ivec2(x,y-1))] = 2;
        end += 8;
    }
    int offset;
    while(power != 0 and end > 0)
    {
        power--;
        offset = (rand()%end)/2;
        offset *= 2;

        x = array[offset];
        y = array[offset+1];
        if(surface[GetUnit(glm::ivec2(x,y))] == 2)
            surface[GetUnit(glm::ivec2(x,y))] = 1;

        array[offset] = array[end-2];
        array[offset+1] = array[end-1];

        end -= 2;

        if( x+1 >= 0 and x+1 < area_size and y >= 0 and y < area_size and surface[GetUnit(glm::ivec2(x+1,y))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x+1);
                array.push_back(y);
            }
            else
            {
                array[end] = x+1;
                array[end+1] = y;
            }
            surface[GetUnit(glm::ivec2(x+1,y))] = 2;
            end += 2;
        }
        if( x >= 0 and x < area_size and y+1 >= 0 and y+1 < area_size and surface[GetUnit(glm::ivec2(x,y+1))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y+1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y+1;
            }
            surface[GetUnit(glm::ivec2(x,y+1))] = 2;
            end += 2;
        }
        if(x-1 >= 0 and x-1 < area_size and y >= 0 and y < area_size and surface[GetUnit(glm::ivec2(x-1,y))] == 0 )
        {
            if(end == array.size())
            {
                array.push_back(x-1);
                array.push_back(y);
            }
            else
            {
                array[end] = x-1;
                array[end+1] = y;
            }
            surface[GetUnit(glm::ivec2(x-1,y))] = 2;
            end += 2;
        }
        if( x >= 0 and x < area_size and y-1 >= 0 and y-1 < area_size and surface[GetUnit(glm::ivec2(x,y-1))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y-1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y-1;
            }
            surface[GetUnit(glm::ivec2(x,y-1))] = 2;
            end += 2;
        }
    }
    for(int i = 0 ; i < area_size ; i++)
        for(int j = 0 ; j < area_size ; j++)
            if(surface[GetUnit(glm::ivec2(i,j))] == 2)
                surface[GetUnit(glm::ivec2(i,j))] = 0;
}

CGenerator CContinent::GetContinent()
{
    superficies = 0;
    vector<int> array;
    int end = 0;
    int x,y;
    do
    {
        x = rand()%(area_size-2)+1;
        y = rand()%(area_size-2)+1;
    }
    while(surface[GetUnit(glm::ivec2(x,y))] != 0);
    ///GetObj(glm::ivec3(x,y,0)) = 1;
    surface[GetUnit(glm::ivec2(x,y))] = 3;
    x_max = x_min = x;
    y_max = y_min = y;
    array.push_back(x+1);
    array.push_back(y);
    array.push_back(x);
    array.push_back(y+1);
    array.push_back(x-1);
    array.push_back(y);
    array.push_back(x);
    array.push_back(y-1);
    surface[GetUnit(glm::ivec2(x+1,y))] = 2;
    surface[GetUnit(glm::ivec2(x,y+1))] = 2;
    surface[GetUnit(glm::ivec2(x-1,y))] = 2;
    surface[GetUnit(glm::ivec2(x,y-1))] = 2;
    end += 8;

    int offset;
    while( end > 0 )
    {
        offset = (rand()%end)/2;
        offset *= 2;

        x = array[offset];
        y = array[offset+1];
        if(surface[GetUnit(glm::ivec2(x,y))] == 2)
        {
            surface[GetUnit(glm::ivec2(x,y))] = 3;
            border(x,y);
            ///GetObj(glm::ivec3(x,y,0)) = 1;
        }

        array[offset] = array[end-2];
        array[offset+1] = array[end-1];

        end -= 2;

        if( x+1 >= 0 and x+1 < area_size and y >= 0 and y < area_size and surface[GetUnit(glm::ivec2(x+1,y))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x+1);
                array.push_back(y);
            }
            else
            {
                array[end] = x+1;
                array[end+1] = y;
            }
            surface[GetUnit(glm::ivec2(x+1,y))] = 2;
            end += 2;
        }
        if( x >= 0 and x < area_size and y+1 >= 0 and y+1 < area_size and surface[GetUnit(glm::ivec2(x,y+1))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y+1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y+1;
            }
            surface[GetUnit(glm::ivec2(x,y+1))] = 2;
            end += 2;
        }
        if(x-1 >= 0 and x-1 < area_size and y >= 0 and y < area_size and surface[GetUnit(glm::ivec2(x-1,y))] == 0 )
        {
            if(end == array.size())
            {
                array.push_back(x-1);
                array.push_back(y);
            }
            else
            {
                array[end] = x-1;
                array[end+1] = y;
            }
            surface[GetUnit(glm::ivec2(x-1,y))] = 2;
            end += 2;
        }
        if( x >= 0 and x < area_size and y-1 >= 0 and y-1 < area_size and surface[GetUnit(glm::ivec2(x,y-1))] == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y-1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y-1;
            }
            surface[GetUnit(glm::ivec2(x,y-1))] = 2;
            end += 2;
        }
    }
    ///for(int i = 0 ; i < area_size ; i++)
    ///   for(int j = 0 ; j < area_size ; j++)
    ///       if(surface[GetUnit(glm::ivec2(i,j))])
    ///           GetObj(glm::ivec3(i,j,0)) = 1;
    if( y_max >= area_size-1 or x_max >= area_size-1 or y_min <= 0 or x_min <= 0)
        return GetContinent();
    ///cout << x_max << " " << y_max << " " << x_min << " " << y_min << endl;

    int x_size = x_max - x_min;
    int y_size = y_max - y_min;
    int scale = (x_size > y_size)?(area_size/x_size):(area_size/y_size);
    if(scale > 3)
        scale = 3;
    scale--;
    int shift_x = area_size/2 - (x_size*scale)/2;
    int shift_y = area_size/2 - (y_size*scale)/2;
    for(int i = 0 ; i < x_size ; i++)
        for(int j = 0 ; j < y_size ; j++)
        {
            for(int k = i*scale ; k < (i+1)*scale ; k++)
                for(int l = j*scale ; l < (j+1)*scale ; l++)
                {
                    if(surface[GetUnit(glm::ivec2(i+x_min,j+y_min))] == 3)
                        GetObj(glm::ivec3(k+shift_x,l+shift_y,0)) = 1;
                        superficies++;
                }
        }
    for(int k = 0 ; k < scale ; k++)
        for(int i = 0 ; i < area_size ; i++)
            for(int j = 0 ; j < area_size ; j++)
                if(GetObj(glm::ivec3(i,j,0)) == 1)
                {
                    if(GetObj(glm::ivec3(i+1,j,0)) == 0)
                        if(rand()%3 ==  1)
                        {
                            GetObj(glm::ivec3(i+1,j,0)) = 1;
                            border(i+1,j);
                            superficies++;
                        }
                    if(GetObj(glm::ivec3(i,j+1,0)) == 0)
                        if(rand()%3 ==  1)
                        {
                            GetObj(glm::ivec3(i,j+1,0)) = 1;
                            border(i,j+1);
                            superficies++;
                        }
                    if(GetObj(glm::ivec3(i-1,j,0)) == 0)
                        if(rand()%3 ==  1)
                        {
                            GetObj(glm::ivec3(i-1,j,0)) = 1;
                            border(i-1,j);
                            superficies++;
                        }
                    if(GetObj(glm::ivec3(i,j-1,0)) == 0)
                        if(rand()%3 ==  1)
                        {
                            GetObj(glm::ivec3(i,j-1,0)) = 1;
                            border(i,j-1);
                            superficies++;
                        }
                }
    smooth(0,1);
    smooth(0,1);
    smooth(0,1);
    x_size = x_max - x_min;
    y_size = y_max - y_min;
    CHill hill(x_size,y_size,10); ///! 10
    for(int i = x_min ; i < x_max ; i++)
        for(int j = y_min ; j < y_max ; j++)
        {
            if(GetObj(glm::ivec3(i,j,0)) == 1)
            {
                hill.GetObj(glm::ivec3(i-x_min,j-y_min,0)) = 1;
            }
        }
    hill.generate(superficies*0.8 , 0.8);
    return std::move((CGenerator)hill);
}

