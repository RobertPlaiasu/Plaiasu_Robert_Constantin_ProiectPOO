#pragma once
#include "CenturaBjj.h"
#include "GiBjj.h"
#include "AfisareConsola.h"
class EchipamentBjj : public AfisareConsola
{
private:
	const int id;
	HasPret* centura;
	HasPret* gi;
	std::string proprietar;

public:
	EchipamentBjj();

	EchipamentBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar);

	EchipamentBjj(const EchipamentBjj& echipament);

	~EchipamentBjj();

	void setCentura(const CenturaBjj& centura);

	HasPret* getCentura();

	void setGi(const GiBjj& gi);

	HasPret* getGi();

	void setProprietar(const std::string proprietar);

	std::string getProprietar();

	void afisare();


	EchipamentBjj& operator=(const EchipamentBjj& echipament);

	friend std::ostream& operator<<(std::ostream& out, EchipamentBjj& echipament);
};

