
#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest() : Request(), salary(0) {}

PromotionRequest::PromotionRequest(const std::string& sender, double amount)
	: Request("I want a raise!", sender), salary(amount) {}

double PromotionRequest::getAmount() const {
	return this->salary;
}