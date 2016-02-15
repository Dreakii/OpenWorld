#ifndef MESH_VECTOR_HPP_INCLUDED
#define MESH_VECTOR_HPP_INCLUDED

#include "Cvector.hpp"

class mesh_vector
{
 public:
    Cvector a;
    Cvector b;
    Cvector c;

    mesh_vector( Cvector _a , Cvector _b , Cvector _c ) : a(_a), b(_b), c(_c) {}
    bool operator==(const mesh_vector &other) const;
};

#endif // MESH_VECTOR_HPP_INCLUDED
