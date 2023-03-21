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

#include "Deck.hpp"

Deck::Deck() {
	this->deckName = " ";
}

Deck::Deck(std::string _deckName, std::vector<Monster> _monster, std::vector<Magic> _magic, std::vector<Pendulum> _pendulum) {
	this->deckName = _deckName;
	this->magic = _magic;
	this->monster = _monster;
	this->pendulum = _pendulum;
}

Deck::Deck(const Deck& d) {
	this->deckName = d.deckName;
	this->magic = d.magic;
	this->monster = d.monster;
	this->pendulum = d.pendulum;
}

void Deck::setDeckName(std::string name) {
	this->deckName = name;
}

std::string Deck::getDeckName() const {
	return this->deckName;
}

unsigned int Deck::getMonsterCardCount() const {
	return this->monster.size();
}

unsigned int Deck::getMagicCardCount() const {
	return this->magic.size();
}

unsigned int Deck::getPendulumCardCount() const {
	return this->pendulum.size();
}

void Deck::AddMonsterCard(Monster _mon) {
	this->monster.push_back(_mon);
}

void Deck::AddMagicCard(Magic _mag) {
	this->magic.push_back(_mag);
}

void Deck::AddPendulumCard(Pendulum _pen) {
	this->pendulum.push_back(_pen);
}

void Deck::ChangeMonsterCard(int index, Monster mon) {
	this->monster.at(index) = mon;
}

void Deck::ChangeMagicCard(int index, Magic mag) {
	this->magic.at(index) = mag;
}

void Deck::ChangePendulumrCard(int index, Pendulum pen) {
	this->pendulum.at(index) = pen;
}

void Deck::EmptyDeck() {
	this->setDeckName(" ");
	this->magic.clear();
	this->monster.clear();
	this->pendulum.clear();
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
	out << deck.getDeckName() << "|" << deck.getMonsterCardCount() << "|" << deck.getMagicCardCount() << "|" << deck.getPendulumCardCount() << std::endl;
	for (int i = 0; i < deck.getMonsterCardCount(); i++) {
		out << deck.monster[i].getName() << "|" << deck.monster[i].getEffect() << "|" << deck.monster[i].getAttack() << "|" << deck.monster[i].getDefence() << std::endl;
	}
	for (int i = 0; i < deck.getMagicCardCount(); i++) {
		out << deck.magic[i].getName() << "|" << deck.magic[i].getEffect() << "|";
	
		switch(deck.magic[i].getType()) {
		case Type::trap: out << "Trap" << std::endl; break;
		case Type::spell: out << "Spell" << std::endl; break;
		case Type::buff: out << "Buff" << std::endl; break;
		case Type::none: out << "None" << std::endl; break;
		}
	}
	for (int i = 0; i < deck.getPendulumCardCount(); i++) {
		out << deck.pendulum[i].getName() << "|" << deck.pendulum[i].getEffect() << "|" << deck.pendulum[i].getAttack() << "|"
			<< deck.pendulum[i].getDefence() << "|";

		switch (deck.pendulum[i].getType()) {
		case Type::trap: out << "Trap" << "|"; break;
		case Type::spell: out << "Spell" << "|"; break;
		case Type::buff: out << "Buff" << "|"; break;
		case Type::none: out << "None" << "|"; break;
		}
		out << deck.pendulum[i].getScale() << std::endl;
	}
	return out;
}