//BasicType\Cvector.hpp
#ifndef CVECTOR_HPP_INCLUDED
#define CVECTOR_HPP_INCLUDED

class Cvector // vector punktu
{
 public:
    float x;
    float y;
    float z;

    Cvector(float x_ , float y_ , float z_);
    Cvector operator+( const Cvector& b ) const;
    friend bool operator==( Cvector a , Cvector b );
    friend bool operator<(Cvector a , Cvector b);
};

#endif // CVECTOR_HPP_INCLUDED
