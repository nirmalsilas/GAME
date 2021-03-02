#include"../inc/Interface.h"
#include"../inc/log.h"
#include"../inc/base.h"
#include"../inc/Interface.h"
#include <boost/property_tree/xml_parser.hpp>
#include<boost/property_tree/ptree.hpp>
#include<boost/foreach.hpp>
#include"../inc/record.h"


using namespace game;
#define NAME "name"
#define QUOTE "quote"



cred game::Interface::get_credentials()
{
	cred cred_;
	LOG_INFO<< "ENTER USERNAME:";
	std::cin >> cred_.userName_;
	LOG_INFO<< "ENTER PIN:";
	std::cin >> cred_.pin_;
	return cred_;

}
 Interface& Interface::get()
{
	static Interface Interface_;
	return Interface_;
}
 ErrCode Interface::get_record(const std::string fileName_)
 {
	 ErrCode retValue = ErrCode::ERR_SUCESS;
	 boost::property_tree::ptree pt;

	 boost::property_tree::read_xml(fileName_, pt);
	
	 BOOST_FOREACH(boost::property_tree::ptree::value_type const& module_, pt.get_child("data-set"))
	 {
		 
		 if (module_.first == "record")
		 {
			std::string name = module_.second.get<std::string>(NAME);
			std::string quote = module_.second.get < std::string>(QUOTE);
			RecordLIst.emplace_back(name, quote);
		 }
	 }
	 return retValue;

 }

 void Interface::print_recordList()
 {

	 for (game::Record rcd_ : RecordLIst)
	 {
		 LOG_INFO << "Name: " << rcd_.name << "\n";
		 LOG_INFO << "Quote: " << rcd_.quote << "\n";
	 }

 }
 void Interface::query(mark& tmpMark)
 {
	 LOG_INFO << "INITIALIZING QUESTIONS\n";
	 LOG_INFO << "FIND WHO'S WORDS IT IS ..??\n";
	 
	 std::string answer;
	 cin.get();
	 for (game::Record rcd_ : RecordLIst)
	 {
		 LOG_INFO << "..............................\n";
		 LOG_INFO << "Quote: " << rcd_.quote << "\n";
		 LOG_INFO << "WRITE YOUR ANSWER :\n";
		// cin.get();
		 getline(cin, answer);

		 if (answer == rcd_.name)
		 {
			 LOG_INFO << "RIGHT ANSWER\n";
			 tmpMark.total_score +=  5;
			 tmpMark.correct_answ++;
		 }
		 else
		 {
			 LOG_ERROR << "WRONG ANSWER\n";
			 tmpMark.wrong_answ++;
		 }
		 answer.clear();
	 }
 }
