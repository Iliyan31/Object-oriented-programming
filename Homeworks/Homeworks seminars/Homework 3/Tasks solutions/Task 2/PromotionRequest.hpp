
#ifndef PROMOTIONREQUEST
#define PROMOTIONREQUEST
#include "Request.hpp"

class PromotionRequest : public Request {
protected:
	double salary;
public:
	PromotionRequest();
	PromotionRequest(const std::string& sender, double amount);
	double getAmount() const;
};

#endif // !PROMOTIONREQUEST