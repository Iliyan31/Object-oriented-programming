
/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Iliyan Yordanov
* @idnumber 62546
* @task 2
* @compiler VC
*/


#ifndef DUELIST
#define DUELIST

#include <iostream>


const int SIZE_NAME = 25;
const int NAME_EFFECT = 100;
const int SIZE_CARDS = 20;


class Monster {
private:
	char name[SIZE_NAME];
	unsigned int attackPoints;
	unsigned int protectingPoints;
public:
	Monster();
	Monster(const char*, unsigned int = 0, unsigned int = 0);
	Monster(const Monster& m);
	void showMonsterCard() const;
	
};

enum MagicCardType {
	Default,
	trap,
	buff,
	spell
};

class MagicCard {
private:
	char nameMag[SIZE_NAME];
	char effect[NAME_EFFECT];
	MagicCardType type;
public:
	MagicCard();
	MagicCard(const char*, const char*, MagicCardType);
	MagicCard(const MagicCard& ms);
	void showMagicCard() const;
	

};

class Deck {
private:
	Monster monsterCard[SIZE_CARDS];
	int _monsterCards;
	MagicCard magicCard[SIZE_CARDS];
	int _magicCards;
public:
	Deck();
	void createManuallyMonsterCardsInDeck(const int size, Deck& d);
	void createManuallyMagicCardsInDeck(const int size, Deck& d);
	void fillMonsterDeck(const Monster& m, int i);
	void showDeckMonster() const;
	void fillMagicDeck(const MagicCard& ms, int i);
	void showDeckMagic() const;
	int getMonsterCardCount() const;
	int getMagicCardCount() const;
	void addMonsterCard(const Monster& m);
	void addMagicCard(const MagicCard& ms);
	void changeMonsterCard(const int i, const Monster& m);
	void changeMagicCard(const int i, const MagicCard& ms);
};

class Duelist {
private:
	char* name;
	Deck deck;
public:
	Duelist();
	Duelist(const char*);
	void createManuallyMonsterCardsInDeckDuelist(const int size, Deck& d);
	void createManuallyMagicCardsInDeckDuelist(const int size, Deck& d);
	void fillMonsterDeck(const Monster& m, int i);
	void showDeckMonster() const;
	void fillMagicDeck(const MagicCard& ms, int i);
	void showDeckMagic() const;
	int getMonsterCardCount() const;
	int getMagicCardCount() const;
	void addMonsterCard(const Monster& m);
	void addMagicCard(const MagicCard& ms);
	void changeMonsterCard(const int i, const Monster& m);
	void changeMagicCard(const int i, const MagicCard& ms);
	~Duelist();
};

#endif // !DUELIST