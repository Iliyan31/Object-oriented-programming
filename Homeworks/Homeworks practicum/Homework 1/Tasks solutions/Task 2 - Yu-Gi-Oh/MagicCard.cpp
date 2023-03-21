
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


MagicCard::MagicCard() : type(Default) {
	strcpy_s(nameMag, 2, " ");
	strcpy_s(effect, 2, " ");
}

MagicCard::MagicCard(const char* _nameMag, const char* _effect, MagicCardType _type) {

	strcpy_s(nameMag, (strlen(_nameMag) + 1), _nameMag);
	strcpy_s(effect, (strlen(_effect) + 1), _effect);
	type = _type;
}

MagicCard::MagicCard(const MagicCard& ms) {

	strcpy_s(nameMag, (strlen(ms.nameMag) + 1), ms.nameMag);
	strcpy_s(effect, (strlen(ms.effect) + 1), ms.effect);

	type = ms.type;
}

void MagicCard::showMagicCard() const {
	std::cout << "The name of the Magic card: " << nameMag << std::endl;
	std::cout << "The effect of the card: " << effect << std::endl;
	std::cout << "The type of the card: " << type << std::endl;
}