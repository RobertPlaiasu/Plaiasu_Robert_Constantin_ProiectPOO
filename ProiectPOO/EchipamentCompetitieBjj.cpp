#include "EchipamentCompetitieBjj.h"

EchipamentCompetitieBjj::EchipamentCompetitieBjj() : EchipamentBjj::EchipamentBjj()
{
	this->clubSportiv = "Nu exista club sportiv!";
	this->lungimeCentura = 0;
}

EchipamentCompetitieBjj::EchipamentCompetitieBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar, int lungimeCentura, std::string clubSportiv) :
	EchipamentBjj::EchipamentBjj( id,  centura,  gi, proprietar)
{
	this->lungimeCentura = lungimeCentura;
	this->clubSportiv = clubSportiv;
}

EchipamentCompetitieBjj::EchipamentCompetitieBjj(const EchipamentCompetitieBjj& echipament) 
{
	(EchipamentBjj&)*this = echipament;
	this->clubSportiv = echipament.clubSportiv;
	this->lungimeCentura = echipament.lungimeCentura;
}

int EchipamentCompetitieBjj::getLungimeCentura()
{
	return this->lungimeCentura;
}

std::string EchipamentCompetitieBjj::getClubSportiv()
{
	return this->clubSportiv;
}

void EchipamentCompetitieBjj::setLungimeCentura(int lungimeCentura)
{
	this->lungimeCentura = lungimeCentura;
}

void EchipamentCompetitieBjj::setClubSportiv(std::string clubSportiv)
{
	this->clubSportiv = clubSportiv;
}

EchipamentCompetitieBjj& EchipamentCompetitieBjj::operator=(const EchipamentCompetitieBjj& echipament)
{	
	(EchipamentBjj&)(*this) = (EchipamentBjj&)echipament;
	this->lungimeCentura = echipament.lungimeCentura;
	this->clubSportiv = echipament.clubSportiv;
	return *this;
}

std::ostream& operator<<(std::ostream& out,EchipamentCompetitieBjj& echipament)
{
	out << (EchipamentBjj&)echipament;
	out << "\nLungime centura : " << echipament.lungimeCentura;
	out << "\nClub sportiv : " << echipament.clubSportiv;
	return out;
}