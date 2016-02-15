#ifndef CNET_H_INCLUDED
#define CNET_H_INCLUDED

#include <iostream>
#include <thread>
#include <mutex>
#include "CNetwork.h"
using namespace std;

class Net{
    mutex m;
    public:
bool ready,ta_done,tb_done,add;
int sizeOld;
CCharacter tmp;
CRemoteCharacterBase base;
CClient c;
void receive(CServer *s)
{
    while(1){
    m.lock();
    s->checkData();
    s->broadcastData();
    m.unlock();
    std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    }
}

void accepter(CServer *s)
{
    while(1){
    m.lock();
    s->checkNew();
    m.unlock();
    std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    }
}

void odbieranie(CClient *c)
{
    m.lock();
    c->odbierz();
    m.unlock();
    tb_done=true;
}
void nadawanie(CClient *c)
{
    if(ready)
    {
        m.lock();
        c->getCharacter(tmp);
        c->wyslij();
        m.unlock();
        ready=false;
        ta_done=true;
    }
}
void startServer()
{
    CServer s;
    thread c(&Net::receive,this,&s);
    thread d(&Net::accepter,this,&s);
    c.join();
    d.join();
}
void startClient(CCharacter ch)
{
    ta_done=true;
    tb_done=true;
    c.character=ch;
    c.base=base;
    while(c.connect()){
        cout << "czekam na polaczenie\n";
    }
    c.init();
}
void runThreads()
{
	sizeOld=base.base.size();
    ta_done=false;
    tb_done=false;
    cout << "\nthreads...";
    thread a(&Net::nadawanie,this,&c);
    thread b(&Net::odbieranie,this,&c);
    cout << "started\n";
    a.join();
    b.join();
    cout << "\nthreads joined\n";
    if(sizeOld!=base.base.size())
    {
        add=true;
    }

}
CRemoteCharacterBase getBase()
{
    base=c.base;
    return base;
}
};






#endif // CNET_H_INCLUDED
