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

Duelist::Duelist(std::string name) {
	this->duelistName = name;
}

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
		this->getDeck().EmptyDeck();
		int line = 1;
		int temp1 = 0;
		int temp2 = 0;
		int temp3 = 0;
		int numberOfSigns = 0;

		while (getline(file, buffer)) {

			numberOfSigns = 0;

			if (line == 1) {
				std::string Deckname;
				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						numberOfSigns++;
					}
					if (numberOfSigns == 0) {
						Deckname += buffer[i];
					}
					if (numberOfSigns == 1 && buffer[i]!='|') {
						temp1 = (temp1 * 10 + (buffer[i] - '0'));
					}
					if (numberOfSigns == 2 && buffer[i] != '|') {
						temp2 = (temp2 * 10 + (buffer[i] - '0'));
					}
					if (numberOfSigns == 3 && buffer[i] != '|') {
						temp3 = (temp3 * 10 + (buffer[i] - '0'));
					}
				}
				this->getDeck().setDeckName(Deckname);
			}

			if (line > 1 && line <= temp1 + 1) {

				std::string name;
				std::string effect;
				unsigned int defence = 0;
				unsigned int attack = 0;

				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						numberOfSigns++;
					}
					if (numberOfSigns == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (numberOfSigns == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (numberOfSigns == 2 && buffer[i] != '|') {
						defence = (defence * 10 + (buffer[i] - '0'));
					}
					if (numberOfSigns == 3 && buffer[i] != '|') {
						attack = (attack * 10 + (buffer[i] - '0'));
					}
				}
				Monster m(name, effect, defence, attack);
				this->getDeck().AddMonsterCard(m);
			}

			if (line > temp1 + 1 && line <= temp1 + temp2 + 1) {
				std::string name;
				std::string effect;
				std::string type;
				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						numberOfSigns++;
					}
					if (numberOfSigns == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (numberOfSigns == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (numberOfSigns == 2 && buffer[i] != '|') {
						type += buffer[i];
					}
				}
				if (type == "Buff") {
					Magic m(name, effect, Type::buff);
					this->getDeck().AddMagicCard(m);
				}
				if (type == "Spell") {
					Magic m(name, effect, Type::spell);
					this->getDeck().AddMagicCard(m);
				}
				if (type == "Trap") {
					Magic m(name, effect, Type::trap);
					this->getDeck().AddMagicCard(m);
				}
				if (type == "None") {
					Magic m(name, effect, Type::none);
					this->getDeck().AddMagicCard(m);
				}
			}
			if (line > (temp1 + temp2 + 1) && line <= (temp1 + temp2 + temp3 + 1)) {
				std::string name;
				std::string effect;
				unsigned int defence = 0;
				unsigned int attack = 0;
				unsigned int scale = 0;
				std::string type;

				for (int i = 0; i < buffer.size(); i++) {
					if (buffer.at(i) == '|') {
						numberOfSigns++;
					}
					if (numberOfSigns == 0 && buffer[i] != '|') {
						name += buffer[i];
					}
					if (numberOfSigns == 1 && buffer[i] != '|') {
						effect += buffer[i];
					}
					if (numberOfSigns == 2 && buffer[i] != '|') {
						defence = (defence * 10 + (buffer[i] - '0'));
					}
					if (numberOfSigns == 3 && buffer[i] != '|') {
						attack = (attack * 10 + (buffer[i] - '0'));
					}
					if (numberOfSigns == 4 && buffer[i] != '|') {
						type += buffer[i];
					}
					if (numberOfSigns == 5 && buffer[i] != '|') {
						scale = (scale * 10 + (buffer[i] - '0'));
					}
				}
				if (type == "Buff") {
					Pendulum p(name, effect, attack, defence, Type::buff, scale);
					this->getDeck().AddPendulumCard(p);
				}
				if (type == "Spell") {
					Pendulum p(name, effect, attack, defence, Type::spell, scale);
					this->getDeck().AddPendulumCard(p);
				}
				if (type == "Trap") {
					Pendulum p(name, effect, attack, defence, Type::trap, scale);
					this->getDeck().AddPendulumCard(p);
				}
				if (type == "None") {
					Pendulum p(name, effect, attack, defence, Type::none, scale);
					this->getDeck().AddPendulumCard(p);
				}
			}
			line++;
		}
		return true;
	}
}