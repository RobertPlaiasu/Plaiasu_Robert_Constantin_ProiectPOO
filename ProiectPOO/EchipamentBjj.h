#pragma once
#include "CenturaBjj.h"
#include "GiBjj.h"

class EchipamentBjj
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


	EchipamentBjj& operator=(const EchipamentBjj& echipament);

	explicit operator GiBjj& ();

	friend std::ostream& operator<<(std::ostream& out, EchipamentBjj& echipament);
};

