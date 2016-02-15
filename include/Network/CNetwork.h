#include <iostream>
#include <SFML/Network.hpp>
#include "../Character/CRemoteCharacterBase.hpp"

using namespace std;
class CNetwork{
    public:
        sf::TcpSocket *socket;
        sf::IpAddress *address;
        CNetwork()
        {
            string message="Welcome to CNetwork!\n";
            cout << message;
        }
        sf::Packet packCharacter(CCharacter c)
        {
            sf::Packet temp;
            temp<<c.angle;
            temp<<c.pos.x;
            temp<<c.pos.y;
            temp<<c.pos.z;
            return temp;
        }
        sf::Packet packRemoteCharacter(CRemoteCharacter c)
        {
            sf::Packet temp;
            temp<<c.angle;
            temp<<c.pos.x;
            temp<<c.pos.y;
            temp<<c.pos.z;
            temp<<c.id;
            return temp;
        }
        CRemoteCharacter unpackCharacter(sf::Packet p)
        {
            CRemoteCharacter c;
            p>>c.angle;
            p>>c.pos.x;
            p>>c.pos.y;
            p>>c.pos.z;
            return c;
        }
        CRemoteCharacter unpackRemoteCharacter(sf::Packet p)
        {
            CRemoteCharacter c;
            p>>c.angle;
            p>>c.pos.x;
            p>>c.pos.y;
            p>>c.pos.z;
            p>>c.id;//temp<<c.id;
            return c;
        }
};
class CClient:public CNetwork{
    public:
    string name;
    int id;
    CCharacter character;
    CRemoteCharacterBase base;
    CClient():CNetwork() //CCharacter &ch
    {
        string addr;
        cout << "podaj nick: ";
        cin >> name;
        cout << "podaj adres: ";
        cin >> addr;
        address = new sf::IpAddress(addr);
        socket = new sf::TcpSocket;
    }
    bool connect()
    {
        sf::Socket::Status status = socket->connect(*address,1337);
        if(status != sf::Socket::Done){
            return true;
        }else return false;
    }
    void init()
    {
        sf::Packet p;
        p<<name;
        p<<character.angle;
        p<<character.pos.x;
        p<<character.pos.y;
        p<<character.pos.z;
        socket->send(p);
        p.clear();
        socket->receive(p);
        p>>id;
        cout << "\nInit Done!\n";
        socket->setBlocking(false);
    }
/*    void wypisz(){
        if(wiadomosc_in!=""){
            cout << endl << wiadomosc_in<<endl;
            wiadomosc_in="";
        }
    }
    void napisz(){
        cout << "\nwyslij: ";
        cin >> wiadomosc_out;
    }*/
    void getCharacter(CCharacter c)
    {
        character=c;
    }
    void wyslij(){
        sf::Packet p;
        p=packCharacter(character);
        if(socket->send(p)==sf::Socket::Done){
            cout << "\nData sent!\n";
        }
    }
    void odbierz(){
        sf::Packet p;
        int i;
        cout << "\nClear Base\n";
        //base->base.clear();
        if(socket->receive(p)==sf::Socket::Done){
            p >> i;
            cout << "\nReceived iterator "<<i<<endl;
            while(i!=0)
            {
                p.clear();
                socket->receive(p);
                //CRemoteCharacter r=unpackRemoteCharacter(p);
                //base->base.push_back(r);
                i--;
            }
        }
    }
};
class Client{
    public:
    sf::TcpSocket* client;
    string name;
    int id;
    //dane
    CRemoteCharacter character;
};
class CServer:public CNetwork{
    sf::TcpListener *listener;
    sf::SocketSelector selector;
    string data;
    short sender_id;
    public:
    list<Client> clients;
    CServer():CNetwork()
    {
        listener=new sf::TcpListener;
        listener->listen(1337);
        listener->setBlocking(false);
    }
    void init(){
        while(1){
            checkNew();
            checkData();
            broadcastData();
            std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
        }
    }
    void checkNew()
    {
        sf::TcpSocket *temp = new sf::TcpSocket;
        if(listener->accept(*temp) == sf::Socket::Done){
            bool add=true;
            sf::TcpSocket *x;
            for(list<Client>::iterator i=clients.begin(); i!=clients.end(); i++){
                Client tmp=*i;
                x=tmp.client;
                if(temp->getRemoteAddress()==x->getRemoteAddress()) add=false;
            }
            if(add){
                Client tmpcl;
                tmpcl.client=temp;
                selector.add(*temp);
                cout << "Accepted connection from " << temp->getRemoteAddress();
                sf::Packet p;
                temp->receive(p);
                string x;
                p>>x;
                tmpcl.name=x;
                ///trzeba dodac niepowtarzalne ID
                tmpcl.id=rand()%1000;
                tmpcl.character=unpackCharacter(p);
                tmpcl.character.id=tmpcl.id;
                clients.push_back(tmpcl);
                p.clear();
                p<<tmpcl.id;
                temp->send(p);
                //temp->setBlocking(false);
            }
            else delete temp;
        }else delete temp;
    }
    void checkData()
    {
        data="";
        if(selector.wait(sf::Time(sf::seconds(10)))){
            // The listener socket is not ready, test all other sockets (the clients)
            for(list<Client>::iterator i=clients.begin(); i!=clients.end(); i++)
            {
                Client tmp=*i;
                sf::TcpSocket& client = *tmp.client;
                if (selector.isReady(client))
                {
                    // The client has sent some data, we can receive it
                    sf::Packet packet;
                    if (client.receive(packet) == sf::Socket::Done)
                    {
                        tmp.character=unpackCharacter(packet);
                        cout << "\nReceived from client!\n";
                    }
                }
            }
        }
    }
    void broadcastData()
    {
        sf::TcpSocket *temp = new sf::TcpSocket;
        sf::Packet p;
        for(list<Client>::iterator i=clients.begin(); i!=clients.end(); ++i)
        {
            Client receiver=*i;
            temp=receiver.client;
            p << (sf::Uint8)clients.size(); /// dodalem jawna konwersje NALEZY sprawdzic czy typ sie zgadza
            cout << "Klienty: "<<clients.size()<<endl;
            if(temp->send(p)!=sf::Socket::Done)
            {
                cout << "Blad wysylania!\n";
            }
            else
            {
                for(list<Client>::iterator j=clients.begin(); j!=clients.end(); j++)
                {
                    Client tmp=*j;
                    p.clear();
                    p=packRemoteCharacter(tmp.character);
                    if(temp->send(p)!=sf::Socket::Done)
                    {
                         cout << "Blad wysylania!\n";
                    }
                    else cout << "Wyslano\n";
                }
            }
        }
    }
};
