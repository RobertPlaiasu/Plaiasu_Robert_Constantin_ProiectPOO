#include "MingeEuropean.h"

MingeEuropean::MingeEuropean() : MingeFotbal::MingeFotbal()
{
	an = 0;
	taraGazda = "Nu se cunoaste";
}

MingeEuropean::MingeEuropean(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie, int an, std::string taraGazda) : 
	MingeFotbal::MingeFotbal(id,  pret, taraFabricatie,semnaturi, nrSemnaturi, obiectDeColectie)
{
	this->an = an;
	this->taraGazda = taraGazda;
}
MingeEuropean::MingeEuropean(int id, int pret, std::string taraFabricatie, bool obiectDeColectie, int an, std::string taraGazda) : 
	MingeFotbal::MingeFotbal(id, pret, taraFabricatie, obiectDeColectie)
{
	this->an = an;
	this->taraGazda = taraGazda;
}

MingeEuropean::MingeEuropean(const MingeEuropean& minge) : MingeFotbal::MingeFotbal(minge)
{ 
	this->an = minge.an;
	this->taraGazda = minge.taraGazda;
}

MingeEuropean& MingeEuropean::operator=(const MingeEuropean& minge)
{
	(MingeFotbal&)*this = (MingeFotbal&)minge;
	this->an = minge.an;
	this->taraGazda = minge.taraGazda;
	return *this;
}

void MingeEuropean::setAn(int an)
{
	this->an = an;
}

void MingeEuropean::setTaraGazda(std::string taraGazda)
{
	this->taraGazda = taraGazda;
}

int MingeEuropean::getAn()
{
	return this->an;
}

std::string MingeEuropean::getTaraGazda()
{
	return this->taraGazda;
}


std::ostream& operator<<(std::ostream& out, const MingeEuropean& minge)
{
	out << (MingeFotbal&)minge;
	out << "\nAn: " << minge.an;
	out << "\nTara gazda : " << minge.taraGazda;
	return out;
}