
#include "Console"
#include "ActionJeu.h"


using namespace std;

int main()
{

	ConsoleContext context(60, 70, "Snake", 10, 10, L"Consolas");
	Console::defineContext(context);

	
	ActionJeu jeu;
	jeu.lancer();


	return 0;
}




