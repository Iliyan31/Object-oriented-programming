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
#include "Duelist.hpp"

int main() {

	MagicCard s("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, MagicType::spell);
	MagicCard c("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, MagicType::trap);
	MonsterCard m("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	Pendulum p("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 3, 1200, 600, MagicType::spell, 8);

	/*if (m > c) {
		std::cout << "Yes\n";
	}
	Deck d("New deck");*/

	//d.AddCard(&s);
	//d.AddCard(&c);
	//d.AddCard(&m);

	//d.changeCard(&c, 0);
	//std::cout << d.MagicCardCount();
	//std::cout << "\n";
	//d.clearDeck();
	//std::cout << d;
	Duelist player1("John");
	player1.getDeck().AddCard(&s);
	player1.getDeck().AddCard(&c);
	player1.getDeck().AddCard(&m);
	//player1.getDeck().changeCard(&c, 0);
	//player1.getDeck().AddCard(&p);
	player1.getDeck().setDeckName("Deck name");
	//std::cout << player1.getDeck().MagicCardCount()<<"\n";

	player1.saveDeck("file.txt");

	player1.getDeck().clearDeck();

	std::cout << player1.getDeck();
	std::cout << player1.getDeck().PendulumCardCount() << "\n";

	player1.loadDeck("file.txt");
	std::cout << player1.getDeck();
	// d* = &s

	Duelist player2("John2");
	player2.getDeck().AddCard(&s);
	player2.getDeck().AddCard(&c);
	player2.getDeck().AddCard(&m);
	//player2.getDeck().AddCard(&p);
	player2.getDeck().setDeckName("Deck name");


	std::cout<<player2.getDeck();

	player1.Duel(player2);
	return 0;


}