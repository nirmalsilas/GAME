#include<iostream>
#include"../inc/base.h"
#include"../inc/log.h"
#include"../inc/Interface.h"
#include"../inc/player.h"



using namespace game;


#define Interface_ Interface::get()



int main()
{
	LOG_INFO << "SYSTEM STARTUP\n ";
	

	LOG_INFO<<"GAME IS LOADING  PLEASE WAIT ...\n ";
	
	//authentication of player 
	//2 player mode needs to implement later 
	cred cred_ = Interface_.get_credentials();
	usersList.emplace_back(cred_.userName_, cred_.pin_);
	for (player itr : usersList)
	{
		auto retVal =  itr.validation();
		if (retVal != ErrCode::ERR_SUCESS)
		{
			LOG_ERROR<<"Authentication Failure for userName :$$$$\n";
			return 0;
		}
		LOG_INFO<<"authentication Successfull\n";
	}
	
	//open a file using boost xml
	LOG_INFO <<"Loading Database ...\n";
	if (Interface_.get_record(FILE_PATH) != ErrCode::ERR_SUCESS)
	{
		LOG_ERROR << "FILE OPEN/getting record failed \n";
	}

	

	//create a data base for questions and answers 
	//populate one by one 
	//score calculation and pass /fail
	//wite logs to a file








	

}