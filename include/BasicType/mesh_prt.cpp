//Basic_Type\mesh_prt.cpp

#ifndef MESH_PRT_CPP_INCLUDED
#define MESH_PRT_CPP_INCLUDED

#include "mesh_prt.hpp"

template<class T>
mesh_prt<T>::mesh_prt( prt _a , prt _b , prt _c )
{
    a = _a;
    b = _b;
    c = _c;
}

template<class T>
bool mesh_prt<T>::operator==(mesh_prt other)
{
    if( (*a == *other.a) and (*b == *other.b) and (*c == *other.c) )
        return true;
    if( (*a == *other.a) and (*c == *other.b) and (*a == *other.c) )
        return true;
    if( (*b == *other.a) and (*a == *other.b) and (*c == *other.c) )
        return true;
    if( (*b == *other.a) and (*c == *other.b) and (*a == *other.c) )
        return true;
    if( (*c == *other.a) and (*a == *other.b) and (*b == *other.c) )
        return true;
    if( (*c == *other.a) and (*b == *other.b) and (*a == *other.c) )
        return true;
    return false;
}

template<class T>
mesh_vector mesh_prt<T>::move( Cvector vec)
{
    return mesh_vector( *a + vec , *b + vec , *c + vec );
}

#endif
