
#ifndef ACTIONJEU_H
#define ACTIONJEU_H

#include"Serpent.h"
#include"Pomme.h"
#include"AireDeJeu.h"

class ActionJeu
{
private:
	int mToucheClavier;
	Serpent mSalazar;
	Pomme mPomme;
	bool partieEnCours;
	int mCompteur;
	int mEtat;
	AireDeJeu surfaceJeu;

	//Fonction
	void obtenirClavier();
	bool traiter(double tempsEcoule);
	void afficherJeu();
	

	int compteur();
	void setCompteur(int compteur);

public:
	ActionJeu();
	~ActionJeu();
	void lancer(); // boucle complete de jeu

};

#endif //ACTIONJEU_H




