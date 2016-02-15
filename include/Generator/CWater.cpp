//CWater.cpp

#include"CWater.hpp"

CWater::CWater(int a , int b , int c) : CGenerator(a,b,c) , end(0){}

void CWater::add(glm::ivec3 vec)
{
    if(end == array.size())
    {
        array.push_back(vec.x);
        array.push_back(vec.y);
        array.push_back(vec.z);
    }
    else
    {
        array[end] = vec.x;
        array[end+1] = vec.y;
        array[end+2] =vec.z;
    }
    end += 3;
    GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
}

void CWater::generate(glm::ivec3 source)
{
    source.z = 0;
    while(GetObj(glm::ivec3(source.x,source.y,source.z)) == 1)
        source.z++;
    array.push_back(source.x);
    array.push_back(source.y);
    array.push_back(source.z);
    end += 3;
    GetObj(glm::ivec3(source.x,source.y,source.z)) = 37;

    int offset;
    int x,y,z;
    while(end > 0)
    {
        offset = (rand()%end)/3;
        offset *= 3;
        x = array[offset];
        y = array[offset+1];
        z = array[offset+2];
        array[offset] = array[end-3];
        array[offset+1] = array[end-2];
        array[offset+2] = array[end-1];
        end -= 3;

        glm::ivec3 vec;
        int obj;

        vec = glm::ivec3(x+1,y,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x-1,y,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x,y+1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x,y-1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 35 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x+1,y+1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x-1,y-1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x+1,y-1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }

        vec = glm::ivec3(x-1,y+1,z);
        obj = GetObj(vec);
        if(obj == 0 and obj != 37 and GetObj(vec+glm::ivec3(0,0,-1)) == 1 and inrange(vec))
            add(vec);
        else
        {
            GetObj(glm::ivec3(vec.x,vec.y,vec.z)) = 37;
            if(GetObj(vec+glm::ivec3(0,0,-1)) != 1 and GetObj(vec+glm::ivec3(0,0,-1)) != 37)
                add(vec+glm::ivec3(0,0,-1));
        }
    }
}
