#include <iostream>
#include <string>

// Am ales tema Sport - Plaiasu Robert

class MingeFotbal
{
public:
	const int id;

	static std::string sport;
	static int nrMingiDeColectie;
	static int valoareMingiDeColectie;

	char** semnaturi;
	int nrSemnaturi;
	std::string taraFabricatie;
	bool obiectDeColectie;
	int pret;
	// mingea are emblema unui club sportiv
	std::string clubSportiv;

	

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi,int nrSemnaturi,std::string clubSportiv,bool obiectDeColectie) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->nrSemnaturi = nrSemnaturi;
		this->semnaturi = new char*[nrSemnaturi];
		for (int i = 0; i < this->nrSemnaturi; i++)
		{
			this->semnaturi[i] = new char[strlen(semnaturi[i]) + 1];
			strcpy_s(this->semnaturi[i],strlen(semnaturi[i])+1,semnaturi[i]);
		}
		this->clubSportiv = clubSportiv;
		this->obiectDeColectie = obiectDeColectie;
		if (obiectDeColectie)
		{
			nrMingiDeColectie++;
			valoareMingiDeColectie += pret;
		}
	}

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->nrSemnaturi = nrSemnaturi;
		this->semnaturi = new char* [nrSemnaturi];
		for (int i = 0; i < this->nrSemnaturi; i++)
		{
			this->semnaturi[i] = new char[strlen(semnaturi[i]) + 1];
			strcpy_s(this->semnaturi[i], strlen(semnaturi[i]) + 1, semnaturi[i]);
		}
		this->clubSportiv = "Nu are club sportiv";
		this->obiectDeColectie = obiectDeColectie;
		if (obiectDeColectie)
		{
			nrMingiDeColectie++;
			valoareMingiDeColectie += pret;
		}
	}

	MingeFotbal(int id, int pret, std::string taraFabricatie, bool obiectDeColectie) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->obiectDeColectie = obiectDeColectie;
		this->nrSemnaturi = 0;
		this->semnaturi = NULL;
		this->clubSportiv = "Nu are club sportiv";
		if (obiectDeColectie)
		{
			nrMingiDeColectie++;
			valoareMingiDeColectie += pret;
		}
	}

	~MingeFotbal()
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

	static float valoareMedieMingiDeColectie()
	{
		return ((float)valoareMingiDeColectie / nrMingiDeColectie)/100;
	}

	void afisare()
	{
		std::cout << "\n\n";
		std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : "<< this->pret/100 << "."<<this->pret%100 << "\nclub sportiv:" << this->clubSportiv
		<< "\nnr de semnaturi : " << this->nrSemnaturi;
		for (int i = 0; i < this->nrSemnaturi; i++)
		{
			std::cout << "\n" << i+1 << " : " << this->semnaturi[i];
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

};

struct Data
{
	int an;
	int luna;
	int zi;
};

class CenturaBjj
{
public:
	const int id;
	static std::string sport;
	static int valoareTotala;
	static int nrCenturi;

	// la o centura pe care o ai poti avea dungi albe pe partea neagra ce simbolizeaza cat de avansat esti
	// retin momentul in timp cand am primit o dunga
	Data* dungi;
	int nrDungi;

	std::string culoare;
	std::string taraFabricatie;
	
	int pret;
	
	std::string firmaProducatoare;




	CenturaBjj(int id, int pret, std::string taraFabricatie, Data* dungi, int nrDungi, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->nrDungi = nrDungi;
		this->dungi = new Data[nrDungi];
		for (int i = 0; i < this->nrDungi; i++)
		{
			this->dungi[i].an =  dungi[i].an;
			this->dungi[i].luna = dungi[i].luna;
			this->dungi[i].zi = dungi[i].zi;
		}
		this->culoare = culoare;
		this->firmaProducatoare = firmaProducatoare;
		this->nrCenturi++;
		this->valoareTotala += pret;
	}

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->culoare = culoare;
		this->firmaProducatoare = firmaProducatoare;
		this->nrDungi = 0;
		this->dungi = NULL;
		this->nrCenturi++;
		this->valoareTotala += pret;
	}

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->culoare = culoare;
		this->nrCenturi++;
		this->valoareTotala += pret;
		this->nrDungi = 0;
		this->dungi = NULL;
		this->firmaProducatoare = "Nu este cunoscuta";
	}

	~CenturaBjj()
	{
		nrCenturi--;
		valoareTotala -= pret;
		if (this->dungi != NULL)
		{
			delete[] this->dungi;
		}
	}
	
	static float pretMediuCentura()
	{
		return ((float)valoareTotala / nrCenturi)/100;
	}

	void afisare()
	{
		std::cout << "\n\n";
		std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : " << this->pret / 100 << "." << this->pret % 100 << "\nfirma producatoare : " << this->firmaProducatoare
			<<"\nculoare : "<< this->culoare << "\nnr de stripe-uri : " << this->nrDungi;
		for (int i = 0; i < this->nrDungi; i++)
		{
			std::cout << "\n" << i+1 << " : " << this->dungi[i].an <<"."<< this->dungi[i].luna <<"." << this->dungi[i].zi;
		}
	}

};

class GiBjj
{
public:
	const int id;
	static std::string sport;
	static int nrGi;
	static int valoareTotala;

	int nrMaterialeTextile;
	char** materialeTextie;

	std::string culoare;
	std::string taraFabricatie;

	int pret;

	std::string firmaProducatoare;




	GiBjj(int id, int pret, std::string taraFabricatie, char** materialeTextie, int nrMaterialeTextile, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->nrMaterialeTextile = nrMaterialeTextile;
		this->materialeTextie = new char*[nrMaterialeTextile];
		for (int i = 0; i < this->nrMaterialeTextile; i++)
		{
			this->materialeTextie[i] = new char[strlen(materialeTextie[i])+1];
			strcpy_s(this->materialeTextie[i], strlen(materialeTextie[i]) + 1, materialeTextie[i]);
		}
		this->culoare = culoare;
		this->firmaProducatoare = firmaProducatoare;
		this->nrGi++;
		this->valoareTotala += pret;
	}

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->culoare = culoare;
		this->firmaProducatoare = firmaProducatoare;
		this->nrGi++;
		this->valoareTotala += pret;
		this->materialeTextie = NULL;
		this->nrMaterialeTextile = 0;
	}

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
	{
		this->pret = pret;
		this->taraFabricatie = taraFabricatie;
		this->culoare = culoare;
		this->nrGi++;
		this->valoareTotala += pret;
		this->materialeTextie = NULL;
		this->nrMaterialeTextile = 0;
		this->firmaProducatoare = "Nu este cunoscuta";
	}

	~GiBjj()
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

	static float pretMediuGi()
	{
		return ((float)valoareTotala / nrGi)/100;
	}

	void afisare()
	{
		std::cout << "\n\n";
		std::cout << "id : " << this->id << "\ntara de fabricatie : " << this->taraFabricatie << "\npret : " << this->pret / 100 << "." << this->pret % 100 << "\nfirma producatoare : " << this->firmaProducatoare
			<< "\nculoare : " << this->culoare << "\nmateriale textile continute : " << this->nrMaterialeTextile;
		for (int i = 0; i < this->nrMaterialeTextile; i++)
		{
			std::cout << "\n" << this->materialeTextie[i];
		}
	}
};

std::string MingeFotbal::sport = "Fotbal";
int MingeFotbal::nrMingiDeColectie = 0;
int MingeFotbal::valoareMingiDeColectie = 0;

std::string CenturaBjj::sport = "Bjj";
int CenturaBjj::nrCenturi = 0;
int CenturaBjj::valoareTotala = 0;

std::string GiBjj::sport = "Bjj";
int GiBjj::nrGi = 0;
int GiBjj::valoareTotala = 0;

void main()
{
	char** semnaturi = new char* [2];
	semnaturi[0] = new char[strlen("Ronaldo") + 1];
	semnaturi[1] = new char[strlen("Messi") + 1];
	strcpy_s(semnaturi[0],strlen("Ronaldo")+1,"Ronaldo");
	strcpy_s(semnaturi[1], strlen("Messi") + 1, "Messi");

	MingeFotbal minge1(1,333,"Vietnam",semnaturi,2,"Fc. Barcelona", 1);
	MingeFotbal minge2(2, 333, "Vietnam", 0);
	MingeFotbal minge3(3, 3443, "Vietnam",semnaturi,2,1);
	minge1.afisare();
	minge2.afisare();
	minge3.afisare();
	std::cout << "\n\n\nValoare medie mingi de colectie  : "<<MingeFotbal::valoareMedieMingiDeColectie();

	delete[] semnaturi[0];
	delete[] semnaturi[1];
	delete[] semnaturi;

	Data* date = new Data[2];
	date[0].an = 2020;
	date[0].luna = 3;
	date[0].zi = 23;

	date[1].an = 2021;
	date[1].luna = 4;
	date[1].zi = 4;

	CenturaBjj centura1(1, 333, "Vietnam",date,2,"neagra","Tatami");
	CenturaBjj centura2(2, 3993, "Vietnam","maro","Kings");
	CenturaBjj centura3(3, 500, "Vietnam","alba");
	centura1.afisare();
	centura2.afisare();
	centura3.afisare();
	std::cout << "\n\n\nValoare medie centuri  : " << CenturaBjj::pretMediuCentura();

	delete[] date;

	char** materiale = new char* [2];
	materiale[0] = new char[strlen("bumbac") + 1];
	materiale[1] = new char[strlen("elastan") + 1];
	strcpy_s(materiale[0], strlen("bumbac") + 1, "bumbac");
	strcpy_s(materiale[1], strlen("elastan") + 1, "elastan");

	GiBjj gi1(1,9999,"Pakistan" ,"albastru","Tatami");
	GiBjj gi2(2, 9900, "Pakistan",materiale,2, "negru", "Tatami");
	GiBjj gi3(3, 10000, "Spania","alb");
	gi1.afisare();
	gi2.afisare();
	gi3.afisare();
	std::cout << "\n\n\nValoare medie gi  : " << GiBjj::pretMediuGi();

	delete[] materiale[0];
	delete[] materiale[1];
	delete[] materiale;

}