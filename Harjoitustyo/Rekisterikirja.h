#pragma once
#include<string>
#include<iostream>

using namespace std;
class Rekisterikirja
{
public:
	Rekisterikirja() : Rekisterikirja ("") {
	}
	Rekisterikirja(const string& aKatu) : rekisteri(aKatu) {
		cout << "Rekisterikirja -luokan rakentaja" << endl;
	};
	~Rekisterikirja() {
		cout << "Rekisterikirja -luokan purkaja" << endl;
	}
	string getRekisteri() const { return rekisteri; }

	void setRekisteri(const string& arekisteri) { rekisteri = arekisteri; }

private:
	string rekisteri;
};