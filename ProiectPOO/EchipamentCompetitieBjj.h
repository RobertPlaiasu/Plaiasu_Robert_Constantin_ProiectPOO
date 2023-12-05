#pragma once
#include "EchipamentBjj.h"


class EchipamentCompetitieBjj  : public EchipamentBjj
{
private:
	int lungimeCentura;
	std::string clubSportiv;
public:
	EchipamentCompetitieBjj();
	EchipamentCompetitieBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar,int lungimeCentura, std::string clubSportiv);
	EchipamentCompetitieBjj(const EchipamentCompetitieBjj& echipament);
	void setLungimeCentura(int lungimeCentura);
	void setClubSportiv(std::string clubSportiv);
	int getLungimeCentura();
	std::string getClubSportiv();
	EchipamentCompetitieBjj& operator=(const EchipamentCompetitieBjj& echipament);
	friend std::ostream& operator<<(std::ostream& out ,EchipamentCompetitieBjj& echipament);
};