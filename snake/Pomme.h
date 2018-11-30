
#ifndef POMME_H
#define POMME_H

#include "ConsoleColor.h"
#include "Point.h"

class Pomme
{
private:
	ConsoleColor mCouleur;
	Point mPosition;
	char mDessin;

public:
	// Constructeur par d�faut
	Pomme();

	// get
	ConsoleColor couleur();
	Point position();
	char dessin();

	// set
	void setCouleur(ConsoleColor couleur);
	void setPosition(Point position);
	void setDessin(char dessin);

	// al�atoire
	size_t aleatoire(size_t minimum, size_t maximum);
};

#endif // POMME_H