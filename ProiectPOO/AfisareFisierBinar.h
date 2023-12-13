#pragma once
#include <iostream>

class AfisareFisierBinar
{
public:
	virtual void afisareFisierBinar(std::ofstream& out, AfisareFisierBinar& afisare) = 0;
};