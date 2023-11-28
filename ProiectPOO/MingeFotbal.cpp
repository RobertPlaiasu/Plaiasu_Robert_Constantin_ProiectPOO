#include "MingeFotbal.h"

MingeFotbal::MingeFotbal() : id(100)
{
	semnaturi = NULL;
	nrSemnaturi = 0;
	taraFabricatie = "";
	obiectDeColectie = 0;
	clubSportiv = "";
}

MingeFotbal::MingeFotbal(const MingeFotbal& minge) : id(minge.id)
{
	this->pret = minge.pret;
	setTaraFabricati(minge.taraFabricatie);
	setSemnaturi(minge.nrSemnaturi, minge.semnaturi);
	setClubSportiv(minge.clubSportiv);
	setObiectDeColetie(minge.obiectDeColectie);
	if (obiectDeColectie)
	{
		nrMingiDeColectie++;
		valoareMingiDeColectie += pret;
	}
}

MingeFotbal::MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, std::string clubSportiv, bool obiectDeColectie) : id(id)
{
	setPret(pret);
	setTaraFabricati(taraFabricatie);
	setSemnaturi(nrSemnaturi, semnaturi);
	setClubSportiv(clubSportiv);
	setObiectDeColetie(obiectDeColectie);
	if (obiectDeColectie)
	{
		nrMingiDeColectie++;
		valoareMingiDeColectie += pret;
	}
}

MingeFotbal::MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie) : id(id)
{
	setPret(pret);
	setTaraFabricati(taraFabricatie);
	setSemnaturi(nrSemnaturi, semnaturi);
	setObiectDeColetie(obiectDeColectie);
	if (obiectDeColectie)
	{
		nrMingiDeColectie++;
		valoareMingiDeColectie += pret;
	}
}

MingeFotbal::MingeFotbal(int id, int pret, std::string taraFabricatie, bool obiectDeColectie) : id(id)
{
	setPret(pret);
	setTaraFabricati(taraFabricatie);
	setObiectDeColetie(obiectDeColectie);
	if (obiectDeColectie)
	{
		nrMingiDeColectie++;
		valoareMingiDeColectie += pret;
	}
}

MingeFotbal::~MingeFotbal()
{
	if (this->obiectDeColectie)
	{
		nrMingiDeColectie--;
		valoareMingiDeColectie -= pret;
	}

	if (this->semnaturi != NULL)
	{
		for (int i = 0; i < this->nrSemnaturi; i++)
		{
			delete this->semnaturi[i];
		}
		delete[] this->semnaturi;
	}
}

float MingeFotbal::valoareMedieMingiDeColectie()
{
	return ((float)valoareMingiDeColectie / nrMingiDeColectie) / 100;
}

void  MingeFotbal::afisare()
{
	std::cout << "\n\n";
	std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : " << this->pret / 100 << "." << this->pret % 100 << "\nclub sportiv:" << this->clubSportiv
		<< "\nnr de semnaturi : " << this->nrSemnaturi;
	for (int i = 0; i < this->nrSemnaturi; i++)
	{
		std::cout << "\n" << i + 1 << " : " << this->semnaturi[i];
	}
	if (this->obiectDeColectie)
	{
		std::cout << "\nEste obiect de colectie";
	}
	else
	{
		std::cout << "\nNu este obiect de colectie";
	}
}

std::string  MingeFotbal::getSport()
{
	return sport;
}

void  MingeFotbal::setSport(std::string sport)
{
	MingeFotbal::sport = sport;
}

int MingeFotbal::getNrMingiColectie()
{
	return nrMingiDeColectie;
}

void  MingeFotbal::setNrMingiColectie(int nr)
{
	MingeFotbal::nrMingiDeColectie = nr;
}

int  MingeFotbal::getValoareMingiColectie()
{
	return valoareMingiDeColectie;
}

void  MingeFotbal::setValoareMingiColectie(int nr)
{
	MingeFotbal::valoareMingiDeColectie = nr;
}

int  MingeFotbal::getNrSemnaturi()
{
	return nrSemnaturi;
}

char** MingeFotbal::getSemnaturi()
{
	return semnaturi;
}

void  MingeFotbal::setSemnaturi(int nrSemnaturi, char** semnaturi)
{

	if (nrSemnaturi > 0)
	{
		if (this->semnaturi != NULL)
		{
			for (int i = 0; i < this->nrSemnaturi; i++)
			{
				delete[] this->semnaturi[i];
			}
			delete[] this->semnaturi;
		}
		this->nrSemnaturi = nrSemnaturi;
		this->semnaturi = new char* [nrSemnaturi];
		for (int i = 0; i < this->nrSemnaturi; i++)
		{
			this->semnaturi[i] = new char[strlen(semnaturi[i]) + 1];
			strcpy_s(this->semnaturi[i], strlen(semnaturi[i]) + 1, semnaturi[i]);
		}
	}
	else {
		this->nrSemnaturi = 0;
		this->semnaturi = NULL;
	}

}

std::string  MingeFotbal::getTaraFabricatie()
{
	return taraFabricatie;
}

void  MingeFotbal::setTaraFabricati(std::string taraFabricatie)
{
	this->taraFabricatie = taraFabricatie;
}

float  MingeFotbal::getPret()
{
	return (float)pret / 100;
}

void  MingeFotbal::setPret(int pretNou)
{
	if (this->obiectDeColectie)
		MingeFotbal::valoareMingiDeColectie = MingeFotbal::valoareMingiDeColectie - pret + pretNou;
	pret = pretNou;
}

std::string  MingeFotbal::getClubSportiv()
{
	return clubSportiv;
}

void  MingeFotbal::setClubSportiv(std::string clubSportiv)
{
	this->clubSportiv = clubSportiv;
}

bool  MingeFotbal::getObiectDeColetie()
{
	return obiectDeColectie;
}

void  MingeFotbal::setObiectDeColetie(bool obiectDeColectie)
{
	this->obiectDeColectie = obiectDeColectie;
}

int  MingeFotbal::getId()
{
	return id;
}

MingeFotbal& MingeFotbal::operator=(const MingeFotbal& minge)
{
	if (this != &minge)
	{
		setPret(minge.pret);
		setTaraFabricati(minge.taraFabricatie);
		setSemnaturi(minge.nrSemnaturi, minge.semnaturi);
		setClubSportiv(minge.clubSportiv);
		setObiectDeColetie(minge.obiectDeColectie);
		if (obiectDeColectie)
		{
			nrMingiDeColectie++;
		}
	}
	return *this;
}

char* MingeFotbal::operator[](int index)
{
	if (index <0 || index > this->nrSemnaturi)
	{
		throw std::exception("Index-ul este invalid");
	}
	char* semnatura = new char[strlen(this->semnaturi[index]) + 1];
	strcpy_s(semnatura, strlen(this->semnaturi[index]) + 1, this->semnaturi[index]);
	return semnatura;
}

std::ostream& operator<<(std::ostream& out, MingeFotbal& minge)
{
	out << "\n\n";
	out << "id : " << minge.id << "\ntara de fabricatie : " << minge.taraFabricatie << "\npret : " << minge.pret / 100 << "." << minge.pret % 100 << "\nclub sportiv:" << minge.clubSportiv
		<< "\nnr de semnaturi : " << minge.nrSemnaturi;
	for (int i = 0; i < minge.nrSemnaturi; i++)
	{
		out << "\n" << i + 1 << " : " << minge.semnaturi[i];
	}
	if (minge.obiectDeColectie)
	{
		out << "\nEste obiect de colectie";
	}
	else
	{
		out << "\nNu este obiect de colectie";
	}

	return out;
}

std::ofstream& operator<<(std::ofstream& out, MingeFotbal& minge)
{
	out << minge.taraFabricatie << " " << minge.pret  << " " << minge.clubSportiv
		<< " " << minge.nrSemnaturi;
	for (int i = 0; i < minge.nrSemnaturi; i++)
	{
		out << " " << minge.semnaturi[i] << " ";
	}
	if (minge.obiectDeColectie)
	{
		out << 1;
	}
	else
	{
		out << 0;
	}
	return out;
}


std::istream& operator>>(std::istream& in, MingeFotbal& minge)
{
	std::cout << "\nTara fabricatie : ";
	in >> minge.taraFabricatie;
	std::cout << "\nClub sportiv : ";
	in >> minge.clubSportiv;
	std::cout << "\nPret : ";
	in >> minge.pret;
	std::cout << "\nObiect de colectie : ";
	in >> minge.obiectDeColectie;
	if (minge.semnaturi != NULL)
	{
		for (int i = 0; i < minge.nrSemnaturi; i++)
		{
			delete[] minge.semnaturi[i];
		}
		delete[] minge.semnaturi;
	}
	std::cout << "\nNr semnaturi : ";
	in >> minge.nrSemnaturi;
	if (minge.nrSemnaturi > 0)
	{
		minge.semnaturi = new char* [minge.nrSemnaturi];
		for (int i = 0; i < minge.nrSemnaturi; i++)
		{
			std::string aux;
			std::cout << "\nSemnatura " << i + 1 << " : ";
			in >> aux;
			minge.semnaturi[i] = new char[aux.length() + 1];
			strcpy_s(minge.semnaturi[i], aux.length() + 1, aux.c_str());
		}
	}
	else {
		minge.semnaturi = NULL;
		minge.nrSemnaturi = 0;
	}
	return in;
}

std::ifstream& operator>>(std::ifstream& in, MingeFotbal& minge)
{
	
	in >> minge.taraFabricatie;
	in >> minge.pret;
	in >> minge.clubSportiv;
	if (minge.semnaturi != NULL)
	{
		for (int i = 0; i < minge.nrSemnaturi; i++)
		{
			delete[] minge.semnaturi[i];
		}
		delete[] minge.semnaturi;
	}
	in >> minge.nrSemnaturi;
	if (minge.nrSemnaturi > 0)
	{
		minge.semnaturi = new char* [minge.nrSemnaturi];
		for (int i = 0; i < minge.nrSemnaturi; i++)
		{
			std::string aux;
			in >> aux;
			minge.semnaturi[i] = new char[aux.length() + 1];
			strcpy_s(minge.semnaturi[i], aux.length() + 1, aux.c_str());
		}
	}
	else {
		minge.semnaturi = NULL;
		minge.nrSemnaturi = 0;
	}
	in >> minge.obiectDeColectie;
	return in;
}

int calculareDiferentePret(MingeFotbal& m1, MingeFotbal& m2)
{
	return m2.pret - m1.pret;
}

