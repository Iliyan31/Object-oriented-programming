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

#include "Duelist.hpp"

Duelist::Duelist(const std::string& _name) : duelistName(_name) {}

Deck& Duelist::getDeck() {
	return this->deck;
}

bool Duelist::saveDeck(const char* name) {
	std::ofstream file(name);
	if (!file) {
		std::cerr << "File can't be opened\n";
		return false;
	}
	else {
		file << getDeck();
		return true;
	}
}

bool Duelist::loadDeck(const char* name) {
	std::ifstream file(name);
	std::string buffer;
	if (!file) {
		std::cerr << "File can't be opened\n";
		return false;
	}
	else {
		this->deck.clearDeck();

		unsigned int line = 1;
		unsigned int signs = 0;
		unsigned int allcards = 0;
		unsigned int monsterCards = 0;
		unsigned int magicCards = 0;
		unsigned int pendulumCards = 0;

		while (getline(file, buffer)) {

			signs = 0;
;
			if (line == 1) {

				std::string DeckName;
				for (int i = 0; i < buffer.size(); i++) {
					if (buffer[i] == '|') {
						signs++;
					}
					if (signs == 0) {
						DeckName += buffer[i];
					}
					if (signs == 1 && buffer[i] != '|') {
						allcards = (allcards * 10 + (buffer[i] - '0'));
					}
					if (signs == 2 && buffer[i] != '|') {
						monsterCards = (monsterCards * 10 + (buffer[i] - '0'));
					}
					if (signs == 3 && buffer[i] != '|') {
						magicCards = (magicCards * 10 + (buffer[i] - '0'));
					}
					if (signs == 4 && buffer[i] != '|') {
						pendulumCards = (pendulumCards * 10 + (buffer[i] - '0'));
					}
				}
				this->getDeck().setDeckName(DeckName);

			}

			if (line > 1 && line <= monsterCards + 1) {

				std::string name;
				std::string effect;
				unsigned int defence = 0;
				unsigned int attack = 0;
				unsigned int rarity = 0;

				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						signs++;
					}
					if (signs == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (signs == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (signs == 2 && buffer[i] != '|') {
						rarity = (rarity * 10 + (buffer[i] - '0'));
					}
					if (signs == 3 && buffer[i] != '|') {
						attack = (attack * 10 + (buffer[i] - '0'));
					}
					if (signs == 4 && buffer[i] != '|') {
						defence = (defence * 10 + (buffer[i] - '0'));
					}
				}
				MonsterCard m(name, effect,rarity, attack, defence);
				this->getDeck().AddCard(&m);
			}


			if (line > monsterCards + 1 && line <= monsterCards + magicCards + 1) {
				std::string name;
				std::string effect;
				unsigned int rarity = 0;
				std::string type;
				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						signs++;
					}
					if (signs == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (signs == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (signs == 2 && buffer[i] != '|') {
						rarity = (rarity * 10 + (buffer[i] - '0'));
					}
					if (signs == 3 && buffer[i] != '|') {
						type += buffer[i];
					}
				}
				if (type == "Buff") {
					MagicCard m(name, effect, rarity, MagicType::buff);
					this->getDeck().AddCard(&m);
				}
				if (type == "Spell") {
					MagicCard m(name, effect, rarity, MagicType::spell);
					this->getDeck().AddCard(&m);
				}
				if (type == "Trap") {
					MagicCard m(name, effect, rarity, MagicType::trap);
					this->getDeck().AddCard(&m);
				}
				if (type == "None") {
					MagicCard m(name, effect, rarity, MagicType::None);
					this->getDeck().AddCard(&m);
				}
			}

			if (line > (monsterCards + magicCards + 1) && line <= (monsterCards + magicCards + pendulumCards + 1)) {
				std::string name;
				std::string effect;
				unsigned int rarity = 0;
				unsigned int attack = 0;
				unsigned int defence = 0;
				unsigned int scale = 0;
				std::string type;

				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						signs++;
					}
					if (signs == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (signs == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (signs == 2 && buffer[i] != '|') {
						defence = (defence * 10 + (buffer[i] - '0'));
					}
					if (signs == 3 && buffer[i] != '|') {
						defence = (defence * 10 + (buffer[i] - '0'));
					}
					if (signs == 4 && buffer[i] != '|') {
						attack = (attack * 10 + (buffer[i] - '0'));
					}
					if (signs == 5 && buffer[i] != '|') {
						scale = (scale * 10 + (buffer[i] - '0'));						
					}
					if (signs == 6 && buffer[i] != '|') {
						type += buffer[i];
					}
				}
				if (type == "Buff") {
					Pendulum p(name, effect, rarity, attack, defence, MagicType::buff, scale);
					this->getDeck().AddCard(&p);
				}
				if (type == "Spell") {
					Pendulum p(name, effect, rarity, attack, defence, MagicType::spell, scale);
					this->getDeck().AddCard(&p);
				}
				if (type == "Trap") {
					Pendulum p(name, effect, rarity, attack, defence, MagicType::trap, scale);
					this->getDeck().AddCard(&p);
				}
				if (type == "None") {
					Pendulum p(name, effect, rarity, attack, defence, MagicType::None, scale);
					this->getDeck().AddCard(&p);
				}
			}
			line++;
		}
		return true;
	}
}


void Duelist::Duel(Duelist& d) {
	unsigned int player1 = 0;
	unsigned int player2 = 0;

	if (this->getDeck().allCards() == d.getDeck().allCards()) {
		this->getDeck().shuffleDeck();
		d.getDeck().shuffleDeck();
		for (int i = 0; i < d.getDeck().allCards(); i++) {

			if (*this->getDeck().getCards(i) > *d.getDeck().getCards(i)) {
				printf("Point for Player 1\n"); 
				player1++;
			}
			else if (*this->getDeck().getCards(i) < *d.getDeck().getCards(i)) {
				printf("Point for Player 2\n");
				player2++;
			}
			else {
				printf("Draw\n");
			}
		}

		if (player1 == player2) {
			printf("The duel ends with draw!\n");
		}
		else if (player1 > player2) {
			printf("Player 1 wins!\n");
		}
		else {
			printf("Player 2 wins!\n");
		}
	}
	else {
		std::cout << "The players dont't have equal card count!\n";
	}
}