#include "../include/CyberPC.h"

class iterator;

using namespace std;


//an empty constractor
/*CyberPc::cyberPc():_cyber_pc_os_(""),cyber_pc_name_(""),cyber_pc_connections_(),cyber_pc_time_to_infect_(0)//pointer cyber_worm should be initialized to null???
{}*/

CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name):cyber_pc_os_(cyber_pc_os),cyber_pc_name_(cyber_pc_name)
{
    vector<string> cyber_pc_connections_;
}//default constractor
const string CyberPC::getName(){
    return (cyber_pc_name_);
}

void CyberPC::AddConnection(std::string  second_pc){
    cyber_pc_connections_.push_back(second_pc);
}
// Add a connection to this PC
int CyberPC::sizeCon(){
	return(cyber_pc_connections_.size());
}

void CyberPC::Infect(CyberWorm & worm){
    if (cyber_pc_os_==worm.getOs()){
    	if (this->isInfected()){   //computer already infected,replace worm with new one
    		Disinfect();

    		}
        cyber_worm_=&worm;
        cyber_pc_time_to_infect_=worm.getDormancy();
        cout<<"        "<<cyber_pc_name_<<" infected by "<<worm.getName()<<endl;
    }
    else {
    	cout<<"                "<<"Worm "<<worm.getName()<<" is incompatible with Critical Server"<<endl;
    	   delete &worm;
    	}
    }

// Add a worm to this PC

void CyberPC::Run(const CyberDNS & server){
	if(cyber_worm_!= NULL){
		if(cyber_pc_time_to_infect_==0){
			cout<<"    "<< cyber_pc_name_ << " infecting..." <<endl;
		    int size=cyber_pc_connections_.size();
			for(int i=0;i<size;i++){
				CyberWorm *worm=new CyberWorm(*cyber_worm_);
				server.GetCyberPC(cyber_pc_connections_[i]).Infect(*worm);
				
			}

		}
		else{
		cout<<"    "<<cyber_pc_name_<< ": Worm "<< (*cyber_worm_).getName()<<" is dormant"<<endl;
		cyber_pc_time_to_infect_=cyber_pc_time_to_infect_-1;}
    }


}

bool CyberPC::isInfected(){
	return(cyber_worm_!=NULL);

}
int CyberPC::infectionTime(){
	return (cyber_pc_time_to_infect_);
}

void CyberPC::Disinfect(){
	delete cyber_worm_;
   cyber_worm_=NULL;

}
const string CyberPC::wormName(){
	return((*cyber_worm_).getName());

}
CyberPC::~CyberPC(){
	if(cyber_worm_ != NULL)
	delete cyber_worm_;

}

