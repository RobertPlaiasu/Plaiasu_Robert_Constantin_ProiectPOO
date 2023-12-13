#pragma once
#include "CenturaBjj.h"
#include "GiBjj.h"
#include "AfisareConsola.h"

class EchipamentBjj : public AfisareConsola
{
private:
	const int id;
	CenturaBjj centura;
	GiBjj gi;
	std::string proprietar;

public:
	EchipamentBjj();

	EchipamentBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar);

	EchipamentBjj(const EchipamentBjj& echipament);

	~EchipamentBjj();

	void setCentura(const CenturaBjj& centura);

	CenturaBjj& getCentura();

	void setGi(const GiBjj& gi);

	GiBjj& getGi();

	void setProprietar(const std::string proprietar);

	std::string getProprietar();

	void afisare();


	EchipamentBjj& operator=(const EchipamentBjj& echipament);

	explicit operator GiBjj& ();

	friend std::ostream& operator<<(std::ostream& out, EchipamentBjj& echipament);
	friend std::ofstream& operator<<(std::ofstream& out, EchipamentBjj& echipament);
	friend std::ifstream& operator>>(std::ifstream& in, EchipamentBjj& echipament);
};

