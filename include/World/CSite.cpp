#include "CSite.hpp"

CSite::CSite(glm::ivec3 pos , vector< CParameter>& par):Parameter(par) , position(pos)
{
    for(int i = 0 ; i < 32*32*32 ; i++)
        Chunk.push_back(std::move(CChunk()));
}

glm::ivec3 CSite::decode(int pos)
{
    return glm::ivec3(pos%32,(pos/32)%(32),pos/(32*32));
}

int CSite::decode(glm::ivec3 vec)
{
    return int(vec.x+vec.y*32+vec.z*32*32);
}

glm::ivec3 CSite::GetPos(int pos)
{
    return glm::ivec3(pos%32*16,(pos/32)%(32)*16,pos/(32*32)*16);
}

Cobject CSite::GetObj(glm::ivec3 vec)
{
    return Chunk[decode(glm::ivec3(vec.x/16,vec.y/16,vec.z/16))].GetObj(glm::ivec3(vec.x%16,vec.y%16,vec.z%16));
}

void CSite::change(Cobject obj , glm::ivec3 vec , bool mod)
{
    glm::ivec3 chunk_vec = glm::ivec3(vec.x/16,vec.y/16,vec.z/16);

    vec = glm::ivec3(vec.x%16,vec.y%16,vec.z%16);

    //cout << chunk_vec.x << " " << chunk_vec.y << " " << chunk_vec.z << endl;
    //cout << vec.x << " " << vec.y << " " << vec.z << endl;
    //cout << decode(chunk_vec) << endl;

    Chunk[decode(chunk_vec)].change(vec , obj); // dodaje object do Chunka

    // transformuje otoczenie dopasowujac do nowego elementu
    glm::ivec3 main; // vector Chunka sasiada
    glm::ivec3 relative; // vector sasiedniego obiektu
    int index_centre = obj.id; // zapisuje indeks glownego obiektu
    if(Parameter[index_centre].IsConecting()) // sprawdza czy centralny obiekt chce sie laczyc
    {
        int shift[6] = {0}; // dane sasiadowania z innym Chunkiem

        if(vec.x == 15) { shift[0] = 1;} // sprawdza czy obiekt sasiaduje z sasiednim Chunkiem i zapisuje te dane
        if(vec.y == 15 ) { shift[1] = 1;}
        if(vec.z == 15) { shift[2] = 1;}

        if(vec.x == 0 ) { shift[3] = -1;}
        if(vec.y == 0) { shift[4] = -1;}
        if(vec.z == 0 ) { shift[5] = -1;}

        int index_neight; // indeks sasiada

        int shx_r = 0; // dane przesuniecia sasiadow
        int shy_r = 0;
        int shz_r = 0;
        int shx_m = 0;
        int shy_m = 0;
        int shz_m = 0;

        int against; // zmienna indeku przeciwnej sciany
        for(int i = 0 ; i < 6 ; i++)
        {
            shx_r = shy_r = shz_r = shx_m = shy_m = shz_m = 0;

            switch(i) // ustawia dane przesuniec dla kazdego przejscia petli
            {
                case 0:shx_r =  1; shx_m = shift[0]; break;
                case 1:shy_r =  1; shy_m = shift[1]; shx_r = 0; shx_m = 0; break;
                case 2:shz_r =  1; shz_m = shift[2]; shy_r = 0; shy_m = 0; break;
                case 3:shx_r = -1; shx_m = shift[3]; shz_r = 0; shz_m = 0; break;
                case 4:shy_r = -1; shy_m = shift[4]; shx_r = 0; shx_m = 0; break;
                case 5:shz_r = -1; shz_m = shift[5]; shy_r = 0; shy_m = 0; break;
            }

            main = chunk_vec + glm::ivec3(shx_m,shy_m,shz_m); // ustawia vector Chunka sasiada

            relative = vec + glm::ivec3(shx_r,shy_r,shz_r); // ustawia vector sasiedniego obiektu
            if(relative.x < 0)
                relative.x+=16;
            if(relative.y < 0)
                relative.y+=16;
            if(relative.z < 0)
                relative.z+=16;
            relative.x %= 16;
            relative.y %= 16;
            relative.z %= 16;

            if(main.x < 0 or main.y < 0 or main.z < 0 or main.x >= 32 or main.y >= 32 or main.z >= 32)
                index_neight = 1;
            else
                index_neight = Chunk[decode(main)].GetObj(relative).id;
            if(Parameter[index_neight].IsConecting() and Parameter[index_centre].con[i] == true) // sprawdza czy sasiad i sciana chce siê laczyc
            {
                if(i < 3) // ustala index stycznej sciany
                    against = i+3;
                else
                    against = i-3;
                if(Parameter[index_neight].con[against] == true) // sprawdz czy styczna œciana sasiada chce siê ³¹czyæ
                {
                    if(Parameter[index_centre].conAB[i] == true)
                    {
                        if(Parameter[index_neight].conAB[against] == true)
                        {
                            //if(mod) Chunk[decode(main)].plane.remove(Parameter[index_neight].part[against],relative);
                        }
                        else
                            if(Parameter[index_neight].conA[against] == true)
                            {
                                //if(mod) Chunk[decode(main)].plane.remove(Parameter[index_neight].part[against],relative);
                                Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
                            }
                            else
                                if(Parameter[index_neight].conB[against] == true)
                                {
                                    //if(mod) Chunk[decode(main)].plane.remove(Parameter[index_neight].part[against],relative);
                                    Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
                                }
                                else{cout << "epicfail";}
                    }
                    else
                    if(Parameter[index_centre].conA[i] == true)
                    {
                        if(Parameter[index_neight].conAB[against] == true)
                        {
                            // lol nic sie tu nie dzieje Omg wtf po co wiec warunek? moze w imie zasad?
                        }
                        else
                            if(Parameter[index_neight].conA[against] == true)
                            {
                                //if(mod) Chunk[decode(main)].plane.remove(Parameter[index_neight].part[against],relative);
                            }
                            else
                                if(Parameter[index_neight].conB[against] == true)
                                {
                                    Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
                                }
                                else{cout << "epicfail";}
                    }
                    else
                    if(Parameter[index_centre].conB[i] == true)
                    {
                        if(Parameter[index_neight].conAB[against] == true)
                        {
                            // lol nic sie tu nie dzieje Omg wtf po co wiec warunek? moze w imie zasad?
                        }
                        else
                            if(Parameter[index_neight].conA[against] == true)
                            {
                                Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
                            }
                            else
                                if(Parameter[index_neight].conB[against] == true)
                                {
                                    //if(mod) Chunk[decode(main)].plane.remove(Parameter[index_neight].part[against],relative);
                                }
                                else{cout << "epicfail";}
                    }
                }
                else
                {
                    Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
                }

            }
            else
            {
                Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
            }
        }
    }
    else // obiekt nie chce sie laczyc wiec zostaje wpelni dodany
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            Chunk[decode(chunk_vec)].plane.add(Parameter[index_centre].part[i],glm::vec3(vec));
        }
    }
}

void CSite::addobj( Cobject obj , glm::ivec3 vec )
{
    Chunk[decode(glm::ivec3(vec.x/16,vec.y/16,vec.z/16))].change(glm::ivec3(vec.x%16,vec.y%16,vec.z%16) , obj); // dodaje object do Chunka
}

void CSite::load(CGenerator obj , glm::ivec3 vec)
{
    for(int j = 0 ; j < obj.X ; j++)
            for(int k = 0 ; k < obj.Y ; k++)
                for(int l = 0 ; l < obj.Z ; l++)
                    if(obj.GetObj(glm::ivec3(j,k,l)) != 0)
                        addobj(Cobject(obj.GetObj(glm::ivec3(j,k,l))),glm::ivec3(vec.x+j,vec.y+k,vec.z+l));
}

void CSite::build()
{
    for(int i = 0 ; i < 512 ; i++)
    {
        /*static int procent = 0;
        if((int)((float)((float)(i+255)/(float)(255*2))*100) != procent)
        {
            procent = (float)((float)(i+255)/(float)(255*2))*100 ;
            ///cout << procent << "%" <<endl;
        }*/
        for(int j = 0 ; j < 512 ; j++)
            for(int k = 0 ; k < 512 ; k++)
            {
                if( GetObj(glm::ivec3(i,j,k)).id != 0)
                {
                    change(GetObj(glm::ivec3(i,j,k)),glm::ivec3(i,j,k) , false  );
                }
            }
    }
}
