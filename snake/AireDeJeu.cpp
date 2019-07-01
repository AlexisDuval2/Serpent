#include "AireDeJeu.h"
#include"ConsoleWriter.h"
#include"Console.h"
#include<string>

using namespace std;

AireDeJeu::AireDeJeu()
	:	mLargeur{60},
		mHauteur{ 60 },
		mLargeurJouable{ 50 },
		mHauteurJouable{ 50 },
		x{ (mLargeur - mLargeurJouable) / 2 },
		y{(mHauteur - mHauteurJouable) / 2}
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

void AireDeJeu::afficherAirJeu(Serpent &s, Pomme &pRouge, Pomme &pVerte, bool estPommeVerte, int compteur)
{
	ConsoleWriter & writer{ Console::getInstance().writer() };

	writer.createImage("background");

	size_t height{ 5 };
	size_t py{ 57 };
	size_t width{ 16 };
	size_t px{ 22 };

	string textePause{ "Pause (p)" };
	string texteQuitter{ "Quitter (q)" };


	writer.image("background").fill(x, y, mLargeurJouable, mHauteurJouable, char(219), ConsoleColor::by + ConsoleColor::ty);
	writer.image("background").fill(px, py, width, height, char(219), ConsoleColor::bw + ConsoleColor::tw); // Carré Point
	writer.image("background").drawText(px + 1, py + 2, "Point: " + to_string(compteur), ConsoleColor::bw + ConsoleColor::tk, true);

	writer.image("background").drawText(x, py + 2, textePause, ConsoleColor::bk + ConsoleColor::tW, true);
	writer.image("background").drawText(x+ mLargeurJouable- texteQuitter.size(), py + 2, texteQuitter, ConsoleColor::bk + ConsoleColor::tW, true);
	writer.createImage("imageJeu");
	writer.push("background", "imageJeu");

	//writer.image("imageJeu").drawPoint(p.position().x(), p.position().y(), p.dessin(), p.couleur());

	 // dessiner pomme rouge ou pomme verte
	 if (estPommeVerte) {
	 writer.image("imageJeu").drawPoint(pVerte.position().x(), pVerte.position().y(), pVerte.dessin(), pVerte.couleur());
	 }
	 else {
	 writer.image("imageJeu").drawPoint(pRouge.position().x(), pRouge.position().y(), pRouge.dessin(), pRouge.couleur());
	 }

	for (Point & p : s.corps())
	{
		writer.image("imageJeu").drawPoint(p.x(), p.y(), s.forme(), s.couleur());
		writer.push("imageJeu");
	}

}

void AireDeJeu::afficherGameOver()
{
	ConsoleWriter & writer{ Console::getInstance().writer() };
	size_t px{ 21 };
	size_t py{ 28 };
	size_t width{ 18 };
	size_t heigth{ 5 };

	string texte1{ "Retour Menu (b)" };
	string texte2{ "Quitter (q))" };
	string texte3{ "Rejouer (espace)" };

	writer.createImage("finDePartie");
	writer.image("finDePartie").fill(px, py, width, heigth, char(219), ConsoleColor::bb + ConsoleColor::tb);
	writer.image("finDePartie").fill(px, py+7, width, heigth, char(219), ConsoleColor::bb + ConsoleColor::tb);
	writer.image("finDePartie").drawText(px + 4, py + 2, "GAME OVER!", ConsoleColor::bb + ConsoleColor::tW, true);
	writer.image("finDePartie").drawText(px + 2, py + 8, texte1, ConsoleColor::bb + ConsoleColor::tW, true);
	writer.image("finDePartie").drawText(px + 4, py + 9, texte2, ConsoleColor::bb + ConsoleColor::tW, true);
	writer.image("finDePartie").drawText(px + 1, py + 10, texte3, ConsoleColor::bb + ConsoleColor::tW, true);
	writer.push("finDePartie");
}

void AireDeJeu::afficherMenuEntre()
{
	ConsoleWriter & writer{ Console::getInstance().writer() };

	string text1{ "Bienvenue" };
	string text2{ "Jouer (espace)" };
	string text3{ "Instructions (i)" };
	string text4{ "Quitter (q)" };
	size_t xTexte = (mLargeur - text1.size()) / 2;
	size_t yTexte = mHauteurJouable / 2;
		
	writer.createImage("bienvenu");
	writer.image("bienvenu").fill(x, y, mLargeurJouable, mHauteurJouable, char(219), ConsoleColor::bb + ConsoleColor::tb);
	writer.image("bienvenu").drawText(xTexte, yTexte, text1, ConsoleColor::bb + ConsoleColor::tW);
	writer.image("bienvenu").drawText((mLargeur - text2.size()) / 2, yTexte+3 , text2, ConsoleColor::bb + ConsoleColor::tW);
	writer.image("bienvenu").drawText((mLargeur - text3.size()) / 2, yTexte+4, text3, ConsoleColor::bb + ConsoleColor::tW);
	writer.image("bienvenu").drawText((mLargeur - text4.size()) / 2, yTexte+5 , text4, ConsoleColor::bb + ConsoleColor::tW);
	writer.push("bienvenu");



}

void AireDeJeu::afficherInstruction()
{
	ConsoleWriter & writer{ Console::getInstance().writer() };

	string texte1{ "Instructions" };
	string texte2{ "1. Utiliser les fl""\x8A""ches pour d""\x82""placer Salazar" };
	string texte3{ "2. Manger les pommes pour r""\x82""colter des points" };
	string texte33{ "   et devenir plus grand" };
	string texte4{ "3. Attention! Vous ne pouvez pas toucher les" };
	string texte44{ "   limites du carr""\x82"" de sable!" };
	string texte5{ "4. Attention! Vous ne pouvez pas" };
	string texte55{ "   vous manger vous m""\x88""me" };
	string texte6{ "5. A tout moment appuyer sur \'q\'" };
	string texte66{ "   pour quitter la partie" };

	string texteRetour{ "Retour (b)" };
	string texteJouer{ "Jouer (espace)" };

	size_t yTexte{ mHauteurJouable / 2 };
	size_t xTexte{ 8 };

	writer.createImage("instruction");
	writer.createImage("background");
	writer.push("background", "instruction");
	writer.image("instruction").fill(x, y, mLargeurJouable, mHauteurJouable, char(219), ConsoleColor::bC + ConsoleColor::tC);
	writer.image("instruction").drawText((mLargeur - texte1.size()) / 2, yTexte, texte1, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte+2, texte2, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 3, texte3, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 4, texte33, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 5, texte4, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 6, texte44, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 7, texte5, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 8, texte55, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 9, texte6, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText(xTexte, yTexte + 10, texte66, ConsoleColor::bC + ConsoleColor::tK);

	writer.image("instruction").drawText((mLargeur - texteRetour.size()) / 2, yTexte + 13, texteRetour, ConsoleColor::bC + ConsoleColor::tK);
	writer.image("instruction").drawText((mLargeur - texteJouer.size()) / 2, yTexte + 14, texteJouer, ConsoleColor::bC + ConsoleColor::tK);

	writer.push("instruction");

}
