#include "Sovellus.h"
#include "Koulu.h"
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::getline;


Sovellus::Sovellus():nimi_()
{
}

Sovellus::Sovellus(string nimi): nimi_(nimi)
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::asetaNimi(string nimi)
{
	nimi_=nimi;
}

string Sovellus::annaNimi() const
{
	return nimi_;
}

void Sovellus::aja() const
{
	Koulu amk(nimi_);
	string valinta;
	cout << "Tervetuloa " << nimi_ << " -rekisteriin!" << endl;
	do
	{
		valinta = tulostaValikko();
		if (valinta == "1")
		{
			amk.lisaaKoulutusohjelma();
		}
		else if (valinta == "2")
		{
			amk.tulostaKoulutusohjelmat();
		}
		else if (valinta == "3")
		{
			amk.tulostaKoulutusohjelmienMaara();
		}
		else if (valinta == "4")
		{
			amk.lisaaKoulutusohjelmaanOpettaja();
		}
		else if (valinta == "5")
		{
			amk.tulostaKoulutusohjelmanOpettajat();
		}
		else if (valinta == "6")
		{
			amk.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if (valinta == "7")
		{
			amk.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if (valinta == "8")
		{
			amk.poistaKoulutusohjelma();
		}
		else if (valinta == "9")
		{
			amk.poistaOpettaja();
		}
		else if (valinta == "10")
		{
			amk.poistaOpiskelija();
		}
		else if (valinta == "11")
		{
			amk.paivitaKoulutusohjelma();
		}
		else if (valinta == "12")
		{
			amk.paivitaOpettaja();
		}
		else if (valinta == "13")
		{
			amk.paivitaOpiskelija();
		}
		else if (valinta == "14")
		{
			amk.lueTiedotOpe();
			amk.lueTiedotOpisk();
		}
		else if (valinta == "15")
		{
			amk.kirjoitaTiedotOpe();
			amk.kirjoitaTiedotOpisk();
		}
		else if (valinta == "0")
		{

		}
		else
		{
			cout << "Virheellinen valinta! " << endl;
		}
	} while (valinta != "0");
}

string Sovellus::tulostaValikko() const
{
	string valinta;
	cout << " 1) Lisaa koulutusohjelma" << endl;
	cout << " 2) Tulosta koulutusohjelmien nimet" << endl;
	cout << " 3) Tulosta koulutusohjelmien maara" << endl;
	cout << " 4) Lisaa koulutusohjelmaan opettaja" << endl;
	cout << " 5) Tulosta koulutusohjelman opettajat" << endl;
	cout << " 6) Lisaa koulutusohjelmaan opiskelija" << endl;
	cout << " 7) Tulosta koulutusohjelman opiskelijat" << endl;
	cout << " 8) Poista koulutusohjelma" << endl;
	cout << " 9) Poista opettaja" << endl;
	cout << "10) Poista opiskelija" << endl;
	cout << "11) Paivita koulutusohjelman nimi" << endl;
	cout << "12) Paivita opettajan tiedot" << endl;
	cout << "13) Paivita opiskelijan tiedot" << endl;
	cout << "14) Lue tiedot" << endl;
	cout << "15) Tallenna tiedot" << endl;
	cout << " 0) Lopeta" << endl << endl;
	cout << "Anna valintasi: ";
	getline(cin, valinta);
	return valinta;
}
