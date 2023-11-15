#pragma once
#include "Koulutusohjelma.h"

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();
	void asetaNimi(string nimi);
	string annaNimi() const;
	void lisaaKoulutusohjelma();	// valinta 1
	void tulostaKoulutusohjelmat() const;	// valinta 2
	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat() const;
	void poistaKoulutusohjelma();
	void poistaOpettaja();
	void poistaOpiskelija();
	void paivitaKoulutusohjelma();
	void paivitaOpettaja();
	void paivitaOpiskelija();
	void lueTiedotOpe();
	void kirjoitaTiedotOpe();
	void lueTiedotOpisk();
	void kirjoitaTiedotOpisk();
private:
	int etsiKoulutusohjelma() const;
	bool onkoKoulutusohjelmaOlemassa(string nimi) const;
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
};

