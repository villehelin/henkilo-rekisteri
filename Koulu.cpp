#include "Koulu.h"
#include <iostream>
#include <vector>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::getline; using std::ifstream; 
using std::ofstream; 

Koulu::Koulu():nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi):nimi_(nimi), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna Koulutusohjelman nimi: ";
	getline(cin, nimi);
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
}

void Koulu::tulostaKoulutusohjelmat() const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		cout << koulutusohjelmat_[i].annaNimi() << endl;
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpiskelija();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::poistaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + indeksi);
	}
	else 
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::poistaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}
	else
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}
	else
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::paivitaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();
	string nimi;
	if (indeksi >= 0)
	{
		cout << "Anna koulutusohjelman uusi nimi: ";
		getline(cin, nimi);
		koulutusohjelmat_[indeksi].asetaNimi(nimi);
	}
	else
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::paivitaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOpettaja();
	}
	else
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::paivitaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOpiskelija();
	}
	else
		cout << "koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::lueTiedotOpe()
{
	ifstream luku_tied;
	luku_tied.open("opettajat.csv");
	if (luku_tied.is_open())
	{

		while (luku_tied.peek() != EOF)
		{
			string nimi;
			getline(luku_tied, nimi, ';');
			string etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
			getline(luku_tied, etunimi, ';');
			getline(luku_tied, sukunimi, ';');
			getline(luku_tied, osoite, ';');
			getline(luku_tied, puhelinnumero, ';');
			getline(luku_tied, palkka, ';');
			getline(luku_tied, tunnus, ';');
			getline(luku_tied, opetusala, '\n'); // lopettaa rivinvaihtoon
			double opalkka = atof(palkka.c_str()); // muunnetaan string doubleksi
			Opettaja ope(etunimi, sukunimi, osoite, puhelinnumero, opalkka, tunnus, opetusala);
			// ope.tulosta();
			// opettajat_.push_back(ope);
			if (onkoKoulutusohjelmaOlemassa(nimi) == false) // tarkistaa onko koulutusohjelma olemassa jos ei niin se tehdään muuten sijoitetaan jo olemassa olevaan koulutusohjelmaan
			{
				koulutusohjelmat_.push_back(nimi);
				koulutusohjelmat_.back().lueTiedotOpe(ope);
			}
			else if (onkoKoulutusohjelmaOlemassa(nimi) == true)
			{
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
				{
					if (nimi == koulutusohjelmat_[i].annaNimi())
					{
						koulutusohjelmat_[i].lueTiedotOpe(ope);
					}
				}
			}
		}
		luku_tied.close();
		remove("opettajatOld.csv"); // poistaa opettajatOld tiedoston
		rename("opettajat.csv", "opettajatOld.csv"); // nimeää tallentaessa opettajat tiedoston opettajatOld:ksi
	}
}

void Koulu::kirjoitaTiedotOpe()
{
	ofstream kirj_tied;
	kirj_tied.open("opettajat.csv", ofstream::app);
	if (kirj_tied.is_open())
	{
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		{
			koulutusohjelmat_[i].kirjoitaTiedotOpe(koulutusohjelmat_[i].annaNimi());
		}
		kirj_tied.close();
	}
	else
		cout << "Tiedostoa ei saa avattua!" << endl;
}

void Koulu::lueTiedotOpisk()
{
	ifstream luku_tied;
	luku_tied.open("opiskelijat.csv");
	if (luku_tied.is_open())
	{

		while (luku_tied.peek() != EOF)
		{
			string nimi;
			getline(luku_tied, nimi, ';');
			string etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;
			getline(luku_tied, etunimi, ';');
			getline(luku_tied, sukunimi, ';');
			getline(luku_tied, osoite, ';');
			getline(luku_tied, puhelinnumero, ';');
			getline(luku_tied, opiskelijanumero, '\n'); // lopettaa rivinvaihtoon
			Opiskelija opisk(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
			if (onkoKoulutusohjelmaOlemassa(nimi) == false)
			{
				koulutusohjelmat_.push_back(nimi);
				koulutusohjelmat_.back().lueTiedotOpisk(opisk);
			}
			else if (onkoKoulutusohjelmaOlemassa(nimi) == true)
			{
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
				{
					if (nimi == koulutusohjelmat_[i].annaNimi())
					{
						koulutusohjelmat_[i].lueTiedotOpisk(opisk);
					}
				}
			}
		}
		luku_tied.close();
		remove("opiskelijatOld.csv");
		rename("opiskelijat.csv", "opiskelijatOld.csv");
	}
}

void Koulu::kirjoitaTiedotOpisk()
{
	ofstream kirj_tied;
	kirj_tied.open("opiskelijat.csv", ofstream::app);
	if (kirj_tied.is_open())
	{
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		{
			koulutusohjelmat_[i].kirjoitaTiedotOpisk(koulutusohjelmat_[i].annaNimi());
		}
		kirj_tied.close();
	}
	else
		cout << "Tiedostoa ei saa avattua!" << endl;
}

int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_[i].annaNimi())
		{
			return i;
		}
	}
	return -1;	// ei löytynyt
}

bool Koulu::onkoKoulutusohjelmaOlemassa(string nimi) const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_[i].annaNimi())
		{
			return true;
		}
	}
	return false;	// ei löytynyt
}
