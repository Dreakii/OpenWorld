#ifndef MESH_PRT_HPP_INCLUDED
#define MESH_PRT_HPP_INCLUDED

#include<set>

#include"mesh_vector.hpp"

using namespace std;

template<class T>
class mesh_prt
{
 public:
    typedef typename set<T>::iterator prt;
    prt a;
    prt b;
    prt c;

    mesh_prt( prt _a , prt _b , prt _c );
    bool operator==(mesh_prt other);
    mesh_vector move( Cvector vec);
};

#include"mesh_prt.cpp"

#endif // MESH_PRT_HPP_INCLUDED
