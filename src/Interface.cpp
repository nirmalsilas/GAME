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