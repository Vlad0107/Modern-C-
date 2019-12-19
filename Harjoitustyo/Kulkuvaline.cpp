#include "Kulkuvaline.h"
#include<iostream>
using namespace std;

Kulkuvaline::Kulkuvaline() : ika(0), nimi("")
{
	cout << "Kulkuvalinen rakentaja" << endl;
}

Kulkuvaline::Kulkuvaline(const string& aNimi, int aIka): ika(aIka), nimi(aNimi)
{
	cout << "Kulkuvalineen parametrinen rakentaja" << endl;
}

/*Kulkuvaline::Kulkuvaline(const Kulkuvaline& aHlo) : ika(aHlo.ika), nimi(aHlo.nimi), rekisteri( new Rekisterikirja(*aHlo.rekisteri))
{
	cout << "Kulkuvalinen kopiorakentaja" << endl;
}*/

Kulkuvaline::~Kulkuvaline()
{
	// Vapautetaan olion varaama dynaaminen muisti ja muut resurssit
	cout << "Kulkuvalinen " << nimi << " purkaja" << endl;
}

string Kulkuvaline::getNimi() const
{
	return nimi;
}

void Kulkuvaline::setNimi(const string& aNimi)
{
	nimi = aNimi;
}

int Kulkuvaline::getIka() const
{
	return ika;
}

void Kulkuvaline::setIka(int aIka)
{
	if (ika >= 0) {
		if (aIka != ika) {
			ika = aIka;
			// Jos ikä muuttu, informoi kuuntelijoita (observers/listeners)
			if (listener) {
				listener->ageChanged(aIka);
			}
			/* Vektorillinen kuuntelijoita
					for( KulkuvalineListener* listener : listeners ){
						listener->ageChanged( aIka );
					}
			*/
			// Funktionaalinen eventin lähetys
			if (ageChanged) { // tarkastetaan onko function<void(int)> asetettu
				ageChanged(aIka);
			}
		}
	}

}

string Kulkuvaline::getRekisteri() const
{
	return rekisteri->getRekisteri();
}

void Kulkuvaline::setRekisteri(const string aRekisteri)
{
	if (rekisteri) { // Ohjekirja on luotu ja olemassa => päivitetään Ohjekirja
		rekisteri->setRekisteri(aRekisteri); // kopioidaan uudet arvot vanhaan osoitteeseen
	}
}

void Kulkuvaline::setNewRegister(const string& aRekisteri)
{
	rekisteri = make_unique<Rekisterikirja>();
	rekisteri->setRekisteri(aRekisteri);
}

void Kulkuvaline::removeRegister() {
	rekisteri.reset();
}

void Kulkuvaline::tulostaTiedot() const
{
	cout << "Kulkuvaline osoitteessa" << this << endl;
	cout << "Nimi: " << nimi << endl;
	cout << "Ika: " << ika << endl;
	// tulostetaan myös rekisteri, jos sellainen kulkuneuvolla on
	if (rekisteri) {
		cout << "Rekisteri: " << rekisteri->getRekisteri() << endl;
	}
}
