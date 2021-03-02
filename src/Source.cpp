#include<iostream>
#include"../inc/base.h"
#include"../inc/log.h"
#include"../inc/Interface.h"
#include"../inc/player.h"



using namespace game;


#define Interface_ Interface::get()
#define PASS_MARK 10


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
			LOG_ERROR<<"Authentication Failure for userName :"<<itr.username<<"\n";
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

	//Interface_.print_recordList();

	//create a data base for questions and answers [done]
	//populate one by one   [done]
	//score calculation and pass /fail [done]
	//wite logs to a file [done]
	for (player player_ : usersList)
	{
		Interface_.query(player_.mark_);

		player_.printScoreCard([&](int total) {
			if (total > PASS_MARK)
				player_.result("PASSED");
			else
				player_.result("FAILED"); });
	}

	cin.get();








	

}