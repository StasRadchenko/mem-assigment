#include <iostream>

#include "../include/CyberWorm.h"
using namespace std;

CyberWorm::CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time):cyber_worm_os_(cyber_worm_os),cyber_worm_name_(cyber_worm_name),cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
{ }//constructor
CyberWorm::CyberWorm(const CyberWorm& other):cyber_worm_os_(other.cyber_worm_os_),cyber_worm_name_(other.cyber_worm_name_), cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_)
{ }//copy constructor
const int CyberWorm::getDormancy(){
    return (cyber_worm_dormancy_time_);
}//dormacy time getter

const string CyberWorm::getOs(){
    return (cyber_worm_os_);
}//prefered os by the worm
const string CyberWorm::getName(){
    return (cyber_worm_name_);
}



