//CAcreage.cpp

#include"CAcreage.hpp"

CAcreage::CAcreage(float north , float west , float south , float east , float centre) : north(north) , west(west) , south(south) , east(east) , centre(centre){}

float CAcreage::heightest(float x , float y)
{
    x += 0.5;
    y += 0.5;
    if(x < 0)
        x = -x;
    if(y < 0)
        y = -y;
    x -= (int)x;
    y -= (int)y;
    float z;
    float a;

    if( x > y)
    {
        if(x+y > 1)
        {
            z = west + (south - west)*y;
            a = west + (south - west)*0.5;
            a = (centre - a)*(1-((x-0.5)*2));
            z = z+a;
            return (z - (int)z == 0)?(1):(z - (int)z);
        }
        else
        {
            z = north + (west - north)*x;
            a = north + (west - north)*0.5;
            a = (centre - a)*(y*2);
            z = z+a;
            return (z - (int)z == 0)?(1):(z - (int)z);
        }
    }
    else
    {
        if(x+y > 1)
        {
            z = east + (south - east)*x;
            a = east + (south - east)*0.5;
            a = (centre - a)*(1-(y-0.5)*2);
            z = z+a;
            return (z - (int)z == 0)?(1):(z - (int)z);
        }
        else
        {
            z = north + (east - north)*y;
            a = north + (east - north)*0.5;
            a = (centre - a)*(x*2);
            z = z+a;
            return (z - (int)z == 0)?(1):(z - (int)z);
        }
    }
}

void CAcreage::recreate(float _north , float _west , float _south , float _east , float _centre)
{
    north = _north;
    east = _east;
    west = _west;
    south = _south;
    centre = _centre;
}

void CAcreage::print()
{
    cout << north << " " << west << " " << south << " " << east << " " << centre << " " << endl;
}
