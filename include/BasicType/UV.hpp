//BasicType\UV.hpp
#ifndef UV_HPP_INCLUDED
#define UV_HPP_INCLUDED

class UV // punkt tekstury
{
 public:
    float u;
    float v;
    float s;

    UV();
    bool operator==( UV b ) const;
    friend bool operator<(UV a , UV b);
};



#endif // UV_HPP_INCLUDED
