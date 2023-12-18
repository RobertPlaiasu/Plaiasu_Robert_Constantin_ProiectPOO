#pragma once
#include <iostream>
#include <fstream>
#include "Data.h"
#include "AfisareConsola.h"
#include "HasPret.h" 

class CenturaBjj : public AfisareConsola,public HasPret
{
private:
	const int id;
	static std::string sport;
	static int valoareTotala;
	static int nrCenturi;

	// la o centura pe care o ai poti avea dungi albe pe partea neagra ce simbolizeaza cat de avansat esti
	// retin momentul in timp cand am primit o dunga
	Data* dungi;
	int nrDungi;

	std::string culoare;
	std::string taraFabricatie;

	int pret;

	std::string firmaProducatoare;
public:
	CenturaBjj();

	CenturaBjj(const CenturaBjj& centura);

	CenturaBjj(int id, int pret, std::string taraFabricatie, Data* dungi, int nrDungi, std::string culoare, std::string firmaProducatoare);

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare);

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare);

	~CenturaBjj();

	static float pretMediuCentura();

	void afisare();

	static std::string getSport();

	static void setSport(std::string sport);

	static int  getNrCenturi();

	static void setNrCenturi(int nr);

	static int  getValoareTotala();

	static void setValoareTotala(int valoareTotala);

	int  getNrDungi();

	Data* getDungi();

	void setDungi(int nrDungi, Data* dungi);

	std::string getTaraFabricatie();

	void setTaraFabricatie(std::string taraFabricatie);

	std::string getCuloare();

	void setCuloare(std::string culoare);

	float getPret();

	void setPret(int pretNou);

	std::string getFirmaProductoare();

	void setFirmaProductoare(std::string firmaProducatoare);

	int getId();

	CenturaBjj& operator=(const CenturaBjj& centura);

	bool operator==(const CenturaBjj& centura);

	operator std::string();

	operator float();
	operator int();

	friend std::istream& operator>>(std::istream& in, CenturaBjj& centura);

	friend std::ostream& operator<<(std::ostream& out, CenturaBjj& centura);

	friend std::ifstream& operator>>(std::ifstream& in, CenturaBjj& centura);
	friend std::ofstream& operator<<(std::ofstream& out, CenturaBjj& centura);
	friend void citireFisierBinar(std::ifstream& in,CenturaBjj& centura);
	friend void afisareFisierBinar(std::ofstream& out,CenturaBjj& centura);
};

