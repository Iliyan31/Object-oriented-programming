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

int main() {
	//Magic m("Magic", "effect", Type::buff);

	////Duelist player1("Player1");
	//player1.getDeck().AddMagicCard(m);
	//std::cout<<player1.getDeck().getMagicCardCount();
	//player1.getDeck().setDeckName("This is deck");
	//player1.saveDeck("copy.txt");
	////player1.loadDeck("copy.txt");
	////std::cout << player1.getDeck().getMagicCardCount() << std::endl;
	////std::cout << player1.getDeck().getDeckName() << std::endl;

	Monster dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	Monster magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	Magic swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", Type::spell);
	Magic cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",Type::trap);
	Pendulum timegazer("Timegazer","Your opponent cannot activate Trap Magic Cards", 1200, 600, Type::spell, 8);
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckName("Magician Deck");
	firstDuelist.getDeck().AddMonsterCard(dragon);
	firstDuelist.getDeck().AddMagicCard(swords);
	firstDuelist.getDeck().AddMonsterCard(magician);
	firstDuelist.getDeck().AddMagicCard(cylinder);
	firstDuelist.getDeck().AddPendulumCard(timegazer);
	//firstDuelist.display();
	firstDuelist.saveDeck("copy.txt");
	firstDuelist.loadDeck("copy.txt");
	//firstDuelist.display();
	Magic box("Mystic Box", "Destroy one monster.", Type::spell);
	firstDuelist.getDeck().ChangeMagicCard(1, box);
	firstDuelist.saveDeck("copy.txt");

	std::cout << firstDuelist.getDeck();
	return 0;
}