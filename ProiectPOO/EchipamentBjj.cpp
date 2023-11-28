#include "EchipamentBjj.h"


EchipamentBjj::EchipamentBjj() : id(100)
{
	proprietar = "Nu are proprietar !";
	centura = CenturaBjj();
	gi = GiBjj();
}

EchipamentBjj::EchipamentBjj(int id, CenturaBjj& centura, GiBjj& gi, std::string proprietar) : id(id)
{
	this->centura = centura;
	this->gi = gi;
	this->proprietar = proprietar;
}

EchipamentBjj::EchipamentBjj(const EchipamentBjj& echipament) : id(echipament.id)
{
	this->centura = echipament.centura;
	this->gi = echipament.gi;
	this->proprietar = echipament.proprietar;
}

EchipamentBjj::~EchipamentBjj()
{
}

void EchipamentBjj::setCentura(const CenturaBjj& centura)
{
	this->centura = centura;
}

CenturaBjj& EchipamentBjj::getCentura()
{
	return centura;
}

void EchipamentBjj::setGi(const GiBjj& gi)
{
	this->gi = gi;
}

GiBjj& EchipamentBjj::getGi()
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
	this->centura = echipament.centura;
	this->gi = echipament.gi;
	this->proprietar = echipament.proprietar;
	return *this;
}

EchipamentBjj::operator GiBjj& ()
{
	return gi;
}

std::ostream& operator<<(std::ostream& out, EchipamentBjj& echipament)
{
	out << "\nID : " << echipament.id;
	out << "\nProprietar : " << echipament.proprietar;

	out << echipament.gi;
	out << echipament.centura;

	return out;
}

std::ofstream& operator<<(std::ofstream& out, EchipamentBjj& echipament)
{
	int lungime = echipament.proprietar.length() + 1;
	out.write((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		out.write((char*)&echipament.proprietar[i], sizeof(char));
	}
	out << echipament.gi;
	lungime = echipament.centura.getCuloare().length();
	afisareFisierBinar(out,echipament.centura);
	return out;
}

std::ifstream& operator>>(std::ifstream& in, EchipamentBjj& echipament)
{
	int lungime;
	in.read((char*)&lungime,sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		in.read((char*)&echipament.proprietar[i], sizeof(char));
	}
	in >> echipament.gi;
	citireFisierBinar(in, echipament.centura);
	return in;
}