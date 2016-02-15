// CTree.cpp

#include"CTree.hpp"

CTree::CTree(int x , int y , int z) : CGenerator(x,y,z){}

void CTree::generate(int power)
{
    int x = X/2,y = Y/2,z = Z/2;
    GetObj(glm::ivec3(x,y,z)) = 34;
    int end = 0;
    vector<int> array;

    array.push_back(x+1);
    array.push_back(y);
    array.push_back(z);
    array.push_back(x-1);
    array.push_back(y);
    array.push_back(z);

    array.push_back(x);
    array.push_back(y+1);
    array.push_back(z);
    array.push_back(x);
    array.push_back(y-1);
    array.push_back(z);

    array.push_back(x);
    array.push_back(y);
    array.push_back(z+1);
    array.push_back(x);
    array.push_back(y);
    array.push_back(z-1);

    end = array.size();
    int offset;
    while(power != 0)
    {
        power--;
        offset = (rand()%end)/3;
        offset *= 3;
        x = array[offset];
        y = array[offset+1];
        z = array[offset+2];

        GetObj(glm::ivec3(x,y,z)) = 34;

        array[offset] = array[end-3];
        array[offset+1] = array[end-2];
        array[offset+2] = array[end-1];

        end -= 3;

        if(GetObj(glm::ivec3(x+1,y,z)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x+1);
                array.push_back(y);
                array.push_back(z);
            }
            else
            {
                array[end] = x+1;
                array[end+1] = y;
                array[end+2] = z;
            }
            end +=3;
        }
        if(GetObj(glm::ivec3(x-1,y,z)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x-1);
                array.push_back(y);
                array.push_back(z);
            }
            else
            {
                array[end] = x-1;
                array[end+1] = y;
                array[end+2] = z;
            }
            end +=3;
        }
        if(GetObj(glm::ivec3(x,y+1,z)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y+1);
                array.push_back(z);
            }
            else
            {
                array[end] = x;
                array[end+1] = y+1;
                array[end+2] = z;
            }
            end +=3;
        }
        if(GetObj(glm::ivec3(x,y-1,z)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y-1);
                array.push_back(z);
            }
            else
            {
                array[end] = x;
                array[end+1] = y-1;
                array[end+2] = z;
            }
            end +=3;
        }
        if(GetObj(glm::ivec3(x,y,z+1)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y);
                array.push_back(z+1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y;
                array[end+2] = z+1;
            }
            end +=3;
        }
        if(GetObj(glm::ivec3(x,y,z-1)) == 0)
        {
            if(end == array.size())
            {
                array.push_back(x);
                array.push_back(y);
                array.push_back(z-1);
            }
            else
            {
                array[end] = x;
                array[end+1] = y;
                array[end+2] = z-1;
            }
            end +=3;
        }
    }
    for(int i = 0 ; i < Z ; i++)
    {
        smooth(i,34);
        smooth(i,34);
        smooth(i,34);
    }

    for(int i = 0 ; i < 15 ; i++){
        GetObj(glm::ivec3(X/2,Y/2+1,i)) = 14;
        GetObj(glm::ivec3(X/2+1,Y/2+1,i)) = 15;
        GetObj(glm::ivec3(X/2+1,Y/2,i)) = 16;
        GetObj(glm::ivec3(X/2,Y/2,i)) = 17;
    }
    int beg = (rand()%5)+7;
    int i = 0;
    while(GetObj(glm::ivec3(X/2-1-i-1,Y/2+1,beg+i+1)) == 34)
    {
        GetObj(glm::ivec3(X/2-1-i,Y/2+1,beg+i)) = 18;
        GetObj(glm::ivec3(X/2-1-i,Y/2+0,beg+i)) = 19;
        GetObj(glm::ivec3(X/2-1-i,Y/2+1,beg+i+1)) = 20;
        GetObj(glm::ivec3(X/2-1-i,Y/2+0,beg+i+1)) = 21;
        i++;
    }

    i = 0;
    beg = (rand()%5)+7;
    while(GetObj(glm::ivec3(X/2+2+i+1,Y/2+1,beg+i+1)) == 34)
    {
        GetObj(glm::ivec3(X/2+2+i,Y/2+1,beg+i)) = 23;
        GetObj(glm::ivec3(X/2+2+i,Y/2+0,beg+i)) = 22;
        GetObj(glm::ivec3(X/2+2+i,Y/2+1,beg+i+1)) = 25;
        GetObj(glm::ivec3(X/2+2+i,Y/2+0,beg+i+1)) = 24;
        i++;
    }
    i = 0;
    beg = (rand()%5)+7;
    while(GetObj(glm::ivec3(X/2+1,Y/2+2+i+1,beg+i+1)) == 34)
    {
        GetObj(glm::ivec3(X/2+1,Y/2+2+i,beg+i)) = 26;
        GetObj(glm::ivec3(X/2+0,Y/2+2+i,beg+i)) = 27;
        GetObj(glm::ivec3(X/2+1,Y/2+2+i,beg+i+1)) = 28;
        GetObj(glm::ivec3(X/2+0,Y/2+2+i,beg+i+1)) = 29;
        i++;
    }
    i = 0;
    beg = (rand()%5)+7;
    while(GetObj(glm::ivec3(X/2+1,Y/2-1-i-1,beg+i+1)) == 34)
    {
        GetObj(glm::ivec3(X/2+1,Y/2-1-i,beg+i)) = 31;
        GetObj(glm::ivec3(X/2+0,Y/2-1-i,beg+i)) = 30;
        GetObj(glm::ivec3(X/2+1,Y/2-1-i,beg+i+1)) = 33;
        GetObj(glm::ivec3(X/2+0,Y/2-1-i,beg+i+1)) = 32;
        i++;
    }
}
