#pragma once

#include"../inc/base.h"
namespace game {


	class player
	{
	
		int pin;

	public:
		player(std::string username_, int pin_) :username(username_), pin(pin_)
		{}
		~player() {}
		ErrCode validation();
		std::string username;
		int score;
	};

	static std::vector<player> usersList;
}