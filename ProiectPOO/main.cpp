#include <iostream>
#include <string>

// Am ales tema Sport - Plaiasu Robert

class MingeFotbal
{
private:
	const int id;

	static std::string sport;
	static int nrMingiDeColectie;
	static int valoareMingiDeColectie;

	char** semnaturi;
	int nrSemnaturi;
	std::string taraFabricatie;
	bool obiectDeColectie;
	int pret = 0;
	// mingea are emblema unui club sportiv
	std::string clubSportiv;

public:
	
	MingeFotbal() : id(100)
	{
		semnaturi = NULL;
		nrSemnaturi = 0;
		taraFabricatie = "";
		obiectDeColectie = 0;
		clubSportiv = "";
	}
	
	MingeFotbal(const MingeFotbal& minge) : id(minge.id)
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

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi,int nrSemnaturi,std::string clubSportiv,bool obiectDeColectie) : id(id)
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

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie) : id(id)
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

	MingeFotbal(int id, int pret, std::string taraFabricatie, bool obiectDeColectie) : id(id)
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

	static std::string  getSport()
	{
		return sport;
	}

	static void setSport(std::string sport)
	{
		MingeFotbal::sport = sport;
	}

	static int  getNrMingiColectie()
	{
		return nrMingiDeColectie;
	}

	static void setNrMingiColectie(int nr)
	{
		MingeFotbal::nrMingiDeColectie = nr;
	}

	static int  getValoareMingiColectie()
	{
		return valoareMingiDeColectie;
	}

	static void setValoareMingiColectie(int nr)
	{
		MingeFotbal::valoareMingiDeColectie = nr;
	}

	int getNrSemnaturi()
	{
		return nrSemnaturi;
	}

	char** getSemnaturi()
	{
		return semnaturi;
	}

	void setSemnaturi(int nrSemnaturi,char** semnaturi)
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
			this->semnaturi = new char*[nrSemnaturi];
			for (int i = 0; i < this->nrSemnaturi; i++)
			{
				this->semnaturi[i] = new char[strlen(semnaturi[i]) + 1];
				strcpy_s(this->semnaturi[i], strlen(semnaturi[i]) + 1, semnaturi[i]);
			}
		}
		
	}

	std::string getTaraFabricatie()
	{
		return taraFabricatie;
	}

	void setTaraFabricati(std::string taraFabricatie)
	{
		this->taraFabricatie = taraFabricatie;
	}

	float getPret()
	{
		return (float)pret / 100;
	}

	void setPret(int pretNou)
	{
		if (this->obiectDeColectie)
			MingeFotbal::valoareMingiDeColectie = MingeFotbal::valoareMingiDeColectie - pret + pretNou;
		pret = pretNou;
	}

	std::string getClubSportiv()
	{
		return clubSportiv;
	}

	void setClubSportiv(std::string clubSportiv)
	{
		this->clubSportiv = clubSportiv;
	}

	bool getObiectDeColetie()
	{
		return obiectDeColectie;
	}

	void setObiectDeColetie(bool obiectDeColectie)
	{
		this->obiectDeColectie = obiectDeColectie;
	}

	int getId()
	{
		return id;
	}

	MingeFotbal& operator=(const MingeFotbal& minge)
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

	char* operator[](int index)
	{
		char* semnatura = new char[strlen(this->semnaturi[index])+1];
		strcpy_s(semnatura,strlen(this->semnaturi[index])+1, this->semnaturi[index]);
		return semnatura;
	}

	friend std::ostream& operator<<(std::ostream& out, MingeFotbal& minge)
	{
		out << "\n\n";
		out << "id : " << minge.id << "\ntara de fabricatie : " << minge.taraFabricatie << "\npret : " << minge.pret/100 << "." << minge.pret % 100 << "\nclub sportiv:" << minge.clubSportiv
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

	friend std::istream& operator>>(std::istream& in, MingeFotbal& minge)
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
				minge.semnaturi[i] = new char[aux.length()+1];
				strcpy_s(minge.semnaturi[i], aux.length() +1, aux.c_str());
			}
		}
		return in;
	}
	


	friend int calculareDiferentePret(MingeFotbal& m1, MingeFotbal& m2);
};

struct Data
{
	int an;
	int luna;
	int zi;
};

class CenturaBjj
{
private:
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
public:
	CenturaBjj() : id(100)
	{
		dungi = NULL;
		nrDungi = 0;
		culoare = "";
		taraFabricatie = "";
		pret = 0;
		firmaProducatoare = "";
	}

	CenturaBjj(CenturaBjj& centura) : id(centura.id)
	{
		setPret(centura.pret);
		setTaraFabricatie(centura.taraFabricatie);
		setDungi(centura.nrDungi, centura.dungi);
		setCuloare(centura.culoare);
		setFirmaProductoare(centura.firmaProducatoare);
		this->nrCenturi++;
		this->valoareTotala += pret;
	}

	CenturaBjj(int id, int pret, std::string taraFabricatie, Data* dungi, int nrDungi, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setDungi(nrDungi, dungi);
		setCuloare(culoare);
		setFirmaProductoare(firmaProducatoare);
		this->nrCenturi++;
		this->valoareTotala += pret;
	}

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setCuloare(culoare);
		setFirmaProductoare(firmaProducatoare);
		this->nrCenturi++;
		this->valoareTotala += pret;
	}

	CenturaBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setCuloare(culoare);
		this->nrCenturi++;
		this->valoareTotala += pret;
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

	static std::string getSport()
	{
		return sport;
	}

	static void setSport(std::string sport)
	{
		CenturaBjj::sport = sport;
	}

	static int  getNrCenturi()
	{
		return nrCenturi;
	}

	static void setNrCenturi(int nr)
	{
		CenturaBjj::nrCenturi = nr;
	}

	static int  getValoareTotala()
	{
		return valoareTotala;
	}

	static void setValoareTotala(int valoareTotala)
	{
		CenturaBjj::valoareTotala = valoareTotala;
	}

	int  getNrDungi()
	{
		return nrDungi;
	}

	Data*  getDungi()
	{
		return dungi;
	}

	void setDungi(int nrDungi, Data* dungi)
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
	}

	std::string getTaraFabricatie()
	{
		return taraFabricatie;
	}

	void setTaraFabricatie(std::string taraFabricatie)
	{
		this->taraFabricatie = taraFabricatie;
	}

	std::string getCuloare()
	{
		return culoare;
	}

	void setCuloare(std::string culoare)
	{
		this->culoare = culoare;
	}

	float getPret()
	{
		return (float)pret / 100;
	}

	void setPret(int pretNou)
	{
		pret = pretNou;
	}

	std::string getFirmaProductoare()
	{
		return firmaProducatoare;
	}

	void setFirmaProductoare(std::string firmaProducatoare)
	{
		this->firmaProducatoare = firmaProducatoare;
	}

	int getId()
	{
		return id;
	}

	CenturaBjj& operator=(const CenturaBjj& centura)
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

	bool operator==(const CenturaBjj& centura)
	{
		return this->culoare == centura.culoare;
	}

	operator std::string()
	{
		return this->culoare;
	}

	operator float()
	{
		return getPret();
	}

	operator int()
	{
		return pret;
	}

	friend std::istream& operator>>(std::istream& in, CenturaBjj& centura)
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
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, CenturaBjj& centura)
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

};

class GiBjj
{
private:
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



public:
	GiBjj() : id(100)
	{
		materialeTextie = NULL;
		nrMaterialeTextile = 0;
		culoare = "";
		taraFabricatie = "";
		pret = 0;
		firmaProducatoare = "";
	}

	GiBjj(GiBjj& gi) : id(gi.id)
	{
		setPret(gi.pret);
		setTaraFabricatie(gi.taraFabricatie);
		setMaterialeTextile(gi.nrMaterialeTextile, gi.materialeTextie);
		setCuloare(gi.culoare);
		setFirmaProductoare(gi.firmaProducatoare);
		this->nrGi++;
		this->valoareTotala += pret;
	}

	GiBjj(int id, int pret, std::string taraFabricatie, char** materialeTextie, int nrMaterialeTextile, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setMaterialeTextile(nrMaterialeTextile, materialeTextie);
		setCuloare(culoare);
		setFirmaProductoare(firmaProducatoare);
		this->nrGi++;
		this->valoareTotala += pret;
	}

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare, std::string firmaProducatoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setCuloare(culoare);
		setFirmaProductoare(firmaProducatoare);
		this->nrGi++;
		this->valoareTotala += pret;
	}

	GiBjj(int id, int pret, std::string taraFabricatie, std::string culoare) : id(id)
	{
		setPret(pret);
		setTaraFabricatie(taraFabricatie);
		setCuloare(culoare);
		setFirmaProductoare("Nu este cunoscuta");
		this->nrGi++;
		this->valoareTotala += pret;
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

	static std::string getSport()
	{
		return sport;
	}

	static void setSport(std::string sport)
	{
		GiBjj::sport = sport;
	}

	static int  getNrGi()
	{
		return nrGi;
	}

	static void setNrGi(int nr)
	{
		GiBjj::nrGi = nr;
	}

	static int  getValoareTotala()
	{
		return valoareTotala;
	}

	static void setValoareTotala(int valoareTotala)
	{
		GiBjj::valoareTotala = valoareTotala;
	}

	int  getNrMaterialeTextile()
	{
		return nrMaterialeTextile;
	}

	char** getMaterialeTextile()
	{
		return materialeTextie;
	}

	void setMaterialeTextile(int nrMaterialeTextile, char** materialeTextile)
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
			this->materialeTextie = new char*[nrMaterialeTextile];
			for (int i = 0; i < this->nrMaterialeTextile; i++)
			{
				this->materialeTextie[i] = new char[strlen(materialeTextile[i]) + 1];
				strcpy_s(this->materialeTextie[i], strlen(materialeTextile[i]) + 1, materialeTextile[i]);
			}
		}
	}

	std::string getTaraFabricatie()
	{
		return taraFabricatie;
	}

	void setTaraFabricatie(std::string taraFabricatie)
	{
		this->taraFabricatie = taraFabricatie;
	}

	std::string getCuloare()
	{
		return culoare;
	}

	void setCuloare(std::string culoare)
	{
		this->culoare = culoare;
	}

	float getPret()
	{
		return (float)pret/100;
	}

	void setPret(int pretNou)
	{
		pret = pretNou;
	}

	std::string getFirmaProductoare()
	{
		return firmaProducatoare;
	}

	void setFirmaProductoare(std::string firmaProducatoare)
	{
		this->firmaProducatoare = firmaProducatoare;
	}

	int getId()
	{
		return id;
	}

	GiBjj& operator=(const GiBjj& gi)
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

	char* operator[](int index)
	{
		return this->materialeTextie[index];
	}

	bool operator>(const GiBjj& gi)
	{
		return this->pret > gi.pret;
	}

	bool operator<(const GiBjj& gi)
	{
		return this->pret < gi.pret;
	}

	GiBjj operator++()
	{
		this->pret += 100;
		return *this;
	}

	GiBjj operator++(int i)
	{
		GiBjj gi(*this);
		gi.pret += 100;
		return gi;
	}

	friend bool validareId(GiBjj& gi);

	friend std::istream& operator>>(std::istream& in, GiBjj& gi)
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
			gi.materialeTextie = new char*[gi.nrMaterialeTextile];
			for (int i = 0; i < gi.nrMaterialeTextile; i++)
			{
				std::string aux;
				std::cout << "\nMaterial textil : ";
				in >> aux;
				gi.materialeTextie[i] = new char[aux.length() + 1];
				strcpy_s(gi.materialeTextie[i],aux.length() + 1,aux.c_str());
			}
		}


		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, GiBjj& gi)
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
};


int calculareDiferentePret(MingeFotbal &m1, MingeFotbal &m2)
{
	return m2.pret - m1.pret;
}

bool validareId(GiBjj& gi)
{
	return gi.id > 0;
}

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
	MingeFotbal::setSport("Fotbal");
	MingeFotbal::setNrMingiColectie(0);
	MingeFotbal::setValoareMingiColectie(0);

	CenturaBjj::setSport("Bjj");
	CenturaBjj::setNrCenturi(0);
	CenturaBjj::setValoareTotala(0);

	GiBjj::setSport("Bjj");
	GiBjj::setNrGi(0);
	GiBjj::setValoareTotala(0);
	
	/*char** semnaturi = new char* [2];
	semnaturi[0] = new char[strlen("Ronaldo") + 1];
	semnaturi[1] = new char[strlen("Messi") + 1];
	strcpy_s(semnaturi[0],strlen("Ronaldo")+1,"Ronaldo");
	strcpy_s(semnaturi[1], strlen("Messi") + 1, "Messi");

	MingeFotbal minge1(1,333,"Vietnam",semnaturi,2,"Fc. Barcelona", 1);
	MingeFotbal minge2(2, 333, "Vietnam", 0);
	MingeFotbal minge3(3, 3443, "Vietnam",semnaturi,2,1);
	MingeFotbal minge4(minge1);
	minge1.afisare();
	minge2.afisare();
	minge3.afisare();
	minge4.afisare();
	std::cout << "\n\n\nValoare medie mingi de colectie  : "<<MingeFotbal::valoareMedieMingiDeColectie();


	minge2.setPret(2500);
	minge2.setTaraFabricati("Brazil");
	minge2.setSemnaturi(2,semnaturi);
	minge2.setClubSportiv("FC Example");
	minge2.setObiectDeColetie(true);
	minge2.afisare();

	std::cout << minge2.getPret() << "\n";
	std::cout << minge2.getTaraFabricatie() << "\n";
	std::cout << minge2.getNrSemnaturi() << "\n";
	std::cout << minge2.getClubSportiv() << "\n";
	std::cout << minge2.getId() << "\n";

	delete[] semnaturi[0];
	delete[] semnaturi[1];
	delete[] semnaturi;

	minge1 = minge2;	
	std::cout << minge1;
	std::cin >> minge1;
	std::cout << minge1;

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
	CenturaBjj centura4(centura1);
	centura1.afisare();
	centura2.afisare();
	centura3.afisare();
	centura4.afisare();
	std::cout << "\n\n\nValoare medie centuri  : " << CenturaBjj::pretMediuCentura();

	centura2.setPret(4334);
	centura2.setTaraFabricatie("Franta");
	centura2.setDungi(2, date);
	centura2.setCuloare("alb");
	centura2.setFirmaProductoare("Tatami");

	centura1 = centura2;
	std::cout << std::endl << (std::string)centura1;
	std::cout << std::endl << (float)centura1;
	std::cout << std::endl <<(int)centura1;

	std::cout << centura2.getPret() << "\n";
	std::cout << centura2.getTaraFabricatie() << "\n";
	std::cout << centura2.getNrDungi() << "\n";
	std::cout << centura2.getCuloare() << "\n";
	std::cout << centura2.getFirmaProductoare() << "\n";
	std::cout << centura2.getId() << "\n";

	delete[] date;

	char** materiale = new char* [2];
	materiale[0] = new char[strlen("bumbac") + 1];
	materiale[1] = new char[strlen("elastan") + 1];
	strcpy_s(materiale[0], strlen("bumbac") + 1, "bumbac");
	strcpy_s(materiale[1], strlen("elastan") + 1, "elastan");

	GiBjj gi1(1,9999,"Pakistan" ,"albastru","Tatami");
	GiBjj gi2(2, 9900, "Pakistan",materiale,2, "negru", "Tatami");
	GiBjj gi3(3, 10000, "Spania","alb");
	GiBjj gi4(gi1);
	gi1.afisare();
	gi2.afisare();
	gi3.afisare();
	gi4.afisare();
	std::cout << "\n\n\nValoare medie gi  : " << GiBjj::pretMediuGi();

	gi2.setPret(4334);
	gi2.setTaraFabricatie("Franta");
	gi2.setMaterialeTextile(2,materiale);
	gi2.setCuloare("alb");
	gi2.setFirmaProductoare("Kings");

	std::cout << gi2.getPret() << "\n";
	std::cout << gi2.getTaraFabricatie() << "\n";
	std::cout << gi2.getNrMaterialeTextile() << "\n";
	std::cout << gi2.getCuloare() << "\n";
	std::cout << gi2.getFirmaProductoare() << "\n";
	std::cout << gi2.getId() << "\n";

	std::cout << "\nDiferenta pret :" << calculareDiferentePret(minge1, minge2);
	bool error =  !validareId(gi1);
	if (error)
		std::cout << "\nId-ul nu este valid";

	gi1 = gi2;
	if (gi1 > gi2)
		std::cout << "\nPretul gi1 este mai mare decat gi2 \n";
	else  if (gi1 < gi2)
		std::cout << "\nPretul gi2 este mai mare decat gi1 \n";
	else
		std::cout << "\nPretul este egal \n";

	gi1++;
	std::cout << "\n" << gi1.getPret();


	delete[] materiale[0];
	delete[] materiale[1];
	delete[] materiale;*/
	
	int n;
	
	std::cout << "\nNr mingii :";
	std::cin >> n;
	MingeFotbal* mingii = new MingeFotbal[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> mingii[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << mingii[i];
	}
	
	delete[] mingii;

	std::cout << "\nNr centuri :";
	std::cin >> n;
	CenturaBjj* centuri = new CenturaBjj[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> centuri[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << centuri[i];
	}

	delete[] centuri;

	std::cout << "\nNr gi-uri : ";
	std::cin >> n;
	GiBjj* giuri = new GiBjj[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> giuri[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << giuri[i];
	}
	
	std::cout << "\nNr linii si coloane gi matrice : ";
	std::cin >> n;
	GiBjj** matrix = new GiBjj * [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new GiBjj[n];
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j];;
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

}