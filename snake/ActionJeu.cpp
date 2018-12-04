
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
	//mToucheClavier = 0;

	

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
	else if (mToucheClavier == 32)
	{
		mEtat = 1;
	}
	else if (mToucheClavier == 73)
	{
		mEtat = 2;
	}
	else if (mToucheClavier == 66)
	{
		mEtat = 0;
	}


	if (mSalazar.tete().x() <= 4 || mSalazar.tete().x() >= 55 || mSalazar.tete().y() <= 4 || mSalazar.tete().y() >= 55)
	{
		mEtat = -1; //Game Over
	}

	int compteur = 0;
	for (Point & p : mSalazar.corps())
	{
		if (compteur != 0) {
			if (mSalazar.tete().x() == p.x() && mSalazar.tete().y() == p.y()) {
				return false;
			}
		}
		compteur++;
	}

	if (mSalazar.mange() == true)
	{
		mCompteur += 1;
		mSalazar.ajouterPoint(mPomme.position());
		mSalazar.setMange(false);

		Point temp(mPomme.aleatoire(5, 55), mPomme.aleatoire(5, 55));
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

	else
	{
		ConsoleWriter & writer{ Console::getInstance().writer() };



		writer.createImage("background");

		size_t a{ 5 };
		size_t b{ 50 };
		size_t c{ 57 };
		size_t d{ 16 };
		size_t e{ 22 };



		writer.image("background").fill(a, a, b, b, char(219), ConsoleColor::by + ConsoleColor::ty);
		writer.image("background").fill(e, c, d, a, char(219), ConsoleColor::bw + ConsoleColor::tw);
		writer.image("background").drawText(e + 1, c + 2, "Point: " + to_string(mCompteur), ConsoleColor::bw + ConsoleColor::tk, true);
		writer.createImage("imageJeu");
		writer.push("background", "imageJeu");

		writer.image("imageJeu").drawPoint(mPomme.position().x(), mPomme.position().y(), mPomme.dessin(), mPomme.couleur());

		for (Point & p : mSalazar.corps())
		{
			writer.image("imageJeu").drawPoint(p.x(), p.y(), mSalazar.forme(), mSalazar.couleur());
			writer.push("imageJeu");
		}



		if (partieEnCours == false)
		{


		}

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
