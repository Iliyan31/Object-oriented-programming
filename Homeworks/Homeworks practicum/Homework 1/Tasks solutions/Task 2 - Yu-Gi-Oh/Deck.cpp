
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


Deck::Deck() : _monsterCards(0), _magicCards(0) {
	for (int i = 0; i < SIZE_CARDS; i++) {
		monsterCard[i] = Monster();
		magicCard[i] = MagicCard();
	}
}

void Deck::createManuallyMonsterCardsInDeck(const int size, Deck& d) {

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
		d.fillMonsterDeck(m, i);
	}
}

void Deck::createManuallyMagicCardsInDeck(const int size, Deck& d) {

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

		d.fillMagicDeck(ms, i);
	}
}

void Deck::fillMonsterDeck(const Monster& m, int i) {
	monsterCard[i] = m;
	_monsterCards++;
}

void Deck::showDeckMonster() const {
	std::cout << std::endl;
	for (int i = 0; i < SIZE_CARDS; i++) {
		monsterCard[i].showMonsterCard();
		std::cout << std::endl;
	}
}

void Deck::fillMagicDeck(const MagicCard& ms, int i) {
	magicCard[i] = ms;
	_magicCards++;
}

void Deck::showDeckMagic() const {
	std::cout << std::endl;
	for (int i = 0; i < SIZE_CARDS; i++) {
		magicCard[i].showMagicCard();
		std::cout << std::endl;
	}
}


int Deck::getMonsterCardCount() const {
	return _monsterCards;
}

int Deck::getMagicCardCount() const {
	return _magicCards;
}


void Deck::addMonsterCard(const Monster& m) {
	if (_monsterCards == SIZE_CARDS - 1) {
		printf("You can't add more cards");
		return;
	}
	monsterCard[_monsterCards] = m;
	_monsterCards++;
}

void Deck::addMagicCard(const MagicCard& ms) {
	if (_magicCards == SIZE_CARDS - 1) {
		printf("You can't add more cards");
		return;
	}
	magicCard[_magicCards] = ms;
	_monsterCards++;
}


void Deck::changeMonsterCard(const int i, const Monster& m) {
	if (i < SIZE_CARDS) {

		monsterCard[i - 1] = m;
		if (i - 1 > _monsterCards) {
			_monsterCards++;
		}
	}
	else {
		std::cout << "You can't add more than " << SIZE_CARDS << " cards!" << std::endl;
		return;
	}
}

void Deck::changeMagicCard(const int i, const MagicCard& ms) {
	if (i < SIZE_CARDS) {

		magicCard[i - 1] = ms;
		if (i - 1 > _magicCards) {
			_magicCards++;
		}
	}
	else {
		std::cout << "You can't add more than " << SIZE_CARDS << " cards!" << std::endl;
		return;
	}
}