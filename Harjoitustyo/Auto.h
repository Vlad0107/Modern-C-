#include"Kulkuvaline.h"
#include<iostream>
using namespace std;

class Auto : public Kulkuvaline {
public:
	Auto(const string& aNimi, int aIka, string& aMalli)
		: Kulkuvaline(aNimi, aIka), malli(aMalli) 
	{}
	~Auto() {
		cout << "Auton purkaja. Vapautetaan auton omistamat resussit " << endl;
	}
	void tulostaTiedot() const {
		cout << "Auton tulosta tiedot -metodi" << endl;
		Kulkuvaline::tulostaTiedot();
		cout << "Malli " << malli << endl;
	}
	string getModel() const
	{
		return malli;
	}
	void setModel(int aMalli) {
		malli = aMalli;
	}

private:
	string malli = "";
};