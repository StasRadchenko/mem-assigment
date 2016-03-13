#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../include/CyberDNS.h"
using namespace std;

CyberDNS::CyberDNS(){}

//constructor

void CyberDNS::AddPC(CyberPC & cyber_pc_){

  cyber_DNS_.insert (std::pair<const string, CyberPC&>(cyber_pc_.getName(),cyber_pc_));


}//Adding cyber pc

CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const{
  map<const string, CyberPC &>::const_iterator p=cyber_DNS_.find(cyber_pc_name);
  return p->second;

}//pc getter by string

vector<std::string> CyberDNS::GetCyberPCList(){
  vector<string> CyberPCList;
  map<const string, CyberPC &>::iterator it;
  for (it = cyber_DNS_.begin(); it != cyber_DNS_.end(); it++)
  {
    CyberPCList.push_back(it->first);
  }
  return CyberPCList;

}//pc list as vector
CyberDNS::~CyberDNS(){
	map<const string, CyberPC &>::iterator it;
	  for (it = cyber_DNS_.begin(); it != cyber_DNS_.end(); it++)
	  {
	    delete &(it->second);
	  }
	  cyber_DNS_.clear();




}
