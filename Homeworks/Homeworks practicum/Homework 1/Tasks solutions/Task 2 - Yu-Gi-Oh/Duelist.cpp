
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


#include "Duelist.hpp"

Duelist::Duelist() {
	strcpy_s(name, 7, "default");
	for (int i = 0; i < SIZE_CARDS * 2; i++) {
		deck = Deck();
	}
}

Duelist::Duelist(const char* _name) {
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

void Duelist::createManuallyMonsterCardsInDeckDuelist(const int size, Deck& d) {
	
	char nameMonster[SIZE_NAME];
	unsigned int attpoints;
	unsigned int protpoints;

	for (int i = 0; i < size; i++) {

		std::cin.ignore();
		printf("Name of the monster card: ");
		std::cin.getline(nameMonster, SIZE_NAME + 1);
		printf("Attack points of the monster card: ");
		std::cin >> attpoints;
		printf("Protecting points of the monster card: ");
		std::cin >> protpoints;
		Monster m(nameMonster, attpoints, protpoints);
		deck.fillMonsterDeck(m, i);
	}
}

void Duelist::createManuallyMagicCardsInDeckDuelist(const int size, Deck& d) {
	char nameMagic[SIZE_NAME];
	char eff[NAME_EFFECT];
	int _type;

	for (int i = 0; i < size; i++) {

		std::cin.ignore();
		printf("Name of the magic card: ");
		std::cin.getline(nameMagic, SIZE_NAME);
		printf("Name of the effect of the magic card: ");
		std::cin.getline(eff, SIZE_CARDS);
		printf("The type of the magic card (1-trap) (2-buff) (3-spell): ");

		do {
			std::cin >> _type;
		} while (_type < 1 || _type > 3);

		MagicCardType magType = static_cast<MagicCardType>(_type);
		MagicCard ms(nameMagic, eff, magType);

		deck.fillMagicDeck(ms, i);
	}
}

void Duelist::fillMonsterDeck(const Monster& m, int i) {
	deck.fillMonsterDeck(m, i);
}

void Duelist::showDeckMonster() const {
	deck.showDeckMonster();
}

void Duelist::fillMagicDeck(const MagicCard& ms, int i) {
	deck.fillMagicDeck(ms, i);
}

void Duelist::showDeckMagic() const {
	deck.showDeckMagic();
}


int Duelist::getMonsterCardCount() const {
	return deck.getMonsterCardCount();
}

int Duelist::getMagicCardCount() const {
	return deck.getMagicCardCount();
}


void Duelist::addMonsterCard(const Monster& m) {
	deck.addMonsterCard(m);
}

void Duelist::addMagicCard(const MagicCard& ms) {
	deck.addMagicCard(ms);
}


void Duelist::changeMonsterCard(const int i, const Monster& m) {
	deck.changeMonsterCard(i, m);
}

void Duelist::changeMagicCard(const int i, const MagicCard& ms) {
	deck.changeMagicCard(i, ms);
}

Duelist::~Duelist() {
	delete[] name;
}