
#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
private:
    std::vector<int> vec;
public:
    SectionVotes();
    SectionVotes(unsigned int party1Votes, unsigned int party2Votes, unsigned int party3Votes);
    SectionVotes(const SectionVotes& s);
    int votesForParty(Party) const;
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& _party);
    friend std::istream& operator>>(std::istream& in, SectionVotes& _party);
    bool operator!=(const SectionVotes& sec) const;
};

