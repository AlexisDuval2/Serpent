
#include "Pomme.h"
#include <algorithm>
#include <numeric>
#include <random>

Pomme::Pomme()
	:mCouleur{ ConsoleColor::by + ConsoleColor::tr },
	mPosition(30, 30),
	mDessin{ char(219) }
{
}

// get
ConsoleColor Pomme::couleur() {
	return mCouleur;
}

Point Pomme::position() {
	return mPosition;
}

char Pomme::dessin() {
	return mDessin;
}

// set
void Pomme::setCouleur(ConsoleColor couleur) {
	mCouleur = couleur;
}

void Pomme::setPosition(Point position) {
	mPosition = position;
}

void Pomme::setDessin(char dessin) {
	mDessin = dessin;
}

// aléatoire
size_t Pomme::aleatoire(size_t minimum, size_t maximum)
{
	std::random_device device;
	std::mt19937 engine(device());
	std::uniform_int_distribution<size_t> distribution(minimum, maximum);

	return distribution(engine);
}


