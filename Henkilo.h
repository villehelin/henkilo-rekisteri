#pragma once
#include <string>
using std::string;

class Henkilo
{
public:
	Henkilo(); // oletus rak
	Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero);
	Henkilo(const Henkilo & alkup); // param rak
	~Henkilo(); // purkaja
	Henkilo& operator=(const Henkilo & sij); // sijoitus operaattori
	void asetaEtunimi(string etunimi);
	void asetaSukunimi(string sukunimi);
	void asetaOsoite(string osoite);
	void asetaPuhelinnumero(string puhelinnumero);
	string annaEtunimi() const;
	string annaSukunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;
	void kysyTiedot();
	void tulosta() const;
private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};

