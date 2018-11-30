#include "AireDeJeu.h"



AireDeJeu::AireDeJeu()
	:	mLargeur{60},
		mHauteur{ 60 },
		mLargeurJouable{ 50 },
		mHauteurJouable{ 50 }
{
}


AireDeJeu::~AireDeJeu()
{
}

size_t AireDeJeu::largeur()
{
	return mLargeur;
}

size_t AireDeJeu::hauteur()
{
	return mHauteur;
}

size_t AireDeJeu::largeurJouable()
{
	return mLargeurJouable;
}

size_t AireDeJeu::hauteurJouable()
{
	return mHauteurJouable;
}
