
#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	unsigned int num1 = 0, num2 = 0, num3 = 0;
	std::string buffer;
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error!\n";
	}
	if (file.is_open()) {
		while (getline(file, buffer)) {
			
			std::string temp;
			temp = buffer;

			int spaces = 1;
			for (int i = 0; i < temp.size(); i++) {
				if ((spaces >= 1 && spaces <= 3) && (temp[i] <= 57 && temp[i] >= 48)) {
					if (spaces == 1) {
						num1 = (num1 * 10 + (temp[i]-48));
					}
					if (spaces == 2) {
						num2 = (num2 * 10 + (temp[i]-48));
					}
					if (spaces == 3) {
						num3 = (num3 * 10 + (temp[i]-48));
					}
				}
				if (temp[i] == 32 && temp[i+1] !=32) {
					spaces++;
				}
			}
			SectionVotes _votes(num1, num2, num3);
			this->votes.push_back(_votes);
			num1 = 0;
			num2 = 0;
			num3 = 0;
		}
	}
	file.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
	return this->votes.size();
}

int ElectionResultsDatabase::votesForParty(Party _party) const
{
	int sum = 0;
	for (int i = 0; i < votes.size(); i++) {
		sum += votes[i].votesForParty(_party);
	}
	return sum;
}

Party ElectionResultsDatabase::winningParty() const
{
	int Party1 = votesForParty(Party::PARTY1);
	int Party2 = votesForParty(Party::PARTY2);
	int Party3 = votesForParty(Party::PARTY3);
	if (Party1 >= Party2 && Party1 >= Party3) {
		return Party::PARTY1;
	}
	else if (Party2 > Party1 && Party2 >= Party3) {
		return Party::PARTY2;
	}
	else if (Party3 > Party1 && Party3 > Party2) {
		return Party::PARTY3;
	}
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& _party)
{
	for (int i = 0; i < _party.votes.size(); i++) {
		out << _party.votes[i] << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& _party)
{
	SectionVotes sec;
	SectionVotes temp;
	in >> sec;
	while (sec != temp) {
		_party.votes.push_back(sec);
		in >> sec;
	}
	return in;
}