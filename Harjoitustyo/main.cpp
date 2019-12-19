#include"Kulkuvaline.h"
#include"Rekisterikirja.h"
#include"Vene.h"
#include"Auto.h"

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<limits>
#include<string>
#include<algorithm>

using namespace std;

void printMenu() {
	cout << "1)	Lisaa kulkuvaline" << endl;
	cout << "2)	Tulosta kulkuvalineiden nimet" << endl;
	cout << "3)	Hae kulkuvaline " << endl;
	cout << "4)	Lisaa kulkuvalineelle rekisteri" << endl;
	cout << "5)	Tulosta kulkuvalineen rekisteri" << endl;
	cout << "6) Poista kulkuvaline" << endl;
	cout << "7)	Poista rekisteri" << endl;
	cout << "8) Paivita kulkuvaline" << endl;
	cout << "9) Paivita rekisteri" << endl;
	cout << "10) Jarjesta kulkuvalineet ian mukaan" << endl;
	cout << "0)	Lopeta" << endl;
}

int getChoice() {
	int ret = 0;
	cout << "Valintasi: ";
	cin >> ret;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR  Valitse numero(0-15): ";
		cin >> ret;
	}
	return ret;
}

string getString() {
	string ret = "";
	cin.ignore();
	getline(cin, ret);
	return ret;
}

int main() {
	vector<unique_ptr<Kulkuvaline>> kulkuvalineet;

	int choice = 1;
	int choice2 = 0;
	string input1 = "";
	int input2 = 0;
	string input3 = "";

	while (choice != 0) {
		printMenu();
		choice = getChoice();

		switch (choice) {
		case 1: {
			cout << "Haluatko lisata veneen(1) vai auton?(2)";
			choice2 = getChoice();
			if (choice2 == 1)
			{
				cout << "Veneen nimi:";
				input1 = getString();
				cout << "Veneen ika:";
				cin >> input2;
				cout << "Veneen malli:";
				input3 = getString();
				unique_ptr<Kulkuvaline> p = make_unique<Vene>(input1, input2, input3);
				kulkuvalineet.push_back(p);
				MyClass* myObj = new MyClass();
				p->addHenkiloListener(myObj);
			}
			else if (choice2 == 2)
			{
				cout << "Auton nimi: ";
				input1 = getString();
				cout << "Auton ika: ";
				cin >> input2;
				cout << "Auton malli: ";
				input3 = getString();
				unique_ptr<Kulkuvaline> p = make_unique<Auto>(input1, input2, input3);
				kulkuvalineet.push_back(p);
				MyClass* myObj = new MyClass();
				p->addHenkiloListener(myObj);
			}
			break;
		}
		case 2:
			for (unique_ptr<Kulkuvaline>& h : kulkuvalineet) {
				h->tulostaTiedot();
			}
			break;
		case 3: 
			{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			auto printFound = [&](const auto& p) { if (p->getNimi() == input1) p->tulostaTiedot(); };
			for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
			break;
			}
		case 4: 
			{
				cout << "Ajoneuvon nimi. ";
				input1 = getString();
				auto printFound = [&](const auto& p) { 
					if (p->getNimi() == input1) {
						cout << "Rekisteri: ";
						input1 = getString();
						p->setNewRegister(input1);
					}
				};
				for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
			}
			break;
		case 5:
		{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			auto printFound = [&](const auto& p) {
				if (p->getNimi() == input1) {
					cout << p->getRekisteri() << endl;
				}
			};
			for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
		}
			break;
		case 6:
		{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			vector<unique_ptr<Kulkuvaline>>::iterator object =
				find_if(kulkuvalineet.begin(), kulkuvalineet.end(),
					[&](unique_ptr<Kulkuvaline>& obj) { return obj->getNimi() == input1; }
			);
			kulkuvalineet.erase(std::remove(kulkuvalineet.begin(), kulkuvalineet.end(), *object));
		}
			break;
		case 7:
		{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			auto printFound = [&](const auto& p) {
				if (p->getNimi() == input1) {
					p->removeRegister();
				}
			};
			for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
		}
			break;
		case 8:
		{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			auto printFound = [&](const auto& p) {
				if (p->getNimi() == input1) {
					cout << "Ajoneuvon nimi:";
					input1 = getString();
					p->setNimi(input1);
					cout << "Ajoneuvon ika:";
					cin >> input2;
					p->setIka(input2);
				}
			};
			for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
		}
			break;
		case 9:
		{
			cout << "Ajoneuvon nimi. ";
			input1 = getString();
			auto printFound = [&](const auto& p) {
				if (p->getNimi() == input1) {
					cout << "Uusi rekisteri:";
					input1 = getString();
					p->setNewRegister(input1);
				}
			};
			for_each(kulkuvalineet.begin(), kulkuvalineet.end(), printFound);
		}
			break;
		case 10:
		{
			auto myComparator = [](const Kulkuvaline& a, const Kulkuvaline& b) { return a.getIka() < b.getIka(); };
			sort(kulkuvalineet.begin(), kulkuvalineet.end(), myComparator);
			break;
		}
		}
		if (choice != 0) {
			system("pause");
			system("cls");
		}
		}
		return EXIT_SUCCESS;
	}

