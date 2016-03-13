#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "../include/CyberDNS.h"
#include "../include/CyberExpert.h"
#include "../include/CyberPC.h"
#include "../include/CyberWorm.h"
#include <boost/foreach.hpp>
#include <iterator>
#include <vector>
#include <string>
#include <map>
using boost::property_tree::ptree;
using namespace std;

int main() {

	ptree computers;
		read_xml("computers.xml",computers);
		ptree network;
		read_xml("network.xml",network);
		ptree events;
		read_xml("events.xml",events);
		CyberDNS *dns=new CyberDNS();
		vector<CyberExpert*> expertsVec;
                vector<CyberWorm*>worms;

		// building computers
		BOOST_FOREACH(ptree::value_type &v,computers){
                    CyberPC *pc=new CyberPC(v.second.get<string>("os"),v.second.get<string>("name"));
                    cout<<"Adding to server:"<<(*pc).getName()<<endl;
		    dns->AddPC(*pc);
		    cout<<(*pc).getName()<<" connected to server"<<endl;
		};

		// building network
		BOOST_FOREACH(ptree::value_type &v,network){
			cout << "Connecting " << v.second.get<string>("pointA") <<" to " <<v.second.get<string>("pointB")<< endl;
			dns->GetCyberPC(v.second.get<string>("pointA")).AddConnection(v.second.get<string>("pointB"));
			cout <<"        "<<v.second.get<string>("pointA")<<" now connected to "<<v.second.get<string>("pointB")<< endl;
			dns->GetCyberPC(v.second.get<string>("pointB")).AddConnection(v.second.get<string>("pointA"));
			cout <<"        "<<v.second.get<string>("pointB")<<" now connected to "<<v.second.get<string>("pointA")<< endl;

		};


       //build events
		int dayCount=0;
		int day=0;
		BOOST_FOREACH(ptree::value_type &v,events){

			cout<<"Day : "<<day<<endl;

			// hack
					if (v.first=="hack"){
						string compName= v.second.get<string>("computer");
						string WormName= v.second.get<string>("wormName");
                        int Dorm=v.second.get<int>("wormDormancy");
                        string Wormos=v.second.get<string>("wormOs");


                        cout<<"        "<<"Hack occured on "<<compName<<endl;

                        CyberWorm *worm=new CyberWorm(Wormos,WormName,Dorm);
                        dns->GetCyberPC(compName).Infect(*worm);



		}//end if hack
					if (v.first=="clock-in"){

						string ExpertName= v.second.get<string>("name");
						 int workTime=v.second.get<int>("workTime");
						 int restTime=v.second.get<int>("restTime");
						 int efficiency=v.second.get<int>("efficiency");
						 CyberExpert *expert=new CyberExpert(ExpertName,workTime,restTime,efficiency);
						 expertsVec.push_back(expert);
						 cout<<"    "<<"Clock-In: "<<ExpertName<<" began working"<<endl;

					}//end if clock in

					int size=expertsVec.size();
					 int already_checked=0;
					 for(int i=0;i<size && already_checked<(int)(dns->GetCyberPCList().size());i++){
						if( (*expertsVec[i]).getCount_Work_days()>0){
						(*expertsVec[i]).dailyCheck(*dns,already_checked);
						 (*expertsVec[i]).setCount_Work_days(1);
						   if((*expertsVec[i]).getCount_Work_days()==0){
						     cout<<(*expertsVec[i]).get_expert_Name()<<" is taking a break"<<endl;}
						}
						else if((*expertsVec[i]).getCount_Rest_days()>0){
							(*expertsVec[i]).setCount_Rest_days(1);
							if((*expertsVec[i]).getCount_Rest_days()==0)
							  cout<<(*expertsVec[i]).get_expert_Name()<<" is back to work"<<endl;


						}
						else {
							(*expertsVec[i]).setCount_Work_days(0);
							 (*expertsVec[i]).setCount_Work_days(1);
							(*expertsVec[i]).setCount_Rest_days(0);
							}




					 }//end for

					if (v.first=="termination"){
						dayCount=v.second.get<int>("time");}

					vector<string> list;
				    list=dns->GetCyberPCList();
				    std::reverse(list.begin(),list.end());
					//vector<string>::iterator itExp;
				    int Size=list.size();
				   for (int i=0; i<Size; i++){  
					 (dns->GetCyberPC(list[i])).Run(*dns);
				 }

					//clock-in

					if (v.first=="termination")
						dayCount=v.second.get<int>("time");

					day++;
		};
		while(day<=dayCount){
			cout<<"Day : "<<day<<endl;
			int size=expertsVec.size();
			 int already_checked=0;
			 for(int i=0;i<size&&already_checked<(int)( dns->GetCyberPCList().size() );i++){
						if( (*expertsVec[i]).getCount_Work_days()>0){
						(*expertsVec[i]).dailyCheck(*dns,already_checked);
						 (*expertsVec[i]).setCount_Work_days(1);
						   if((*expertsVec[i]).getCount_Work_days()==0){
						     cout<<(*expertsVec[i]).get_expert_Name()<<" is taking a break"<<endl;}
						}
						else if((*expertsVec[i]).getCount_Rest_days()>0){
							(*expertsVec[i]).setCount_Rest_days(1);
							if((*expertsVec[i]).getCount_Rest_days()==0)
							  cout<<(*expertsVec[i]).get_expert_Name()<<" is back to work"<<endl;

						}
						else if ((*expertsVec[i]).getCount_Rest_days()==0&&(*expertsVec[i]).getCount_Work_days()==0){
							(*expertsVec[i]).setCount_Work_days(0);
							 (*expertsVec[i]).setCount_Work_days(1);
							 (*expertsVec[i]).dailyCheck(*dns,already_checked);
							(*expertsVec[i]).setCount_Rest_days(0);
							}

		     }//daily event
			 vector<string> list;
			list=dns->GetCyberPCList();
			std::reverse(list.begin(),list.end());
			//vector<string>::iterator itExp;
			int Size=list.size();
		   for (int i=0; i<Size; i++){  //copy
			 (dns->GetCyberPC(list[i])).Run(*dns);
		    }//pc running
			day++;
		}
	int SIZE =expertsVec.size();
        for (int i=0; i<SIZE; i++){
        	delete expertsVec[i];
        	expertsVec[i]=NULL;

        }
       

delete dns;



    return 0;
}
