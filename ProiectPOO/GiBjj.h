#pragma once
#include <iostream>
#include <fstream>

class GiBjj
{
private:
	const int id;
	static std::string sport;
	static int nrGi;
	static int valoareTotala;

	int nrMaterialeTextile;
	char** materialeTextie;

	std::string culoare;
	std::string taraFabricatie;

	int pret;

	std::string firmaProducatoare;



public:
	GiBjj();

	GiBjj(GiBjj& gi);

	GiBjj(int id, int pret, std::string taraFabricatie, char** materialeTextie, int nrMaterialeTextile, std::string culoare, std::string firmaProducatoare);

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare);

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare);

	~GiBjj();

	static float pretMediuGi();

	void afisare();

	static std::string getSport();

	static void setSport(std::string sport);

	static int  getNrGi();

	static void setNrGi(int nr);

	static int  getValoareTotala();

	static void setValoareTotala(int valoareTotala);

	int  getNrMaterialeTextile();

	char** getMaterialeTextile();

	void setMaterialeTextile(int nrMaterialeTextile, char** materialeTextile);

	std::string getTaraFabricatie();

	void setTaraFabricatie(std::string taraFabricatie);

	std::string getCuloare();

	void setCuloare(std::string culoare);

	float getPret();

	void setPret(int pretNou);

	std::string getFirmaProductoare();

	void setFirmaProductoare(std::string firmaProducatoare);

	int getId();

	GiBjj& operator=(const GiBjj& gi);

	char* operator[](int index);

	bool operator>(const GiBjj& gi);

	bool operator<(const GiBjj& gi);

	GiBjj operator++();

	GiBjj operator++(int i);

	friend bool validareId(GiBjj& gi);

	friend std::istream& operator>>(std::istream& in, GiBjj& gi);

	friend std::ostream& operator<<(std::ostream& out, GiBjj& gi);
};

