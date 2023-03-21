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

Deck::Deck(const std::string& _name) : deckName(_name) {}

Deck::Deck(const Deck& d) {
	this->deckName = d.deckName;
	for (int i = 0; i < d.deck.size(); i++) {
		this->AddCard(d.deck[i]);
	}
}

Deck& Deck::operator=(const Deck& d) {
	if (this != &d) {
		for (int i = 0; i < this->deck.size(); i++) {
			delete this->deck[i];
		}
		this->deckName = d.deckName;
		for (int i = 0; i < d.deck.size(); i++) {
			this->AddCard(d.deck[i]);
		}
	}
	return *this;
}

int Deck::MonsterCardCount() const {
	int count = 0;
	for (int i = 0; i < this->deck.size(); i++) {
		if (deck[i]->getCardType() == CardType::Monster) {
			count++;
		}
	}
	return count;
}

int Deck::MagicCardCount() const {
	int count = 0;
	for (int i = 0; i < this->deck.size(); i++) {
		if (deck[i]->getCardType() == CardType::Magic) {
			count++;
		}
	}
	return count;
}

int Deck::PendulumCardCount() const {
	int count = 0;
	for (int i = 0; i < this->deck.size(); i++) {
		if (deck[i]->getCardType() == CardType::pendulum) {
			count++;
		}
	}
	return count;
}

int Deck::allCards() const {
	return MonsterCardCount() + MagicCardCount() + PendulumCardCount();
}

std::string Deck::getDeckName() const {
	return this->deckName;
}

void Deck::setDeckName(const std::string& name) {
	this->deckName = name;
}

void Deck::AddCard(Card* card) {
	this->deck.push_back(card->clone());
}

void Deck::changeCard(Card* c, unsigned int index) {
	if (index >= 0 && index < deck.size()) {
		for (int i = 0; i < deck.size(); i++) {
			if (this->deck[i]->getCardType() == c->getCardType() && i == index) {
				delete deck[i];
				deck[i] = c->clone();	
			}
		}
	}
	else {
		std::cerr << "Index cannot be below 0 and above " << deck.size() << "!\n";
	}
}

void Deck::clearDeck() {
	for (int i = 0; i < deck.size(); i++) {
		delete deck[i];
	}
	deck.clear();
}

void Deck::shuffleDeck() {
	std::random_shuffle(deck.begin(), deck.end());	
}

Card* Deck::getCards(int index) const {
	for (int i = 0; i < deck.size(); i++) {
		if (i == index) {
			return deck[i];
		}
	}
}


Deck::~Deck() { 
	for (int i = 0; i < deck.size(); i++) {
		delete this->deck[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Deck& d) {

	out << d.getDeckName() << "|" << d.allCards() << "|" << d.MonsterCardCount() << "|" << d.MagicCardCount() << "|" << d.PendulumCardCount() << std::endl;
	for (int i = 0; i < d.deck.size(); i++) {
		MonsterCard* monster = dynamic_cast<MonsterCard*>(d.deck[i]);
		MagicCard* magic = dynamic_cast<MagicCard*>(d.deck[i]);
		if (monster && !magic) {
			out << monster->getName() << "|" << monster->getEffect() << "|" << monster->getRarity() << "|" 
				<< monster->getAttackPoints() << "|" << monster->getProtectPoints()<<  std::endl;
		}
	}
	for (int i = 0; i < d.deck.size(); i++) {
		MonsterCard* monster = dynamic_cast<MonsterCard*>(d.deck[i]);
		MagicCard* magic = dynamic_cast<MagicCard*>(d.deck[i]);
		if (magic && !monster) {
			out << magic->getName() << "|" << magic->getEffect() << "|" << magic->getRarity() << "|";

			switch (magic->getMagicType()) {
			case MagicType::trap: out << "Trap" << std::endl; break;
			case MagicType::spell: out << "Spell" << std::endl; break;
			case MagicType::buff: out << "Buff" << std::endl; break;
			case MagicType::None: out << "None" << std::endl; break;
			}
		}
	}

	for (int i = 0; i < d.deck.size(); i++) {
		Pendulum* pendulum = dynamic_cast<Pendulum*>(d.deck[i]);
		if (pendulum) {
			out << pendulum->getName() << "|" << pendulum->getEffect() << "|" << pendulum->getRarity() << "|"
				<< pendulum->getAttackPoints() << "|" << pendulum->getProtectPoints() << "|" << pendulum->getScale() << "|";

			switch (pendulum->getMagicType()) {
			case MagicType::trap: out << "Trap\n"; break;
			case MagicType::spell: out << "Spell\n"; break;
			case MagicType::buff: out << "Buff\n"; break;
			case MagicType::None: out << "None\n"; break;
			}
		}
	}
	return out;
}
