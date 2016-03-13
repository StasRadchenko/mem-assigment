#include "../include/CyberExpert.h"
#include <algorithm>
using namespace std;


// Prevent the use of an empty constructor
// Add your own variables here

CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
		cyber_expert_name_(cyber_expert_name_),  cyber_expert_work_time_(cyber_expert_work_time_),  cyber_expert_rest_time_(cyber_expert_rest_time_),  cyber_expert_efficiency_(cyber_expert_efficiency_),count_Rest_days(cyber_expert_rest_time_),count_Work_days(cyber_expert_work_time_) {

} //default constractor

void CyberExpert::Clean(CyberPC & cyber_pc){
    cyber_pc.Disinfect();
}
void CyberExpert::dailyCheck(CyberDNS & server,int already_checked){
	vector<string> CyberPcList;
	CyberPcList=server.GetCyberPCList();
	std::reverse(CyberPcList.begin(),CyberPcList.end());
	  int it=CyberPcList.size();
	  int how_many_checked=0;
	   while(how_many_checked<cyber_expert_efficiency_ && already_checked< it){
		   cout<<"    "<<cyber_expert_name_<<" examining "<<CyberPcList[already_checked]<<endl;
		  if(server.GetCyberPC(CyberPcList[already_checked]).isInfected()){
			  cout<<"        "<<"Worm "<<(server.GetCyberPC(CyberPcList[already_checked])).wormName()<<" successfully removed from "<< CyberPcList[already_checked]<<endl;
		  Clean(server.GetCyberPC(CyberPcList[already_checked]));

		  }
		  already_checked++;
		  how_many_checked++;

       }




}


const int CyberExpert::get_expert_work_time(){
	return cyber_expert_work_time_;
}
const int CyberExpert::get_expert_rest_time(){
	return cyber_expert_rest_time_;
}
const string CyberExpert::get_expert_Name(){
	return cyber_expert_name_;
}


int CyberExpert::getCount_Work_days(){
	return count_Work_days;
}
 void CyberExpert::setCount_Work_days(int i){
		if (i==1)
			count_Work_days--;
		else if(i==0)
			count_Work_days=cyber_expert_work_time_;
}

 int CyberExpert::getCount_Rest_days(){
 	return count_Rest_days;
 }
  void CyberExpert::setCount_Rest_days(int i){
  		if (i==1)
  			count_Rest_days--;
  		else if(i==0)
  			count_Rest_days=cyber_expert_rest_time_;
  }
 const int CyberExpert::getEfficiency(){
	 return (cyber_expert_efficiency_);
 }






