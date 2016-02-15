//BasicType\mesh_index.cpp

#include "mesh_index.hpp"

bool mesh_index::operator==( mesh_index other )
{
    if( ((a == other.a) and (b == other.b) and (c == other.c))
                        or
        ((b == other.a) and (c == other.b) and(a == other.c))
                        or
        ((c == other.a) and (a == other.b) and (b == other.c)) )
        return true;
    return false;
}
