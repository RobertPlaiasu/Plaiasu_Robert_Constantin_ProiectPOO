#include <iostream>
#include <string>
#include <fstream>
#include "MingeFotbal.h"
#include "Data.h"
#include "CenturaBjj.h"
#include "GiBjj.h"
#include "EchipamentBjj.h"
// Am ales tema Sport - Plaiasu Robert


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
	
	/*
	char** semnaturi = new char* [2];
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

	std::cout << "\n";
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
	delete[] materiale;
	*/
    // faza 4
	
	/*
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
	*/
	

	// faza 5
	
	GiBjj gi;
	GiBjj gi1(1, 22, "Vietnam", "Negru");
	CenturaBjj centura;
	CenturaBjj centura1(1,22,"Vietnam", "Negru");
	EchipamentBjj echipament1;
	EchipamentBjj echipament2(1,centura,gi,"echipament");
	EchipamentBjj echipament3(echipament2);
	echipament3.setCentura(centura1);
	echipament3.setGi(gi1);
	echipament3.setProprietar("Nou proprietar");
	std::cout << echipament1;
	std::cout << echipament2;
	std::cout << echipament3;

	echipament2 = echipament3;

	
	std::cout<<"\n\n\n" << echipament2;

	std::cout << echipament2.getProprietar();
	std::cout << echipament2.getGi();
	std::cout << echipament2.getCentura();
	
	

	// faza 6

	
}