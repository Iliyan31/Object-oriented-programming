/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/

#ifndef DUELIST
#define DUELIST
#include "Deck.hpp"
#include <fstream>
class Duelist {
private:
	std::string duelistName;
	Deck deck;
public:
	Duelist(const std::string& _name = " ");
	Deck& getDeck();
	bool saveDeck(const char* name);
	bool loadDeck(const char* name);
	void Duel(Duelist& d);
};

#endif // !DUELIST
