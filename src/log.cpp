#include"../inc/log.h"
#include<string>
#include<iostream>
#include<sstream>
#include<sstream>
#include<fstream>
using namespace game;


void log::print()
{
	
	if (logLevel >= currLogLevel)
	{
		std::cout << buffer.str();
		writeToFile(buffer.str());
	}

}
void log::setLogLevel(int logLevel_)
{
	log::logLevel = logLevel_;
}
void log::writeToFile(const std::string& str_)
{
	std::fstream myFile("C:\/c++\/GAME_ENGINE_01\/LOG.txt",std::ios_base::out | std::ofstream::app);
	myFile << str_;

}



