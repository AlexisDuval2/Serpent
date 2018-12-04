
#include "Serpent.h"

Serpent::Serpent()
	:mLongueur{ 1 },
	mVitesse{ 1.0 },
	mTete(15, 30),
	mCorps{ mTete },
	mCouleur{ ConsoleColor::bb + ConsoleColor::tg },
	mForme{ char(219) },
	mMange{ false },
	mDirection { 'X' }
{
}

Serpent::~Serpent()
{
}

void Serpent::bougeAGauche() {

	Point tempo{ mTete };
	tempo.setX(tempo.x() - 1);
	mCorps.push_front(tempo);
	mCorps.pop_back();

	mTete = tempo;
}

void Serpent::bougeADroite() {

	Point tempo{ mTete };
	tempo.setX(tempo.x() + 1);
	mCorps.push_front(tempo);
	mCorps.pop_back();

	mTete = tempo;
}

void Serpent::bougeEnHaut() {

	Point tempo{ mTete };
	tempo.setY(tempo.y() - 1);
	mCorps.push_front(tempo);
	mCorps.pop_back();

	mTete = tempo;
}

void Serpent::bougeEnBas() {
	
	Point tempo{ mTete };
	tempo.setY(tempo.y() + 1);
	mCorps.push_front(tempo);
	mCorps.pop_back();

	mTete = tempo;
}

// -------GETTER / Setter ------------//

Point Serpent::tete() {
	return mTete;
}
int Serpent::longueur() {
	return mLongueur;
}
double Serpent::vitesse() {
	return mVitesse;
}
ConsoleColor Serpent::couleur() {
	return mCouleur;
}
char Serpent::forme() {
	return mForme;
}
std::list<Point> Serpent::corps() {
	return mCorps;
}

char Serpent::direction() {
	return mDirection;
}

bool Serpent::mange()
{
	return mMange;
}

void Serpent::ajouterPoint(Point a)
{
	mCorps.push_back(a);

}


void Serpent::setPosition(Point position) {
	mTete = position;
}


void Serpent::setlongueur(int longueur) {
	mLongueur = longueur;
}
void Serpent::setvitesse(double vitesse) {
	mVitesse = vitesse;
}
void Serpent::setcouleur(ConsoleColor couleur) {
	mCouleur = couleur;
}
void Serpent::setforme(char forme) {
	mForme = forme;
}

void Serpent::setMange(bool mange)
{
	mMange = mange;
}

void Serpent::setDirection(char direction) {
	mDirection = direction;
}


