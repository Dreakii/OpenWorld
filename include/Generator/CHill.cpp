//CHill.cpp

#include"CHill.hpp"

CHill::CHill(int x , int y , int z) : CGenerator(x,y,z){}

int CHill::LayerSize(int z)
{
    int count = 0;
    for(int i = 1 ; i < X-1 ; i++)
        for(int j = 1 ; j < Y-1 ; j++)
        {
            if(surrounded(glm::ivec3(i,j,z)))
                count++;
        }
    return count;
}

int CHill::generate(int power , float severity )
{
    int basic_power = power;
    for(int i = 1 ; i < Z ; i++)
    {
        if(i != 0)
        {
            power = LayerSize(i-1) * severity;
        }
        level( power , i );
        smooth(i,1);
        smooth(i,1);
        smooth(i,1);
    }
    //smoothing(0,Z);
    //print();
    //round();
}

void CHill::level( int power , int z)
{
    //if(power < 10)
    //    return;
    int x = 0,y = 0;
    vector<int> array;
    int end = 0;

    if(z != 0)
    {
        for(int i = 0 ; i < 30 ; i++)
        {
            do
            {
                x = rand()%X;
                y = rand()%Y;
            }while(!surrounded(glm::ivec3(x,y,z-1)));
            GetObj(glm::ivec3(x,y,z)) = 1;

            if(surrounded(glm::ivec3(x+1,y,z-1)))
            {
                array.push_back(x+1);
                array.push_back(y);
                GetObj(glm::ivec3(x+1,y,z)) = 2;
                end += 2;
            }
            if(surrounded(glm::ivec3(x,y+1,z-1)))
            {
                array.push_back(x);
                array.push_back(y+1);
                GetObj(glm::ivec3(x,y+1,z)) = 2;
                end += 2;
            }
            if(surrounded(glm::ivec3(x-1,y,z-1)))
            {
                array.push_back(x-1);
                array.push_back(y);
                GetObj(glm::ivec3(x-1,y,z)) = 2;
                end += 2;
            }
            if(surrounded(glm::ivec3(x,y-1,z-1)))
            {
                array.push_back(x);
                array.push_back(y-1);
                GetObj(glm::ivec3(x,y-1,z)) = 2;
                end += 2;
            }
        }
    }
    else
    {
        for(int i = 0 ; i < 625 ; i++)
        {
            x = 0.1*X+(rand()%((int)(X*0.8)));
            y = 0.1*Y+(rand()%((int)(Y*0.8)));
            GetObj(glm::ivec3(x,y,z)) = 1;
            array.push_back(x+1);
            array.push_back(y);
            array.push_back(x);
            array.push_back(y+1);
            array.push_back(x-1);
            array.push_back(y);
            array.push_back(x);
            array.push_back(y-1);
            GetObj(glm::ivec3(x+1,y,z)) = 2;
            GetObj(glm::ivec3(x,y+1,z)) = 2;
            GetObj(glm::ivec3(x-1,y,z)) = 2;
            GetObj(glm::ivec3(x,y-1,z)) = 2;
            end += 8;
        }
    }
    int offset;
    while(power != 0 and end != 0)
    {
        power--;
        if(end == 0)
            cout << "fail" << endl;
        offset = (rand()%end)/2;
        offset *= 2;

        x = array[offset];
        y = array[offset+1];
        if(GetObj(glm::ivec3(x,y,z)) == 2)
            GetObj(glm::ivec3(x,y,z)) = 1;

        array[offset] = array[end-2];
        array[offset+1] = array[end-1];

        end -= 2;

        if(surrounded(glm::ivec3(x+1,y,z-1)) and GetObj(glm::ivec3(x+1,y,z)) == 0 and x+1 > 0 and x+1 < X-1 and y > 0 and y < Y-1)
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
            GetObj(glm::ivec3(x+1,y,z)) = 2;
            end += 2;
        }
        if(surrounded(glm::ivec3(x,y+1,z-1)) and GetObj(glm::ivec3(x,y+1,z)) == 0 and x > 0 and x < X-1 and y+1 > 0 and y+1 < Y-1)
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
            GetObj(glm::ivec3(x,y+1,z)) = 2;
            end += 2;
        }
        if(surrounded(glm::ivec3(x-1,y,z-1)) and GetObj(glm::ivec3(x-1,y,z)) == 0 and x-1 > 0 and x-1 < X-1 and y > 0 and y < Y-1)
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
            GetObj(glm::ivec3(x-1,y,z)) = 2;
            end += 2;
        }
        if(surrounded(glm::ivec3(x,y-1,z-1)) and GetObj(glm::ivec3(x,y-1,z)) == 0 and x > 0 and x < X-1 and y-1 > 0 and y-1 < Y-1)
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
            GetObj(glm::ivec3(x,y-1,z)) = 2;
            end += 2;
        }
    }
    for(int i = 1 ; i < X-1 ; i++)
        for(int j = 1 ; j < Y-1 ; j++)
            if(GetObj(glm::ivec3(i,j,z)) == 2)
                GetObj(glm::ivec3(i,j,z)) = 0;
}
