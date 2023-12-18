#include "EchipamentBjj.h"


EchipamentBjj::EchipamentBjj() : id(100)
{
	proprietar = "Nu are proprietar !";
	centura = new CenturaBjj();
	gi = new GiBjj();
}

EchipamentBjj::EchipamentBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar) : id(id)
{
	this->centura = new CenturaBjj(centura);
	this->gi = new GiBjj(gi);
	this->proprietar = proprietar;
}

EchipamentBjj::EchipamentBjj(const EchipamentBjj& echipament) : id(echipament.id)
{
	this->centura = new CenturaBjj(*(CenturaBjj*)echipament.centura);
	this->gi = new GiBjj(*(GiBjj*)echipament.gi);
	this->proprietar = echipament.proprietar;
}

EchipamentBjj::~EchipamentBjj()
{
	delete this->centura;
	delete this->gi;
}

void EchipamentBjj::setCentura(const CenturaBjj& centura)
{
	this->centura = new CenturaBjj(centura);
}

HasPret* EchipamentBjj::getCentura()
{
	return centura;
}

void EchipamentBjj::setGi(const GiBjj& gi)
{
	this->gi = new GiBjj(gi);
}

HasPret* EchipamentBjj::getGi()
{
	return  this->gi;
}

void EchipamentBjj::setProprietar(const std::string proprietar)
{
	this->proprietar = proprietar;
}

std::string EchipamentBjj::getProprietar()
{
	return proprietar;
}


EchipamentBjj& EchipamentBjj::operator=(const EchipamentBjj& echipament)
{
	this->centura = new CenturaBjj(*(CenturaBjj*)echipament.centura);
	this->gi = new GiBjj(*(GiBjj*)echipament.gi);
	this->proprietar = echipament.proprietar;
	return *this;
}


std::ostream& operator<<(std::ostream& out, EchipamentBjj& echipament)
{
	out << "\nID : " << echipament.id;
	out << "\nProprietar : " << echipament.proprietar;

	out << "\nPret gi : "  <<echipament.getGi()->getPret();
	out << "\nPret centura : " << echipament.getCentura()->getPret();

	return out;
}

void EchipamentBjj::afisare()
{
	std::cout << "\nID : " << this->id;
	std::cout << "\nProprietar : " << this->proprietar;

	std::cout << this->gi->getPret();
	std::cout << this->centura->getPret();
}