#pragma once

#include"../inc/base.h"
#include<functional>
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
		mark mark_;
		void printScoreCard(std::function<void(int)>);
		void result(std::string );
		
	};

	static std::vector<player> usersList;
}