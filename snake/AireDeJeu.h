#ifndef AIRDEJEU_H
#define AIRDEJEU_H

#include"ConsoleWriter.h"
#include"AireDeJeu.h"
#include"Serpent.h"
#include"Pomme.h"

class AireDeJeu
{
public:
	AireDeJeu();
	~AireDeJeu();

	size_t largeur();
	size_t hauteur();
	size_t largeurJouable();
	size_t hauteurJouable();

	void afficherAirJeu(Serpent &s, Pomme &p, int compteur);
	void afficherGameOver();
	void afficherMenuEntre();
	void afficherInstruction();

private:
	size_t mLargeur;
	size_t mHauteur;
	size_t mLargeurJouable;
	size_t mHauteurJouable;

	size_t x;
	size_t y;
};

#endif //AIRDEJEU_H

