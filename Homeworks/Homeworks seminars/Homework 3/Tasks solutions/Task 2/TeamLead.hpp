
#ifndef TEAMLEAD
#define TEAMLEAD
#include <vector>
#include "Developer.hpp"

class TeamLead : public Developer {
protected:
	std::vector<Developer*> dev; 
	std::vector<LeavingRequest> leave;
	std::vector<PromotionRequest> promo;
public:
	TeamLead(const std::string& name, double salary);
	std::vector<Developer*> getTeam() const;
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();

};

#endif // !TEAMLEAD