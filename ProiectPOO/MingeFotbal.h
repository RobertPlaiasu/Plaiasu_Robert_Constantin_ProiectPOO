#pragma once
#include <iostream>
#include <fstream>
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

	MingeFotbal();

	MingeFotbal(const MingeFotbal& minge);

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, std::string clubSportiv, bool obiectDeColectie);
	

	MingeFotbal(int id, int pret, std::string taraFabricatie, char** semnaturi, int nrSemnaturi, bool obiectDeColectie); 
	

	MingeFotbal(int id, int pret, std::string taraFabricatie, bool obiectDeColectie);

	~MingeFotbal();

	static float valoareMedieMingiDeColectie();
	void afisare();

	static std::string  getSport();

	static void setSport(std::string sport);

	static int  getNrMingiColectie();

	static void setNrMingiColectie(int nr);

	static int  getValoareMingiColectie();
	static void setValoareMingiColectie(int nr);

	int getNrSemnaturi();

	char** getSemnaturi();
	void setSemnaturi(int nrSemnaturi, char** semnaturi);

	std::string getTaraFabricatie();

	void setTaraFabricati(std::string taraFabricatie);
	float getPret();

	void setPret(int pretNou);

	std::string getClubSportiv();
	void setClubSportiv(std::string clubSportiv);

	bool getObiectDeColetie();

	void setObiectDeColetie(bool obiectDeColectie);
	int getId();

	MingeFotbal& operator=(const MingeFotbal& minge); 
	char* operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, MingeFotbal& minge);

	friend std::ofstream& operator<<(std::ofstream& out, MingeFotbal& minge);

	friend std::istream& operator>>(std::istream& in, MingeFotbal& minge);

	friend int calculareDiferentePret(MingeFotbal& m1, MingeFotbal& m2);
};

