#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>

#include "CyberPC.h"


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int count_Rest_days;
    int count_Work_days;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here

public:

    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
 	int getCount_Work_days();
    void setCount_Work_days(int i);
    int getCount_Rest_days();
    void setCount_Rest_days(int i);
    const int getEfficiency();
    void dailyCheck(CyberDNS & server,int already_checked);
    const int get_expert_work_time();
    const int get_expert_rest_time();
    const std::string get_expert_Name();

};


#endif
