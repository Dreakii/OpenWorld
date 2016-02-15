#ifndef MESH_INDEX_HPP_INCLUDED
#define MESH_INDEX_HPP_INCLUDED

class mesh_index // sciana mesh
{
 public:
    short int a;
    short int b;
    short int c;

    bool operator==( mesh_index other );
};

#endif // MESH_INDEX_HPP_INCLUDED
