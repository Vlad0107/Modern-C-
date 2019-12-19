#pragma once
#include<string>
#include<memory>
#include<vector>
#include<functional>
#include"Rekisterikirja.h"

using namespace std;

class KulkuvalineListener {
public:
	virtual void ageChanged(int aNewAge) = 0;
	static int count;
};

class Kulkuvaline
{
public:
	Kulkuvaline(); // Oletusrakentaja ei luo rekisteritta, vaan rekisteri on nullptr
	Kulkuvaline(const string& aNimi, int aIka);
	Kulkuvaline(const string& aNimi, int aIka, const Rekisterikirja& arekisteri); // luodaan rekisteri new:lla 
	Kulkuvaline(const Kulkuvaline& aHlo); // kopiorakentaja
	virtual ~Kulkuvaline();

	string getNimi() const;
	void setNimi(const string& aNimi);
	int getIka() const;
	void setIka(int aIka);
	string getRekisteri() const;
	void setRekisteri(const string aRekisteri);
	void setNewRegister(const string& rekisteri);
	void removeRegister();
	virtual void tulostaTiedot() const;

	void addHenkiloListener(KulkuvalineListener* aNewListener) {
		listener = aNewListener;
	}
	function<void(int)> ageChanged;

private:
	int ika = 0;
	string nimi = "";
	unique_ptr<Rekisterikirja> rekisteri; 
	KulkuvalineListener* listener = nullptr;
};

class MyClass : public KulkuvalineListener { // MyClass IS-A HenkiloListener
public:
	MyClass() {};
	~MyClass() {};

	void ageChangedFunctional(int aNewAge) {
		cout << "Functional: Henkilon ika muuttunut. Uusi ika: " << aNewAge << endl;
	}

	// Kuuntelijarajapinnan (observer interface) toteutus
	virtual void ageChanged(int aNewAge) {
		cout << "Henkilon ika muuttunut. Uusi ika: " << aNewAge << endl;
	}

};