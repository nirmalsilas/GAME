#include"../inc/log.h"
#include<string>
#include<iostream>
#include<sstream>
#include<sstream>
using namespace game;


void log::print()
{
	
	if (logLevel >= currLogLevel)
		std::cout << buffer.str() ;
}
void log::setLogLevel(int logLevel_)
{
	log::logLevel = logLevel_;
}



