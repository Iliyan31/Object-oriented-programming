
#ifndef DEVELOPER
#define DEVELOPER
#include <iostream>
#include <string>

#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
class TeamLead;

class Developer {		
protected:
	TeamLead* leader;	
	std::string name;
	double salary;
public:
	Developer();
	Developer(const std::string& name);
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void setTeamLeader(TeamLead* teamLeader);
	void setSalary(double amount);
};

#endif // !DEVELOPER