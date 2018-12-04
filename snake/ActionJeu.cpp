
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
	// mettre position al�atoire pomme rouge
	Point temp(mPommeRouge.aleatoire(6, 54), mPommeRouge.aleatoire(6, 54));
	mPommeRouge.setPosition(temp);

	// patch temporaire...
	// mettre position impossible pour pomme verte
	Point impossible(2,2);
	mPommeVerte.setPosition(impossible);

	// mettre couleur verte � la pomme verte
	mPommeVerte.setCouleur(ConsoleColor::by + ConsoleColor::tg);

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
			// Si on a pes� la fl�che gauche
			mToucheClavier = 37;
		}
		else if (event.keyV() == char(38) && mSalazar.direction() != 'B') {
			// Si on a pes� la fl�che haut
			mToucheClavier = 38;
		}
		else if (event.keyV() == char(39) && mSalazar.direction() != 'G') {
			// Si on a pes� la fl�che droite
			mToucheClavier = 39;
		}
		else if (event.keyV() == char(40) && mSalazar.direction() != 'H') {
			// Si on a pes� la fl�che bas
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
	if (mSalazar.tete().x() == mPommeRouge.position().x() && mSalazar.tete().y() == mPommeRouge.position().y()
		|| mSalazar.tete().x() == mPommeVerte.position().x() && mSalazar.tete().y() == mPommeVerte.position().y()) {

		mSalazar.setMange(true);

		if (mSalazar.tete().x() == mPommeVerte.position().x() && mSalazar.tete().y() == mPommeVerte.position().y()) {
			mCompteur += 4; // pomme verte vaut 4 points de plus
		}
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

	int compteurTemp = 0;
	for (Point & p : mSalazar.corps())
	{
		if (compteurTemp != 0) {
			if (mSalazar.tete().x() == p.x() && mSalazar.tete().y() == p.y()) {
				return false;
			}
		}
		compteurTemp++;
	}

	if (mSalazar.mange() == true)
	{
		mCompteur += 1;

		// le serpent grandit
		mSalazar.ajouterPoint(mPommeRouge.position());
		mSalazar.setMange(false);

		// 1 chance sur 5 d'avoir une pomme verte
		mProbabilitePommeVerte = mPommeVerte.aleatoire(1, 5);
		if (mProbabilitePommeVerte == 1) {
			Point temp(mPommeVerte.aleatoire(6, 54), mPommeVerte.aleatoire(6, 54));
			mPommeVerte.setPosition(temp);
			mAfficherPommeVerte = true;
		}
		else {
			Point temp(mPommeRouge.aleatoire(6, 54), mPommeRouge.aleatoire(6, 54));
			mPommeRouge.setPosition(temp);
			mAfficherPommeVerte = false;
		}
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

		// dessiner pomme rouge ou pomme verte
		if (mAfficherPommeVerte) {
			writer.image("imageJeu").drawPoint(mPommeVerte.position().x(), mPommeVerte.position().y(), mPommeVerte.dessin(), mPommeVerte.couleur());
		}
		else {
			writer.image("imageJeu").drawPoint(mPommeRouge.position().x(), mPommeRouge.position().y(), mPommeRouge.dessin(), mPommeRouge.couleur());
		}

		// dessiner serpent
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
