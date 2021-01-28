#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Singe
{
public:
	Singe(const std :: string pnom, const std :: string psigle, const int ppdv, const std :: size_t ppdc, 
		  const std :: size_t ppds, const std :: size_t parmure, const std :: size_t ppa)
	{
		pdv = ppdv;
		pdc = ppdc;
		pds = ppds;
		armure = parmure;
		pa = ppa;
		nom = pnom;
		sigle = psigle;
	};

	virtual ~Singe(){};

	virtual void combat(Singe& adversaire, int i) = 0;
	virtual void soin(Singe& a) = 0;
	virtual void soin(int luckSinge) = 0;
	virtual bool vie() = 0;
	virtual void resetPA() = 0;

	void setPDV(const int valeur){pdv = valeur;};
	void setPDC(const std :: size_t valeur){pdc = valeur;};
	void setPDS(const std :: size_t valeur){pds = valeur;};
	void setPDV(const std :: size_t valeur){pdv = valeur;};
	void setArmure(const std :: size_t valeur){armure = valeur;};
	void setSigle(const std :: string mot){sigle = mot;};
	void setPA(const std :: size_t valeur){pa = valeur;};

	int getPDV(){return pdv;};
	std :: size_t getPDC(){return pdc;};
	std :: size_t getPDS(){return pds;};
	std :: size_t getArmure(){return armure;};
	std :: size_t getPA(){return pa;};

	std :: string getNom(){return nom;};
	//std :: string getSigle(){return sigle;};

	friend std :: ostream& operator<<(std :: ostream& os, Singe& a)
	{
		os << "Stats " << a.nom << std :: endl;
	 	os << "PDV : " << a.pdv << std :: endl;
	 	os << "PDC : " << a.pdc << std :: endl;
		os << "PDS : " << a.pds << std :: endl;
	 	os << "Armure : " << a.armure << std :: endl;
	 	os << "Point d'action : " << a.pa << std :: endl;
	 	os << "Type : " << a.sigle;
	 	os << std :: endl;

 	return os;
 	};

protected:
	std :: string nom;
	std :: string sigle;

	int pdv;
	std :: size_t pdc;
	std :: size_t pds;
	std :: size_t armure;
	std :: size_t pa;
};