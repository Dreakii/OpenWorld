#include "CTextureArray.hpp"

unsigned char* CTextureArray::downloadBMP(string filename)
{
    sf::Image tex;
    tex.loadFromFile(filename);
    size = tex.getSize().x*tex.getSize().y*3;
    width = tex.getSize().x;
    height = tex.getSize().y;

    unsigned char* buffer = new unsigned char[size];
    int j = 0;
    for(int i = 0 ; i < size ; i++)
    {
        buffer[size-i-1] = (unsigned char)tex.getPixelsPtr()[j];
        j++;
        if(j%4 == 3)
        {
            j++;
        }
    }

    unsigned char temp;     // zmienna pomocnicza zamiany danych
    for( int i = 0 ; i < size ; i+= 3)     // zamiana formatu BGR na RGB
    {
        temp = buffer[i];
        buffer[i] = buffer[ i + 2 ];
        buffer[ i + 2 ] = temp;
    }
    return buffer;
}

CTextureArray::CTextureArray(string filename , int _deepth) : counter(0)
{
    deepth = _deepth;
    glGenTextures(1,&texId);
    glBindTexture(GL_TEXTURE_2D_ARRAY,texId);

    unsigned char* data;
    data = downloadBMP(filename);

    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_MIN_FILTER , GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_MAG_FILTER , GL_LINEAR_MIPMAP_LINEAR);

    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE);

    glPixelStorei(GL_UNPACK_ALIGNMENT , 1);
    glTexImage3D(GL_TEXTURE_2D_ARRAY , 0 , GL_RGB , width , height , deepth , 0 , GL_RGB , GL_UNSIGNED_BYTE , NULL);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , counter , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data );
    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
}

void CTextureArray::add(string filename)
{
    counter++;
    unsigned char* data;
    data = downloadBMP(filename);
    ///glTexImage3D(GL_TEXTURE_2D_ARRAY , 0 , GL_RGB , width , height , deepth , 0 , GL_RGB , GL_UNSIGNED_BYTE , NULL);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , counter , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data );
    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
}
