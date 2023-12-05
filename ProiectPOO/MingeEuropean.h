#pragma once
#include "MingeFotbal.h"

class MingeEuropean : public MingeFotbal
{
private: 
	int an;
	std::string taraGazda;
	static std::string continent;
public:
	MingeEuropean();
	MingeEuropean(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie,int an,std::string taraGazda);
	MingeEuropean(int id, int pret, std::string taraFabricatie, bool obiectDeColectie, int an, std::string taraGazda);
	MingeEuropean(const MingeEuropean& minge);
	MingeEuropean& operator=(const MingeEuropean& minge);

	
	void setAn(int an);


	void setTaraGazda(std::string taraGazda);

	int getAn();

	std::string getTaraGazda();

	friend std::ostream& operator<<(std::ostream&, const MingeEuropean& minge);
};