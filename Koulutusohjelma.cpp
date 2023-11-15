#include "Koulutusohjelma.h"
#include <iostream>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::getline; using std::ifstream; using std::ofstream;


Koulutusohjelma::Koulutusohjelma():nimi_(), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::Koulutusohjelma(string nimi):nimi_(nimi), opiskelijat_(), opettajat_()
{
}


Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja ope;
	ope.kysyTiedot();
	opettajat_.push_back(ope);
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija opisk;
	opisk.kysyTiedot();
	opiskelijat_.push_back(opisk);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		opettajat_[i].tulosta();
	}
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		opiskelijat_[i].tulosta();
	}
}

void Koulutusohjelma::poistaOpettaja()
{
	int indeksi = etsiOpettaja();
	if (indeksi >= 0)
	{
		opettajat_.erase(opettajat_.begin() + indeksi);
	}
	else
		cout << "opettajaa ei loytynyt! " << endl;
}

void Koulutusohjelma::poistaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	if (indeksi >= 0)
	{
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
	}
	else
		cout << "opiskelijaa ei loytynyt! " << endl;
}

void Koulutusohjelma::paivitaOpettaja()
{
	int indeksi = etsiOpettaja();
	if (indeksi >= 0)
	{
		string valinta;
		string etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
		do
		{
			cout << endl;
			cout << "Mita tietoa opettajasta muutetaan? " << endl;
			cout << " 1) Etunimi" << endl;
			cout << " 2) Sukunimi" << endl;
			cout << " 3) Osoite" << endl;
			cout << " 4) Puhelinnumero" << endl;
			cout << " 5) Palkka" << endl;
			cout << " 6) Tunnus" << endl;
			cout << " 7) Opetusala" << endl;
			cout << " 0) Palaa takaisin" << endl << endl;
			cout << "Anna valintasi: ";
			getline(cin, valinta);
			if (valinta == "1")
			{
				cout << "Anna uusi etunimi: ";
				getline(cin, etunimi);
				opettajat_[indeksi].asetaEtunimi(etunimi);
			}
			else if (valinta == "2")
			{
				cout << "Anna uusi sukunimi: ";
				getline(cin, sukunimi);
				opettajat_[indeksi].asetaSukunimi(sukunimi);
			}
			else if (valinta == "3")
			{
				cout << "Anna uusi osoite: ";
				getline(cin, osoite);
				opettajat_[indeksi].asetaOsoite(osoite);
			}
			else if (valinta == "4")
			{
				cout << "Anna uusi puhelinnumero: ";
				getline(cin, puhelinnumero);
				opettajat_[indeksi].asetaPuhelinnumero(puhelinnumero);

			}
			else if (valinta == "5")
			{
				cout << "Anna uusi palkka: ";
				getline(cin, palkka);
				double opalkka = atof(palkka.c_str());
				opettajat_[indeksi].asetaPalkka(opalkka);
			}
			else if (valinta == "6")
			{
				cout << "Anna uusi tunnus: ";
				getline(cin, tunnus);
				opettajat_[indeksi].asetaTunnus(tunnus);
			}
			else if (valinta == "7")
			{
				cout << "Anna uusi opetusala: ";
				getline(cin, opetusala);
				opettajat_[indeksi].asetaOpetusala(opetusala);
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
	else
		cout << "opettajaa ei loytynyt! " << endl;
}

void Koulutusohjelma::paivitaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	if (indeksi >= 0)
	{
		string valinta;
		string etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;
		do
		{
			cout << endl;
			cout << "Mita tietoa opiskelijasta muutetaan? " << endl;
			cout << " 1) Etunimi" << endl;
			cout << " 2) Sukunimi" << endl;
			cout << " 3) Osoite" << endl;
			cout << " 4) Puhelinnumero" << endl;
			cout << " 5) Opiskelijanumero" << endl;
			cout << " 0) Palaa takaisin" << endl << endl;
			cout << "Anna valintasi: ";
			getline(cin, valinta);
			if (valinta == "1")
			{
				cout << "Anna uusi etunimi: ";
				getline(cin, etunimi);
				opiskelijat_[indeksi].asetaEtunimi(etunimi);
			}
			else if (valinta == "2")
			{
				cout << "Anna uusi sukunimi: ";
				getline(cin, sukunimi);
				opiskelijat_[indeksi].asetaSukunimi(sukunimi);
			}
			else if (valinta == "3")
			{
				cout << "Anna uusi osoite: ";
				getline(cin, osoite);
				opiskelijat_[indeksi].asetaOsoite(osoite);
			}
			else if (valinta == "4")
			{
				cout << "Anna uusi puhelinnumero: ";
				getline(cin, puhelinnumero);
				opiskelijat_[indeksi].asetaPuhelinnumero(puhelinnumero);

			}
			else if (valinta == "5")
			{
				cout << "Anna uusi opiskelijanumero: ";
				getline(cin, opiskelijanumero);
				opiskelijat_[indeksi].asetaOpiskelijanumero(opiskelijanumero);
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
	else
		cout << "opiskelijaa ei loytynyt! " << endl;
}

void Koulutusohjelma::lueTiedotOpe(Opettaja ope)
{
	opettajat_.push_back(ope); // lisää luetun opettajan tiedostosta
}

void Koulutusohjelma::kirjoitaTiedotOpe(string nimi)
{
	ofstream kirj_tied;
	kirj_tied.open("opettajat.csv", ofstream::app);
	if (kirj_tied.is_open())
	{
		for (unsigned int i = 0; i < opettajat_.size(); i++)
		{
			kirj_tied << nimi << ";"
				<< opettajat_[i].annaEtunimi() << ";"
				<< opettajat_[i].annaSukunimi() << ";"
				<< opettajat_[i].annaOsoite() << ";"
				<< opettajat_[i].annaPuhelinnumero() << ";"
				<< opettajat_[i].annaPalkka() << ";"
				<< opettajat_[i].annaTunnus() << ";"
				<< opettajat_[i].annaOpetusala() << endl;
		}
	}
	else
		cout << "Tiedostoa ei saa avattua!" << endl;
}

void Koulutusohjelma::lueTiedotOpisk(Opiskelija opisk)
{
	opiskelijat_.push_back(opisk);
}

void Koulutusohjelma::kirjoitaTiedotOpisk(string nimi)
{
	ofstream kirj_tied;
	kirj_tied.open("opiskelijat.csv", ofstream::app);
	if (kirj_tied.is_open())
	{
		for (unsigned int i = 0; i < opiskelijat_.size(); i++)
		{
			kirj_tied << nimi << ";"
				<< opiskelijat_[i].annaEtunimi() << ";"
				<< opiskelijat_[i].annaSukunimi() << ";"
				<< opiskelijat_[i].annaOsoite() << ";"
				<< opiskelijat_[i].annaPuhelinnumero() << ";"
				<< opiskelijat_[i].annaOpiskelijanumero() << endl;
		}
	}
	else
		cout << "Tiedostoa ei saa avattua!" << endl;
}

int Koulutusohjelma::etsiOpettaja() const
{
	string tunnus;
	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus);
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		if (tunnus == opettajat_[i].annaTunnus())
		{
			return i;
		}
	}
	return -1;	// ei löytynyt
}

int Koulutusohjelma::etsiOpiskelija() const
{
	string opiskelijanumero;
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero);
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero())
		{
			return i;
		}
	}
	return -1;	// ei löytynyt
}
