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

#ifndef DECK
#define DECK
#include <vector>
#include <algorithm>

#include "PendulumCard.hpp"

class Deck {
private:
	std::vector<Card*> deck;
	std::string deckName;
public:
	Deck(const std::string& _name = " ");
	Deck(const Deck& d);
	Deck& operator=(const Deck& d);
	int MonsterCardCount() const;
	int MagicCardCount() const;
	int PendulumCardCount() const;
	int allCards() const;
	std::string getDeckName() const;
	void setDeckName(const std::string& name);

	void AddCard(Card* card);
	void changeCard(Card* c, unsigned int index);
	void clearDeck();
	void shuffleDeck();
	Card* getCards(int index) const;
	
	friend std::ostream& operator<<(std::ostream& out, const Deck& d);
	~Deck();
};

#endif // !DECK