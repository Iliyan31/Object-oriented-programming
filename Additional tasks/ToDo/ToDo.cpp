
#include "ToDo.h"

ToDo::ToDo(const char* id, bool finish) : finished(finish) {
	strcpy(this->Id, id);
}

ToDo::ToDo(const ToDo& t) : finished(t.finished) {
	this->Id = new char[strlen(t.Id) + 1];
	strcpy(this->Id, t.Id);
}

ToDo& ToDo::operator=(const ToDo& t) {
	delete[] this->Id;
	if (this != &t) {
		this->Id = t.Id;
		this->finished = t.finished;
	}
	return *this;
}

ToDo::~ToDo() {
	delete[] Id;
}

void ToDo::print() const {
	std::cout << "The ID of the task: " << Id;
	std::cout << "Finished / Not: " << finished;
}