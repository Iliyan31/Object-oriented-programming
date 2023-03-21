
#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name) {
	this->TestSuitName = name;
}

void TestSuite::add(const TestCase& _tests) {
	this->tests.push_back(_tests);
}

std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase> passedTests;
	for (int i = 0; i < tests.size(); i++) {
		if (tests.at(i).isPassing()) {
			passedTests.push_back(tests.at(i));
		}
	}
	return passedTests;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase> failedTests;
	for (int i = 0; i < tests.size(); i++) {
		if (tests.at(i).hasError()) {
			failedTests.push_back(tests.at(i));
		}
	}
	return failedTests;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType _error) const {
	std::vector<TestCase> new_vec;

	for (int i = 0; i < tests.size(); i++) {
		if (tests.at(i).getErrorType() == _error) {
			new_vec.push_back(tests.at(i));
		}
	}
	return new_vec;
}

void TestSuite::removeByErrorType(ErrorType _error) {

	for (int i = 0; i < tests.size(); i++) {
		if (tests.at(i).getErrorType() == _error) {
			tests.erase(tests.begin() + i);
		}
	}
}

std::string TestSuite::getName() const {
	return this->TestSuitName;
}

void TestSuite::setName(const std::string& str) {
	this->TestSuitName = str;
}