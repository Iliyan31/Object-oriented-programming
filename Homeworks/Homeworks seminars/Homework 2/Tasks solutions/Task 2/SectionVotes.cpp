
#include "SectionVotes.hpp"

SectionVotes::SectionVotes()
{
	vec.push_back(-1);
	vec.push_back(-1);
	vec.push_back(-1);
}

SectionVotes::SectionVotes(unsigned int party1Votes, unsigned int party2Votes, unsigned int party3Votes)
{

	vec.push_back(party1Votes);
	vec.push_back(party2Votes);
	vec.push_back(party3Votes);
}

SectionVotes::SectionVotes(const SectionVotes& s)
{
	for (int i = 0; i < 3; i++) {
		vec.push_back(s.vec[i]);
	}
}

int SectionVotes::votesForParty(Party _party) const
{
	int temp = this->vec[_party];
	return temp;
}

bool SectionVotes::operator!=(const SectionVotes& sec) const
{
	for (int i = 0; i < sec.vec.size(); i++) {
		if (vec[i] != sec.vec[i]) return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& _party)
{
	for (int i = 0; i < _party.vec.size(); i++) {
		out << _party.vec[i] << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, SectionVotes& _party)
{
	unsigned int num = -1;
	for (int i = 0; i < 3; i++) {
		in >> num;
		_party.vec[i] = num;
	}
	return in;
}