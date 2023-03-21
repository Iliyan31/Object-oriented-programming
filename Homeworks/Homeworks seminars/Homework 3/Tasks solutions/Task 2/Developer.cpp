
#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer() 
	: name(" "), salary(0), leader(nullptr) {}

Developer::Developer(const std::string& name)
	: name(name), salary(0), leader(nullptr) {}

std::string Developer::getName() const {
	return this->name;
}

double Developer::getSalary() const {
	return this->salary;
}

TeamLead* Developer::getTeamLead() const {
	return this->leader;
}

void Developer::setInitialSalary(double amount) {
	if (this->salary == 0) {
		this->salary = amount;
	}
	else {
		std::cerr << "You can't set initial salary if there is already one!\n";
	}
}

void Developer::sendLeavingRequest() {
	if (this->leader != nullptr) {
		LeavingRequest l(this->name);
		this->leader->addLeavingRequest(l);
	}
}

void Developer::sendPromotionRequest(double amount) {
	if (this->leader != nullptr) {
		PromotionRequest p(this->name, amount);
		this->leader->addPromotionRequest(p);
	}
}

void Developer::setTeamLeader(TeamLead* teamLeader) {
	this->leader = teamLeader;
}

void Developer::setSalary(double amount) {
	this->salary = amount;
}