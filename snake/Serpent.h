#ifndef SERPENT_H
#define SERPENT_H

#include <string>;
#include <list>
#include "Point.h"
#include "ConsoleColor.h"

class Serpent
{
private:
	int mLongueur;
	double mVitesse;
	ConsoleColor mCouleur;
	Point mTete;
	std::list<Point> mCorps;
	char mForme;
	bool mMange;
	char mDirection;

public:
	Serpent();
	~Serpent();

	//Getter
	Point tete();
	int longueur();
	double vitesse();
	ConsoleColor couleur();
	char forme();
	std::list<Point> corps();
	bool mange();
	char direction();

	//Setter
	void setPosition(Point position);
	void setlongueur(int longueur);
	void setvitesse(double vitesse);
	void setcouleur(ConsoleColor couleur);
	void setforme(char forme);
	void setMange(bool mange);
	void setDirection(char direction);

	//Fonction
	void ajouterPoint(Point a);
	//Bouge
	void bougeAGauche();
	void bougeADroite();
	void bougeEnHaut();
	void bougeEnBas();
};

#endif //SERPENT_H

