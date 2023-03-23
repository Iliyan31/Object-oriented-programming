
#ifndef CAR
#define CAR
#include "Vehicle.hpp"

class Car : public Vehicle {
public:
	Car(const std::string& brand = " ", const std::string& model = " ", const std::string& problem = " ", Severity severity = Severity::None,
		const size_t& year = 0, Type type = Type::none, bool isPersonal = false);

	bool getIsCompany() const;
	bool getIsPersonal() const;

	void setIspersonal(bool flag);

	Vehicle* clone();
	~Car() = default;
private:
	bool isPersonal;
};

#endif // !CAR