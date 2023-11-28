#include "GiBjj.h"

GiBjj::GiBjj() : id(100)
{
	materialeTextie = NULL;
	nrMaterialeTextile = 0;
	culoare = "";
	taraFabricatie = "";
	pret = 0;
	firmaProducatoare = "";
}

GiBjj::GiBjj(GiBjj& gi) : id(gi.id)
{
	setPret(gi.pret);
	setTaraFabricatie(gi.taraFabricatie);
	setMaterialeTextile(gi.nrMaterialeTextile, gi.materialeTextie);
	setCuloare(gi.culoare);
	setFirmaProductoare(gi.firmaProducatoare);
	this->nrGi++;
	this->valoareTotala += pret;
}

GiBjj::GiBjj(int id, int pret, std::string taraFabricatie, char** materialeTextie, int nrMaterialeTextile, std::string culoare, std::string firmaProducatoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setMaterialeTextile(nrMaterialeTextile, materialeTextie);
	setCuloare(culoare);
	setFirmaProductoare(firmaProducatoare);
	this->nrGi++;
	this->valoareTotala += pret;
}

GiBjj::GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setCuloare(culoare);
	setFirmaProductoare(firmaProducatoare);
	this->nrGi++;
	this->valoareTotala += pret;
}

GiBjj::GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setCuloare(culoare);
	setFirmaProductoare("Nu este cunoscuta");
	this->nrGi++;
	this->valoareTotala += pret;
}

GiBjj::~GiBjj()
{
	nrGi--;
	valoareTotala -= pret;
	if (this->materialeTextie != NULL)
	{
		for (int i = 0; i < this->nrMaterialeTextile; i++)
		{
			delete[] this->materialeTextie[i];
		}
		delete[] this->materialeTextie;
	}
}

float GiBjj::pretMediuGi()
{
	return ((float)valoareTotala / nrGi)/100;
}

void GiBjj::afisare()
{
	std::cout << "\n\n";
	std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : " << this->pret / 100 << "." << this->pret % 100 << "\nfirma producatoare : " << this->firmaProducatoare
		<< "\nculoare : " << this->culoare << "\nmateriale textile continute : " << this->nrMaterialeTextile;
	for (int i = 0; i < this->nrMaterialeTextile; i++)
	{
		std::cout << "\n" << this->materialeTextie[i];
	}
}

std::string GiBjj::getSport()
{
	return sport;
}

void GiBjj::setSport(std::string sport)
{
	GiBjj::sport = sport;
}

int GiBjj::getNrGi()
{
	return nrGi;
}

void GiBjj::setNrGi(int nr)
{
	GiBjj::nrGi = nr;
}

int GiBjj::getValoareTotala()
{
	return valoareTotala;
}

void GiBjj::setValoareTotala(int valoareTotala)
{
	GiBjj::valoareTotala = valoareTotala;
}

int GiBjj::getNrMaterialeTextile()
{
	return nrMaterialeTextile;
}

char** GiBjj::getMaterialeTextile()
{
	return materialeTextie;
}

void GiBjj::setMaterialeTextile(int nrMaterialeTextile, char** materialeTextile)
{
	if (nrMaterialeTextile > 0)
	{
		if (this->materialeTextie != NULL)
		{
			for (int i = 0; i < this->nrMaterialeTextile; i++)
			{
				delete[] this->materialeTextie[i];
			}
			delete[] this->materialeTextie;
		}
		this->nrMaterialeTextile = nrMaterialeTextile;
		this->materialeTextie = new char* [nrMaterialeTextile];
		for (int i = 0; i < this->nrMaterialeTextile; i++)
		{
			this->materialeTextie[i] = new char[strlen(materialeTextile[i]) + 1];
			strcpy_s(this->materialeTextie[i], strlen(materialeTextile[i]) + 1, materialeTextile[i]);
		}
	}
	else
	{
		this->materialeTextie = 0;
		this->materialeTextie = NULL;
	}
}

std::string GiBjj::getTaraFabricatie()
{
	return taraFabricatie;
}

void GiBjj::setTaraFabricatie(std::string taraFabricatie)
{
	this->taraFabricatie = taraFabricatie;
}

std::string GiBjj::getCuloare()
{
	return culoare;
}

void GiBjj::setCuloare(std::string culoare)
{
	this->culoare = culoare;
}

float GiBjj::getPret()
{
	return (float)pret / 100;
}

void GiBjj::setPret(int pretNou)
{
	pret = pretNou;
}

std::string GiBjj::getFirmaProductoare()
{
	return firmaProducatoare;
}

void GiBjj::setFirmaProductoare(std::string firmaProducatoare)
{
	this->firmaProducatoare = firmaProducatoare;
}

int GiBjj::getId()
{
	return id;
}

GiBjj& GiBjj::operator=(const GiBjj& gi)
{
	if (this != &gi)
	{
		setPret(gi.pret);
		setTaraFabricatie(gi.taraFabricatie);
		setMaterialeTextile(gi.nrMaterialeTextile, gi.materialeTextie);
		setCuloare(gi.culoare);
		setFirmaProductoare(gi.firmaProducatoare);
	}
	return *this;
}

char* GiBjj::operator[](int index)
{
	return this->materialeTextie[index];
}

bool GiBjj::operator>(const GiBjj& gi)
{
	return this->pret > gi.pret;
}

bool GiBjj::operator<(const GiBjj& gi)
{
	return this->pret < gi.pret;
}

GiBjj GiBjj::operator++()
{
	this->pret += 100;
	return *this;
}

GiBjj GiBjj::operator++(int i)
{
	GiBjj gi(*this);
	gi.pret += 100;
	return gi;
}

std::istream& operator>>(std::istream& in, GiBjj& gi)
{
	std::cout << "\nTara fabricatie : ";
	in >> gi.taraFabricatie;
	std::cout << "\nCuloare : ";
	in >> gi.culoare;
	std::cout << "\nPret : ";
	in >> gi.pret;
	std::cout << "\nFirma producatoare : ";
	in >> gi.firmaProducatoare;
	if (gi.materialeTextie != NULL)
	{
		delete[] gi.materialeTextie;
	}
	std::cout << "\nNr materiale textile : ";
	in >> gi.nrMaterialeTextile;
	if (gi.nrMaterialeTextile > 0)
	{
		gi.materialeTextie = new char* [gi.nrMaterialeTextile];
		for (int i = 0; i < gi.nrMaterialeTextile; i++)
		{
			std::string aux;
			std::cout << "\nMaterial textil : ";
			in >> aux;
			gi.materialeTextie[i] = new char[aux.length() + 1];
			strcpy_s(gi.materialeTextie[i], aux.length() + 1, aux.c_str());
		}
	}
	else
	{
		gi.nrMaterialeTextile = 0;
		gi.materialeTextie = NULL;
	}


	return in;
}

std::ostream& operator<<(std::ostream& out, GiBjj& gi)
{
	out << "\n\n";
	out << "id : " << gi.id << "\ntara de fabricatie : " << gi.taraFabricatie << "\npret : " << gi.pret / 100 << "." << gi.pret % 100 << "\nfirma producatoare : " << gi.firmaProducatoare
		<< "\nculoare : " << gi.culoare << "\nmateriale textile continute : " << gi.nrMaterialeTextile;
	for (int i = 0; i < gi.nrMaterialeTextile; i++)
	{
		std::cout << "\n" << gi.materialeTextie[i];
	}
	return out;
}

bool validareId(GiBjj& gi)
{
	return gi.id > 0;
}


std::ofstream& operator<<(std::ofstream& out, GiBjj& gi)
{
	int lungime = gi.taraFabricatie.length() + 1;
	out.write((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		out.write((char*)&gi.taraFabricatie[i], sizeof(char));
	}
	out.write((char*)&gi.pret, sizeof(int));
	lungime = gi.firmaProducatoare.length() + 1;
	out.write((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		out.write((char*)&gi.firmaProducatoare[i], sizeof(char));
	}
	lungime = gi.culoare.length() + 1;
	out.write((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		out.write((char*)&gi.culoare[i], sizeof(char));
	}
	out.write((char*)&gi.nrMaterialeTextile,sizeof(int));
	for (int i = 0; i < gi.nrMaterialeTextile; i++)
	{
		lungime = strlen(gi.materialeTextie[i])+ 1;
		out.write((char*)&lungime, sizeof(int));
		for (int j = 0; j < lungime; j++)
		{
			out.write((char*)&gi.materialeTextie[i][j], sizeof(char));
		}
	}
	return out;
}


std::ifstream& operator>>(std::ifstream& in, GiBjj& gi)
{
	int lungime;
	in.read((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		in.read((char*)&gi.taraFabricatie[i], sizeof(char));
	}
	in.read((char*)&gi.pret, sizeof(int));
	in.read((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		in.read((char*)&gi.firmaProducatoare[i], sizeof(char));
	}
	in.read((char*)&lungime, sizeof(int));
	for (int i = 0; i < lungime; i++)
	{
		in.read((char*)&gi.culoare[i], sizeof(char));
	}
	in.read((char*)&gi.nrMaterialeTextile, sizeof(int));
	if (gi.materialeTextie != NULL)
	{
		for (int i = 0; i < gi.nrMaterialeTextile; i++)
		{
			delete[] gi.materialeTextie[i];
		}
		delete[] gi.materialeTextie;
	}
	gi.materialeTextie = new char* [gi.nrMaterialeTextile];
	for (int i = 0; i < gi.nrMaterialeTextile; i++)
	{
		in.read((char*)&lungime, sizeof(int));
		gi.materialeTextie[i] = new char[lungime];
		for (int j = 0; j < lungime; j++)
		{
			in.read((char*)&gi.materialeTextie[i][j], sizeof(char));
		}
	}
	return in;
}
