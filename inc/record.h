#pragma once
#include<iostream>
#include<string>


namespace game {


	struct Record
	{
		std::string name;
		std::string quote;
		Record(std::string name_, std::string quote_) :name(name_), quote(quote_) {}
	};
	std::vector<Record> RecordLIst;
}