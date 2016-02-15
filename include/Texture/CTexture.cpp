//CTexture.cpp

#include"CTexture.hpp"

unsigned char* CTexture::downloadBMP( char* namefile)
{
    /*fstream file(namefile , ios::in | ios::binary); // plik
    BITMAPFILEHEADER head; // naglowek pliku BMP
    BITMAPINFOHEADER info;
    unsigned char *buffer; // bufor obrazu

    file.read( (char*)&head, sizeof(BITMAPFILEHEADER) ); // laduje naglowek pliku
    if ( head.bfType != 0x4D42) // sprawdza typ pliku
    {
        return NULL; // bledny plik
    }
    file.read( (char*)&info, sizeof(BITMAPINFOHEADER) ); // czyta informacje o pliku
    height = info.biHeight; // ustawia wysokosc
    width = info.biWidth; // ustawia szerokosc
    size = info.biSizeImage; // ustawia wielkosc obrazu
    file.seekg(head.bfOffBits , ios::beg); // ustawia sie na danych obrazu
    buffer = new unsigned char[size]; // przydziela pamiec buforowi
    file.read( (char*)buffer , size); // czyta dane do bufora

    unsigned char temp;     // zmienna pomocnicza zamiany danych
    for( int i = 0 ; i < size ; i+= 3)     // zamiana formatu BGR na RGB
    {
        temp = buffer[i];
        buffer[i] = buffer[ i + 2 ];
        buffer[ i + 2 ] = temp;
    }

    return buffer; // zwraca bufor*/

    sf::Image tex;
    tex.loadFromFile(namefile);
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

CTexture::CTexture(char* filename)
{
    glGenTextures(1,&texId);
    glBindTexture(GL_TEXTURE_2D,texId);

    unsigned char* data ;
    data = downloadBMP(filename);

    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR_MIPMAP_LINEAR);

    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE);

    glPixelStorei(GL_UNPACK_ALIGNMENT , 1);
    glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , width , height , 0 , GL_RGB , GL_UNSIGNED_BYTE , data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

CTexture::CTexture(char* filename, char* filename2 , char* filename3, char* filename4 , char* filename5 , char* filename6 )
{
    glGenTextures(1,&texId);
    glBindTexture(GL_TEXTURE_2D_ARRAY,texId);

    unsigned char* data ;
    unsigned char* data2 ;
    unsigned char* data3 ;
    unsigned char* data4 ;
    unsigned char* data5 ;
    unsigned char* data6 ;
    data = downloadBMP(filename);
    data2 = downloadBMP(filename2);
    data3 = downloadBMP(filename3);
    data4 = downloadBMP(filename4);
    data5 = downloadBMP(filename5);
    data6 = downloadBMP(filename6);

    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_MIN_FILTER , GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_MAG_FILTER , GL_LINEAR_MIPMAP_LINEAR);

    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE);

    glPixelStorei(GL_UNPACK_ALIGNMENT , 1);
    glTexImage3D(GL_TEXTURE_2D_ARRAY , 0 , GL_RGB , width , height , 6 , 0 , GL_RGB , GL_UNSIGNED_BYTE , NULL);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 0 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data );
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 1 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data2 );
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 2 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data3 );
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 3 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data4 );
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 4 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data5 );
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY , 0 , 0 , 0 , 5 , width , height , 1 , GL_RGB , GL_UNSIGNED_BYTE , data6 );
    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
}

CTexture::CTexture(void)
{
    glGenTextures(1,&texId);
    glBindTexture(GL_TEXTURE_2D,texId);

    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_CLAMP_TO_EDGE);

    glPixelStorei(GL_UNPACK_ALIGNMENT , 1);
}
