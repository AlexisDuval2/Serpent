
#include "ActionJeu.h"
#include"ConsoleKeyReader.h"
#include "Console"
#include "ElapsedTimer.h"



using namespace std;

ActionJeu::ActionJeu()
	:mEtat{ 0 }
{
}

ActionJeu::~ActionJeu()
{
}

void ActionJeu::lancer()
{

		ElapsedTimer<> chronometre;
		chronometre.start();
		partieEnCours = true;

		while (partieEnCours) {
			if (chronometre.elapsedSeconds() >= 0.1) {
				obtenirClavier();
				partieEnCours = traiter(chronometre.restartSeconds());
				afficherJeu();
			}

		}



}

void ActionJeu::obtenirClavier()
{
	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	reader.installFilter(new ConsoleKeyFilterUp);			// Filtre qui enleve les touche qui monte
	reader.installFilter(new ConsoleKeyFilterModifiers);	//Filtre qui enleve les modifier "Ctrl + touche"
	ConsoleKeyReader::KeyEvents keyEvents;								//Classe event de la classe KeyReader

	keyEvents.clear();

	reader.read(keyEvents);
	

	for (auto event : keyEvents) {
		if (event.keyV() == char(37) && mSalazar.direction() != 'D') {
			// Si on a pesé la flèche gauche
			mToucheClavier = 37;
		}
		else if (event.keyV() == char(38) && mSalazar.direction() != 'B') {
			// Si on a pesé la flèche haut
			mToucheClavier = 38;
		}
		else if (event.keyV() == char(39) && mSalazar.direction() != 'G') {
			// Si on a pesé la flèche droite
			mToucheClavier = 39;
		}
		else if (event.keyV() == char(40) && mSalazar.direction() != 'H') {
			// Si on a pesé la flèche bas
			mToucheClavier = 40;
		}
		else if (event.keyV() == char(32))			//Si on a peser sur espace
		{
			mToucheClavier = 32;
		}
		else if (event.keyV() == char(73))			//Si touche i
		{
			mToucheClavier = 73;
		}
		else if (event.keyV() == char(66))			//Si touche b
		{
			mToucheClavier = 66;
		}
		else if (event.keyV() == char(81))			//Si touche q
		{
			mToucheClavier = 81;
		}
		else if (event.keyV() == char(80))			//Si touche p
		{
			mToucheClavier = 80;
		}
	}

	
}

bool ActionJeu::traiter(double tempsEcoule)
{

	

	if (mSalazar.tete().x() == mPomme.position().x() && mSalazar.tete().y() == mPomme.position().y())
	{
		mSalazar.setMange(true);
	}

	if (mToucheClavier == 37)
	{
		mSalazar.bougeAGauche();
		mSalazar.setDirection('G');

	}
	else if (mToucheClavier == 38)
	{
		mSalazar.bougeEnHaut();
		mSalazar.setDirection('H');
	}
	else if (mToucheClavier == 39)
	{
		mSalazar.bougeADroite();
		mSalazar.setDirection('D');
	}
	else if (mToucheClavier == 40)
	{
		mSalazar.bougeEnBas();
		mSalazar.setDirection('B');
	}

	if (mSalazar.tete().x() <= 4 || mSalazar.tete().x() >= 55 || mSalazar.tete().y() <= 4 || mSalazar.tete().y() >= 55)
	{
		mEtat = -1; //Game Over
		
	}

	if (mToucheClavier == 32)		//Espace Jouer
	{
		mEtat = 1;
		mSalazar.retourEtatDebut();
		mCompteur = 0;
	}
	else if (mToucheClavier == 73)		// I Instruction
	{
		mEtat = 2;
	}
	else if (mToucheClavier == 66) // b Retour Menu
	{
		mEtat = 0;
		mSalazar.retourEtatDebut();
		mCompteur = 0;

	}
	else if (mToucheClavier == 81) // q Quitter
	{
		return 0;

	}
	else if (mToucheClavier == 80) // p pause
	{
		mEtat = 5;

	}




	int compteur = 0;
	for (Point & p : mSalazar.corps())
	{
		if (compteur != 0) {
			if (mSalazar.tete().x() == p.x() && mSalazar.tete().y() == p.y()) {
				mEtat = -1;
			}
		}
		compteur++;
	}

	if (mSalazar.mange() == true)
	{
		mCompteur += 1;
		mSalazar.ajouterPoint(mPomme.position());
		mSalazar.setMange(false);

		Point temp(mPomme.aleatoire(5, 54), mPomme.aleatoire(5, 54));
		mPomme.setPosition(temp);
	}





	return true;
}

void ActionJeu::afficherJeu()
{
	if (mEtat == 0)//Menu Bienvenu
	{
		surfaceJeu.afficherMenuEntre();
	}
	else if (mEtat == -1)// Menu GameOver
	{
		surfaceJeu.afficherGameOver();
	}
	else if (mEtat == 2) //Instruction
	{
		surfaceJeu.afficherInstruction();
	}
	else // On joue!
	{
		surfaceJeu.afficherAirJeu(mSalazar, mPomme, mCompteur);
	}

	

}

int ActionJeu::compteur()
{
	return mCompteur;
}

void ActionJeu::setCompteur(int compteur)
{
	mCompteur = compteur;
}
