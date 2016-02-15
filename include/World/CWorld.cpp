//CWorld.cpp

#include"CWorld.hpp"

CWorld::CWorld()
{
    Parameter.insert( Parameter.begin() , 100 , CParameter() );
    Parameter[1].DownloadFromFile("data/data" , 1);
    Parameter[2].DownloadFromFile("data/data" , 2);
    Parameter[3].DownloadFromFile("data/data" , 2);
    Parameter[4].DownloadFromFile("data/data" , 2);
    Parameter[5].DownloadFromFile("data/data" , 2);
    Parameter[6].DownloadFromFile("data/data" , 3);
    Parameter[7].DownloadFromFile("data/data" , 3);
    Parameter[8].DownloadFromFile("data/data" , 3);
    Parameter[9].DownloadFromFile("data/data" , 3);
    Parameter[10].DownloadFromFile("data/data" , 4);
    Parameter[11].DownloadFromFile("data/data" , 4);
    Parameter[12].DownloadFromFile("data/data" , 4);
    Parameter[13].DownloadFromFile("data/data" , 4);
    Parameter[14].DownloadFromFile("data/data" , 5);
    Parameter[15].DownloadFromFile("data/data" , 5);
    Parameter[16].DownloadFromFile("data/data" , 5);
    Parameter[17].DownloadFromFile("data/data" , 5);
    Parameter[18].DownloadFromFile("data/data" , 6);
    Parameter[19].DownloadFromFile("data/data" , 6);
    Parameter[20].DownloadFromFile("data/data" , 6);
    Parameter[21].DownloadFromFile("data/data" , 6);
    Parameter[34].DownloadFromFile("data/data" , 7);
    Parameter[35].DownloadFromFile("data/data" , 8);
    Parameter[36].DownloadFromFile("data/data" , 9);
    Parameter[37].DownloadFromFile("data/data" , 9);
    Parameter[38].DownloadFromFile("data/data" , 9);
    Parameter[39].DownloadFromFile("data/data" , 9);

    Parameter[3].RorateZ90(true);
    Parameter[4].RorateZ180();
    Parameter[5].RorateZ270(true);
    Parameter[7].RorateZ90(true);
    Parameter[8].RorateZ180();
    Parameter[9].RorateZ270(true);
    Parameter[11].RorateZ90(true);
    Parameter[12].RorateZ180();
    Parameter[13].RorateZ270(true);

    Parameter[15].RorateZ90(true);
    Parameter[16].RorateZ180();
    Parameter[17].RorateZ270(true);

    Parameter[19].part[0].mirrorY();
    Parameter[20].part[0].rotate(180,glm::vec3(0,1,0));
    Parameter[21].part[0].mirrorY();
    Parameter[21].part[0].rotate(180,glm::vec3(0,1,0));

    Parameter[22] = Parameter[18];
    Parameter[23] = Parameter[19];
    Parameter[24] = Parameter[20];
    Parameter[25] = Parameter[21];

    Parameter[26] = Parameter[18];
    Parameter[27] = Parameter[19];
    Parameter[28] = Parameter[20];
    Parameter[29] = Parameter[21];

    Parameter[30] = Parameter[18];
    Parameter[31] = Parameter[19];
    Parameter[32] = Parameter[20];
    Parameter[33] = Parameter[21];

    Parameter[22].RorateZ180();
    Parameter[23].RorateZ180();
    Parameter[24].RorateZ180();
    Parameter[25].RorateZ180();

    Parameter[26].RorateZ90();
    Parameter[27].RorateZ90();
    Parameter[28].RorateZ90();
    Parameter[29].RorateZ90();

    Parameter[30].RorateZ270();
    Parameter[31].RorateZ270();
    Parameter[32].RorateZ270();
    Parameter[33].RorateZ270();

    Parameter[37].RorateZ90();
    Parameter[38].RorateZ180();
    Parameter[39].RorateZ270();

    Parameter[2].layer.recreate(1,1,0,0,0.5);
    Parameter[3].layer.recreate(0,1,1,0,0.5);
    Parameter[4].layer.recreate(0,0,1,1,0.5);
    Parameter[5].layer.recreate(1,0,0,1,0.5);

    Parameter[6].layer.recreate(0,1,0,0,0.5);
    Parameter[7].layer.recreate(1,0,0,0,0.5);
    Parameter[8].layer.recreate(0,0,0,1,0.5);
    Parameter[9].layer.recreate(0,0,1,0,0.5);

    Parameter[10].layer.recreate(1,1,0,1,0.5);
    Parameter[11].layer.recreate(1,0,1,1,0.5);
    Parameter[12].layer.recreate(0,1,1,1,0.5);
    Parameter[13].layer.recreate(1,1,1,0,0.5);
    for(int i = -1 ; i <= 1 ; i++)
        for(int j = -1 ; j <= 1 ; j++)
            Site.insert(pair<long long int,CSite>(decode(glm::ivec2(i,j)),CSite(glm::ivec3(i,j,0) , Parameter)));
    ///Site.insert(pair<long long int,CSite>(decode(glm::ivec2(0,0)),CSite(glm::ivec3(0,0,0),Parameter)));
    generate();

    center = glm::ivec3(250,250,0);
}

CWorld::~CWorld() {}

long long CWorld::decode(glm::ivec2 vec)
{
    int result = 0;
    if(vec.x == 0 and vec.y == 0)
        return 0;
    if(vec.y >= 0 and abs(vec.y) >= abs(vec.x))
    {
        if(vec.x < 0)
            for(int i = 1 ; i < vec.y+1; i++)
                result += i*8;
        else
            for(int i = 1 ; i < vec.y ; i++)
                result += i*8;
        return result+1+vec.x;
    }
    if(vec.x >= 0 and abs(vec.x) >= abs(vec.y))
    {
        for(int i = 1 ; i < vec.x ; i++)
            result += i*8+2;
        return result+3-vec.y;
    }
    if(vec.y < 0 and abs(vec.y) >= abs(vec.x))
    {
        for(int i = 1 ; i < -vec.y ; i++)
            result += i*8+4;
        return result+5-vec.x;
    }
    if(vec.x < 0 and abs(vec.x) >= abs(vec.y))
    {
        for(int i = 1 ; i < -vec.x ; i++)
            result += i*8+6;
        return result+7+vec.y;
    }
}

vector<CWorld::Position> CWorld::region(glm::ivec3 vec)
{
    vector<Position> region;
    Position pos;
    int site;
    for(int i = -5+vec.x ; i < 5+vec.x ; i++)
        for(int j = -5+vec.y ; j < 5+vec.y ; j++)
            for(int k = -5+vec.z ; k < 5+vec.z ; k++)
            {
                pos.SiteIndex = decode(glm::ivec2((i<0)?((i-31)/32):(i/32),(j<0)?((j-31)/32):(j/32)));
                pos.Site = glm::ivec2((i<0)?((i-31)/32):(i/32),(j<0)?((j-31)/32):(j/32));
                pos.ChunkIndex = CSite::decode(glm::ivec3((i<0)?(32+(i%32)):(i%32),(j<0)?(32+(j%32)):(j%32),(k<0)?(32+(k%32)):(k%32)));
                region.push_back(pos);
            }
    return region;
}

void CWorld::generate()
{
    CGenerator generator(512,512,512);                //
    generator.fill(0,1 , 35);                         // Zapelnia mape woda
    for(int i = 0 ; i < Site.size() ; i++)            //
        Site.at(i).load(generator,glm::ivec3(0,0,0)); //

    CContinent con(1536,glm::ivec2(1536,1536));
    con.genContinents(2100000,2000);
    int power = 1536*1536*0.1;
    int attempt = 0;
    while(power > 0 and attempt < 30)
    {
        attempt++;
        CGenerator gen = con.GetContinent();
        int x = rand()%(1536-gen.X)-512;
        int y = rand()%(1536-gen.Y)-512;
        bool match = true;
        for(int i = 0 ; i < 1000 ; i++)
        {
            int px = rand()%gen.X;
            int py = rand()%gen.Y;
            if(gen.GetObj(glm::ivec3(px,py,0)) == 1 and GetObj(glm::ivec3(x+px,y+py,1)).id == 1)
                match = false;
        }
        if(match)
        {
            gen.round();
            power -= con.superficies;
            load(gen , glm::ivec3(x,y,1));
        }
    }

    int x , y, z;
    for(int j = 0 ; j < 9 ; j++)
        for(int i = 0 ; i <= 70 ; i++)
        {
            x = (rand()%500);
            y = (rand()%500);
            z = -1;
            while(Site.at(j).GetObj(glm::ivec3(x,y,z)).id != 0 )
                z++;
            if(Site.at(j).GetObj(glm::ivec3(x,y,z-1)).id == 1)
            {
                CTree obj(20,20,26);
                obj.generate(1000);
                Site.at(j).load(obj,glm::ivec3(x-10,y-10,z));
            }
        }
    ///cout << GetObj(glm::ivec3(0,0,-255)).id << endl;
}

Cobject CWorld::GetObj(glm::ivec3 vec)
{
    glm::ivec2 main((vec.x < 0)?((vec.x-511)/512):(vec.x/512),(vec.y < 0)?((vec.y-511)/512):(vec.y/512));
    (vec.x < 0)?(vec.x = 512+(vec.x%512)):(vec.x %= 512);
    (vec.y < 0)?(vec.y = 512+(vec.y%512)):(vec.y %= 512);
    (vec.z < 0)?(vec.z = 512+(vec.z%512)):(vec.z %= 512);
    return Site.at(decode(main)).GetObj(vec);
}

void CWorld::build()
{
    int i = 0;
    for(pair<const long long int,CSite>& X : Site)
    {
        ///cout << i++ << endl;
        X.second.build();
    }
}

void CWorld::load(CGenerator obj , glm::ivec3 vec)
{
    for(int j = 0 ; j < obj.X ; j++)
        for(int k = 0 ; k < obj.Y ; k++)
            for(int l = 0 ; l < obj.Z ; l++)
            {
                if(obj.GetObj(glm::ivec3(j,k,l)) != 0)
                {
                    glm::ivec3 pos = glm::ivec3(j,k,l)+vec;
                    glm::ivec2 main((pos.x < 0)?((pos.x-511)/512):(pos.x/512),(pos.y < 0)?((pos.y-511)/512):(pos.y/512));
                    (pos.x < 0)?(pos.x = 512+(pos.x%512)):(pos.x %= 512);
                    (pos.y < 0)?(pos.y = 512+(pos.y%512)):(pos.y %= 512);
                    (pos.z < 0)?(pos.z = 512+(pos.z%512)):(pos.z %= 512);
                    Site.at(decode(main)).addobj(Cobject(obj.GetObj(glm::ivec3(j,k,l))),glm::ivec3(pos.x,pos.y,pos.z));
                }
            }
}
