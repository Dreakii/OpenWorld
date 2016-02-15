//CFrameCounter.cpp

#include"CFrameCounter.hpp"

CFrameCounter::CFrameCounter() : frames(0){}

void CFrameCounter::count()
{
	frames++;
	seconds=fpscounter.getElapsedTime();
	if(seconds.asSeconds()>=1){
		std::cout << std::endl << frames;
		frames=0;
		fpscounter.restart();
	}
}