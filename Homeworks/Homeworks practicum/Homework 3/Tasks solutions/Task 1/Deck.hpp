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
#include "baseClass.hpp"
#include "monsterCard.hpp"
#include "magicCard.hpp"
#include "PendulumCard.hpp"
#include <vector>

class Deck {
protected:
	std::string deckName;
	std::vector<Monster> monster;
	std::vector<Magic> magic;
	std::vector<Pendulum> pendulum;
public:
	Deck();
	Deck(std::string _deckName, std::vector<Monster> _monster, std::vector<Magic> _magic, std::vector<Pendulum> _pendulum);
	Deck(const Deck& d);
	~Deck() = default;
	void setDeckName(std::string name);
	std::string getDeckName() const;
	unsigned int getMonsterCardCount() const;
	unsigned int getMagicCardCount() const;
	unsigned int getPendulumCardCount() const;
	void AddMonsterCard(Monster _mon);
	void AddMagicCard(Magic _mag);
	void AddPendulumCard(Pendulum _pen);
	void ChangeMonsterCard(int index, Monster mon);
	void ChangeMagicCard(int index, Magic mag);
	void ChangePendulumrCard(int index, Pendulum pen);
	void EmptyDeck();
	friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};
#endif // !DECK