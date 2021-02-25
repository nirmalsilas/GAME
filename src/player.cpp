#include "../inc/player.h"
#include "../inc/base.h"

using namespace game;

ErrCode player::validation()
{
	ErrCode retVal = ErrCode::CREDENTIAL_CHECK_FAIL;
	auto itr = credentials.find(username);
	if (itr != credentials.end())
		retVal = ErrCode::ERR_SUCESS;

	return retVal;
}