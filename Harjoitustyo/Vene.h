#include"Kulkuvaline.h"
#include<iostream>
using namespace std;

class Vene : public Kulkuvaline {
public:
	Vene(const string& aNimi, int aIka, string& aMAlli)
		: Kulkuvaline(aNimi, aIka), malli(aMAlli) {
	}
	~Vene() {
		cout << "Veneen purkaja. Vapautetaan opiskelijan omistamat resussit " << endl;
	}
	void tulostaTiedot() const {
		cout << "Veneen tulosta tiedot -metodi" << endl;
		Kulkuvaline::tulostaTiedot();
		cout << "Malli " << malli << endl;
	}
	string getModel() const
	{
		return malli;
	}
	void setModel(int aMAlli) {
		malli = aMAlli;
	}

private:
	string malli;
};