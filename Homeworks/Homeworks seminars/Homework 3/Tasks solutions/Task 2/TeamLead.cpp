
#include "TeamLead.hpp"


TeamLead::TeamLead(const std::string& name, double salary) : Developer(name) {
	this->salary = salary;
	this->leader = this;
}

std::vector<Developer*> TeamLead::getTeam() const {
	return this->dev;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
	if (developer == nullptr) {
		std::cout << "There is no developer!\n";
	}
	else {
		developer->setInitialSalary(salary);
		developer->setTeamLeader(this->leader);
		this->dev.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
	int temp = -1;
	for (int i = 0; i < dev.size(); i++) {
		if (dev.at(i)->getName() == name) {
			temp = i;
		}
	}
	if (temp > -1) {
		TeamLead* temp1 = nullptr;
		dev.at(temp)->setTeamLeader(temp1);
		dev.erase(dev.begin() + temp);
	}	
}

void TeamLead::increaseTeamSalariesBy(double amount) {
	for (int i = 0; i < dev.size(); i++) {
		int temp = amount;
		temp += dev.at(i)->getSalary();
		dev.at(i)->setSalary(temp);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
	for (int i = 0; i < dev.size(); i++) {
		int temp = amount;
		if (dev.at(i)->getSalary() >= amount) {
			temp = dev.at(i)->getSalary() - amount;
			dev.at(i)->setSalary(temp);
		}
		else {
			dev.at(i)->setSalary(0);
		}
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
	this->leave.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
	this->promo.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
	
	for (int i = 0; i < leave.size(); i++) {
		int temp = -1;
		for (int j = 0; j < dev.size(); j++) {
			if (leave.at(i).getSender() == dev.at(j)->getName()) {
				temp = j;
			}
		}
		if (temp > -1) {
			dev.at(temp)->setTeamLeader(nullptr);
			removeDeveloperFromTeam(leave.at(i).getSender());
			leave.erase(leave.begin() + i);
		}
	}
}

void TeamLead::fulfillPromotionRequests() {

	for (int i = 0; i < promo.size(); i++) {
		bool flag = false;
		for (int j = 0; j < dev.size(); j++) {
			if (promo.at(i).getSender() == dev.at(j)->getName()) {
				int salary = dev.at(j)->getSalary();
				salary += promo.at(i).getAmount();
				dev.at(j)->setSalary(salary);
				flag = true;
			}
		}
		if (flag == true) {
			promo.erase(promo.begin() + i);
		}
	}
}