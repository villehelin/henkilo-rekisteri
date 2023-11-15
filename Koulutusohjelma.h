#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"
#include <string>
#include <vector>
using std::string; using std::vector;

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	~Koulutusohjelma();
	void asetaNimi(string nimi);
	string annaNimi() const;
	void lisaaOpettaja();
	void lisaaOpiskelija();
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	void poistaOpettaja();
	void poistaOpiskelija();
	void paivitaOpettaja();
	void paivitaOpiskelija();
	void lueTiedotOpe(Opettaja ope);
	void kirjoitaTiedotOpe(string nimi);
	void lueTiedotOpisk(Opiskelija opisk);
	void kirjoitaTiedotOpisk(string nimi);
private:
	int etsiOpettaja() const;
	int etsiOpiskelija() const;
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

