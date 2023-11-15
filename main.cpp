#include "Sovellus.h"
#include <iostream>

using std::endl; using std::cerr;

int main()
{
	try
	{
		Sovellus amk("TAMK");
		amk.aja();
	}
	catch (std::out_of_range& ex)
	{
		cerr << "Virheellinen indeksointi! " << endl;
	}
	catch (std::exception& ex)
	{
		cerr << "Virhe: " << ex.what() << endl;
	}
	catch (...)
	{
		cerr << "Virhe!..." << endl;
	}
	
	


	system("pause");
	return 0;
}
/*
#include "Opettaja.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <direct.h>
using std::cout; using std::endl; using std::ofstream; using std::ifstream; 
using std::cin; using std::vector;

int main()
{
	Opettaja hessu("Hessu", " Hopo", "katu 2", "0501234567", 3500, "hessuh", "kodaus");
	Opettaja jaana("Jaana", "Jämäkkä", "Katu 3", "0407654321", 4000, "jaanaj", "tietokannat");
	hessu.tulosta();
	jaana.tulosta();
	vector<Opettaja> opet;
	opet.push_back(hessu);
	opet.push_back(jaana);
	
	ofstream kirj_tied;
	kirj_tied.open("opettajat.csv");
	if (kirj_tied.is_open())
	{
		for (unsigned int i = 0; i < opet.size(); i++)
		{
			kirj_tied << opet[i].annaEtunimi() << ";"
				<< opet[i].annaSukunimi() << ";"
				<< opet[i].annaOsoite() << ";"
				<< opet[i].annaPuhelinnumero() << ";"
				<< opet[i].annaPalkka() << ";"
				<< opet[i].annaTunnus() << ";"
				<< opet[i].annaOpetusala() << endl;
		}
		kirj_tied.close();
	}
	else
		cout << "Tiedostoa ei saa avattua!" << endl;
	
	ifstream luku_tied;
	luku_tied.open("opettajat.csv");
	if (luku_tied.is_open())
	{
		string etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
		while (luku_tied.peek() != EOF)
		{
			getline(luku_tied, etunimi, ';');
			getline(luku_tied, sukunimi, ';');
			getline(luku_tied, osoite, ';');
			getline(luku_tied, puhelinnumero, ';');
			getline(luku_tied, palkka, ';');
			getline(luku_tied, tunnus, ';');
			getline(luku_tied, opetusala, '\n'); // lopettaa rivinvaihtoon
			double opalkka = atof(palkka.c_str()); // muunnetaan string doubleksi
			Opettaja o(etunimi, sukunimi, osoite, puhelinnumero, opalkka, tunnus, opetusala);
			o.tulosta();
			// harjoitustyö pushback opettaja vectoriin
		}
		luku_tied.close();
		
	}

	system("pause");
	return 0;
}*/
