#include "CenturaBjj.h"

CenturaBjj::CenturaBjj() : id(100)
{
	dungi = NULL;
	nrDungi = 0;
	culoare = "";
	taraFabricatie = "";
	pret = 0;
	firmaProducatoare = "";
}

CenturaBjj::CenturaBjj(CenturaBjj& centura) : id(centura.id)
{
	setPret(centura.pret);
	setTaraFabricatie(centura.taraFabricatie);
	setDungi(centura.nrDungi, centura.dungi);
	setCuloare(centura.culoare);
	setFirmaProductoare(centura.firmaProducatoare);
	this->nrCenturi++;
	this->valoareTotala += pret;
}

CenturaBjj::CenturaBjj(int id, int pret, std::string taraFabricatie, Data* dungi, int nrDungi, std::string culoare, std::string firmaProducatoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setDungi(nrDungi, dungi);
	setCuloare(culoare);
	setFirmaProductoare(firmaProducatoare);
	this->nrCenturi++;
	this->valoareTotala += pret;
}

CenturaBjj::CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setCuloare(culoare);
	setFirmaProductoare(firmaProducatoare);
	this->nrCenturi++;
	this->valoareTotala += pret;
}

CenturaBjj::CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
{
	setPret(pret);
	setTaraFabricatie(taraFabricatie);
	setCuloare(culoare);
	this->nrCenturi++;
	this->valoareTotala += pret;
}

CenturaBjj::~CenturaBjj()
{
	nrCenturi--;
	valoareTotala -= pret;
	if (this->dungi != NULL)
	{
		delete[] this->dungi;
	}
}

float CenturaBjj::pretMediuCentura()
{
	return ((float)valoareTotala / nrCenturi) / 100;
}

void CenturaBjj::afisare()
{
	std::cout << "\n\n";
	std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : " << this->pret / 100 << "." << this->pret % 100 << "\nfirma producatoare : " << this->firmaProducatoare
		<< "\nculoare : " << this->culoare << "\nnr de stripe-uri : " << this->nrDungi;
	for (int i = 0; i < this->nrDungi; i++)
	{
		std::cout << "\n" << i + 1 << " : " << this->dungi[i].an << "." << this->dungi[i].luna << "." << this->dungi[i].zi;
	}
}

std::string CenturaBjj::getSport()
{
	return sport;
}

void CenturaBjj::setSport(std::string sport)
{
	CenturaBjj::sport = sport;
}

int CenturaBjj::getNrCenturi()
{
	return nrCenturi;
}

void CenturaBjj::setNrCenturi(int nr)
{
	CenturaBjj::nrCenturi = nr;
}

int CenturaBjj::getValoareTotala()
{
	return valoareTotala;
}

void CenturaBjj::setValoareTotala(int valoareTotala)
{
	CenturaBjj::valoareTotala = valoareTotala;
}

int  CenturaBjj::getNrDungi()
{
	return nrDungi;
}

Data* CenturaBjj::getDungi()
{
	return dungi;
}

void CenturaBjj::setDungi(int nrDungi, Data* dungi)
{
	if (nrDungi > 0)
	{
		if (this->dungi != NULL)
		{
			delete[] this->dungi;
		}
		this->nrDungi = nrDungi;
		this->dungi = new Data[nrDungi];
		for (int i = 0; i < this->nrDungi; i++)
		{
			this->dungi[i].an = dungi[i].an;
			this->dungi[i].luna = dungi[i].luna;
			this->dungi[i].zi = dungi[i].zi;
		}
	}
	else
	{
		this->nrDungi = 0;
		this->dungi = NULL;
	}
}

std::string CenturaBjj::getTaraFabricatie()
{
	return taraFabricatie;
}

void CenturaBjj::setTaraFabricatie(std::string taraFabricatie)
{
	this->taraFabricatie = taraFabricatie;
}

std::string CenturaBjj::getCuloare()
{
	return culoare;
}

void CenturaBjj::setCuloare(std::string culoare)
{
	this->culoare = culoare;
}

float CenturaBjj::getPret()
{
	return (float)pret / 100;
}

void CenturaBjj::setPret(int pretNou)
{
	pret = pretNou;
}

std::string CenturaBjj::getFirmaProductoare()
{
	return firmaProducatoare;
}

void CenturaBjj::setFirmaProductoare(std::string firmaProducatoare)
{
	this->firmaProducatoare = firmaProducatoare;
}

int CenturaBjj::getId()
{
	return id;
}

CenturaBjj& CenturaBjj::operator=(const CenturaBjj& centura)
{
	if (this != &centura)
	{
		this->pret = centura.pret;
		setTaraFabricatie(centura.taraFabricatie);
		setDungi(centura.nrDungi, centura.dungi);
		setCuloare(centura.culoare);
		setFirmaProductoare(centura.firmaProducatoare);
	}
	return *this;
}

bool CenturaBjj::operator==(const CenturaBjj& centura)
{
	return this->culoare == centura.culoare;
}

CenturaBjj::operator std::string()
{
	return this->culoare;
}

CenturaBjj::operator float()
{
	return getPret();
}

CenturaBjj::operator int()
{
	return pret;
}

std::istream& operator>>(std::istream& in, CenturaBjj& centura)
{
	std::cout << "\nTara fabricatie : ";
	in >> centura.taraFabricatie;
	std::cout << "\nCuloare : ";
	in >> centura.culoare;
	std::cout << "\nPret : ";
	in >> centura.pret;
	std::cout << "\nFirma producatoare : ";
	in >> centura.firmaProducatoare;
	if (centura.dungi != NULL)
	{
		delete[] centura.dungi;
	}
	std::cout << "\nNr dungi : ";
	in >> centura.nrDungi;
	if (centura.nrDungi > 0)
	{
		centura.dungi = new Data[centura.nrDungi];
		for (int i = 0; i < centura.nrDungi; i++)
		{
			std::cout << "\nAn : ";
			in >> centura.dungi[i].an;
			std::cout << "\nLuna : ";
			in >> centura.dungi[i].luna;
			std::cout << "\nZi : ";
			in >> centura.dungi[i].zi;

		}
	}
	else
	{
		centura.nrDungi = 0;
		centura.dungi = NULL;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, CenturaBjj& centura)
{
	out << "\n\n";
	out << "id : " << centura.id << "\ntara de fabricatie : " << centura.taraFabricatie << "\npret : " << centura.pret / 100 << "." << centura.pret % 100 << "\nfirma producatoare : " << centura.firmaProducatoare
		<< "\nculoare : " << centura.culoare << "\nnr de stripe-uri : " << centura.nrDungi;
	for (int i = 0; i < centura.nrDungi; i++)
	{
		out << "\n" << i + 1 << " : " << centura.dungi[i].an << "." << centura.dungi[i].luna << "." << centura.dungi[i].zi;
	}

	return out;
}
