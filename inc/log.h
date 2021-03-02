#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"../inc/base.h"

using namespace std;
namespace game
{

	enum LOGLEVEL :int
	{
		DEBUG =0,
		INFO ,
		WARNING,
		ERROR

	};


	static string LOGSTRING[4] = { "DEBUG","INFO","WARNING","ERROR" };

	/*class logbase
	{
		
	logbase() {}

	public:
		int logLevel;
	};
	*/
	class log 
	{
	private:
		int logLevel;
		int currLogLevel;
		std::stringstream buffer;

	public:
		log(int logLevel_) : logLevel(logLevel_) 
		{
			//std::cout << "\nINITALIZING LOG CLASS"<<std::endl;
		};
		~log()
		{
			//std::cout << "\nDESTROY LOG CLASS"<<std::endl;
		};

		
		void print();
		void setLogLevel(int);
	
		static log& get(int currLogLevel_)
		{
			static log instance_(LOGLEVEL::ERROR);
			instance_.currLogLevel = currLogLevel_;
			return instance_;
		}

		void writeToFile(const std::string& );
		template<typename type>
		log& operator<<(type data)
		{
			buffer.clear();
			buffer.str(std::string());
			buffer << data;
			this->print();
			
			return *this;
		}
	};
	
	

#define LOG_INFO game::log::get(game::INFO) << "[INFO]:   ("<<__FUNCTION__ <<")  :"
#define LOG_DEBUG game::log::get(game::DEBUG)<< "[DEBUG]:  ("<<__FUNCTION__ <<")  :"
#define LOG_WARNING game::log::get(game::WARNING)<<"[WARNING]: ("<<__FUNCTION__ <<")  :"
#define LOG_ERROR game::log::get(ERROR)<<"[ERROR]:  ("<<__FUNCTION__ <<")  :"
	
}
