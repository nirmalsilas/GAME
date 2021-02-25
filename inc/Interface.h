#pragma once
#include<string>
#include"../inc/base.h"
#include<vector>

namespace game{


	
	class Interface
	{
		
	public:
		Interface() {}
		~Interface() {}
		cred get_credentials();
		static Interface& get();
		ErrCode get_record(std::string fileName);
	
	};
}