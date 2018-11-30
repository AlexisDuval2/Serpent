#pragma once
class AireDeJeu
{
public:
	AireDeJeu();
	~AireDeJeu();

	size_t largeur();
	size_t hauteur();
	size_t largeurJouable();
	size_t hauteurJouable();

	//void afficherAirJeu();
	//void afficherGameOver;

private:
	size_t mLargeur;
	size_t mHauteur;
	size_t mLargeurJouable;
	size_t mHauteurJouable;
};

