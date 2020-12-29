#pragma once
#include <iostream>
#include <string>

class Singe
{
public:
	Singe();
	~Singe();

	void combat(Singe& adversaire);
	void soin(Singe& a);
	void soin();
	bool vie() const;
	void resetPA();


	int getPDV(){return this -> pdv;};
	int getPDC(){return this -> pdc;};
	int getPDS(){return this -> pds;};
	int getArmure(){return this -> armure;};
	int getPA(){return this -> pa;};

	std :: string getNom(){return this -> nom;};
	std :: string getSigle(){return this -> sigle;};

	friend std :: ostream& operator<<(std :: ostream& os, Singe& a);


protected:
	std :: string nom;
	std :: string sigle;

	int pdv;
	int pdc;
	int pds;
	int armure;
	int pa;


};