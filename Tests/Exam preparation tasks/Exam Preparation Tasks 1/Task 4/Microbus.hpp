
#ifndef MICROBUS
#define MICROBUS
#include"Vehicle.hpp"

class Microbus : public Vehicle {
public:
	Microbus(const std::string& brand = " ", const std::string& model = " ",
		const std::string& problem = "", Severity severity = Severity::None, const size_t& year = 0, Type type = Type::none, bool hasPassengers = false);

	bool getHasPassengers() const;
	void setHasPassengers(bool flag);

	Vehicle* clone();
	~Microbus() = default;
private:
	bool hasPassengers;
};

#endif // !MICROBUS