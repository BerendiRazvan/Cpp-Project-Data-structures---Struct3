#include "TestExtins.h"
#include "TestScurt.h"
#include <iostream>
#include "Multime.h"

using namespace std;
int main() {

	testAll();
	testAllExtins();
	cout << "That's all!" << endl;

	return 0;
}


/*
---------------------------------------------------------------------------------------------------------------------------------

Să se implementeze în C++ un anumit container de date (TAD) folosind o anumită
reprezentare (indicată) și o tabelă de dispersie (TD) ca structură de date, cu o anumită metodă
(indicată) pentru rezolvarea coliziunilor:
− Liste independente
− Liste întrepătrunse
− Adresare deschisă

Interfețele pentru TAD-uri și testele sunt disponibile în secțiunea Files/Class
materials/Laborator/Teme laborator/ Interfete TAD (proiecte C++) si teste.

---------------------------------------------------------------------------------------------------------------------------------

P10. TAD Mulțime – reprezentare folosind o TD cu rezolvare coliziuni prin liste întrepătrunse.

---------------------------------------------------------------------------------------------------------------------------------
*/
