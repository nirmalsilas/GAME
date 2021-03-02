#include "../inc/player.h"
#include "../inc/base.h"
#include "../inc/log.h"
#include <chrono>
#include<thread>
using namespace game;

ErrCode player::validation()
{
	ErrCode retVal = ErrCode::CREDENTIAL_CHECK_FAIL;
	auto itr = credentials.find(username);
	if (itr != credentials.end())
		retVal = ErrCode::ERR_SUCESS;

	return retVal;
}
void player::result(std::string res_str)
{
	std::cout << "HEY CONGRAGULATION ...\n";
	std::cout << "SUCCESSFULLY " << res_str << " THE MISSION\n";
}



void player::printScoreCard(std::function<void(int)> result)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));;
	LOG_INFO << "##############################\n";
	LOG_INFO << "HI "<< this->username <<"\n";
	LOG_INFO << "HERE IS YOUR SCORE CARD\n";
	LOG_INFO << ".................................\n";
	LOG_INFO << "TOTAL SCORE IS " << mark_.total_score << "\n";
	LOG_INFO << "CORRECT ANSWERS : " << mark_.correct_answ << "\n";
	LOG_INFO << "WRONG ANSWERS : " << mark_.wrong_answ << "\n";

	LOG_INFO << "#############################\n";
	result(mark_.total_score);
}