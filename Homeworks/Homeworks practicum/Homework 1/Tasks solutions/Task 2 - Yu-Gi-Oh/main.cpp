
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

int main() {

	Deck d;
	
	int monsterCardsAmount = 0;

	do {
		printf("Please insert how much monster cards will you have ont the desk: ");
		std::cin >> monsterCardsAmount;
	} while (monsterCardsAmount > 20);
	
	d.createManuallyMonsterCardsInDeck(monsterCardsAmount, d);
	
	Monster BlueEyeDragon("Blue-eyes white dragon", 3000, 2500);
	d.changeMonsterCard(4, BlueEyeDragon);
	std::cout << std::endl;
	//d.showDeckMonster();
	

	Duelist player1("Seto Kaiba");
	Monster DarkMagician("Dark Magician", 2500, 2100);
	player1.changeMonsterCard(2, DarkMagician);
	player1.showDeckMonster();



	int amountOfMagicCards;
	do {
		printf("Please insert how much magic cards will you have ont the desk: ");
		std::cin >> amountOfMagicCards;
	} while (amountOfMagicCards > 20);
	d.createManuallyMagicCardsInDeck(amountOfMagicCards, d);
	MagicCard Reflection("Reflection", "Reflects the last played spell", trap);
	d.changeMagicCard(2, Reflection);
	//d.showDeckMagic();

	Duelist player2("Yugi Muto");
	player2.createManuallyMagicCardsInDeckDuelist(amountOfMagicCards, d);
	//player2.showDeckMagic();
	MagicCard Reflection1("Reflection", "Reflects the last played spell", trap);
	player2.changeMagicCard(2, Reflection1);
	player2.showDeckMagic();
	
	return 0;
}