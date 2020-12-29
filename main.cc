#include <iostream>
#include <string>

#include "Singe.hh"
#include "Gorille.hh"
#include "Macaque.hh"
#include "Joueur.hh"

using namespace std;

int main()
{
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Singe" << endl;
	cout << endl;
	Singe a;
	Singe b;
	cout << b << endl;
	a.combat(b);
	cout << b << endl;
	b.soin(b);
	cout << b << endl;
	cout << "Fin Test pour la classe Singe" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Gorille" << endl;
	cout << endl;
	Gorille c;
	Gorille d;
	cout << d << endl;
	c.combat(d);
	cout << c << endl;
	d.soin(d);
	cout << d << endl;
	cout << "Fin Test pour la classe Gorille" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Macaque" << endl;
	cout << endl;
	Macaque e;
	Macaque f;
	cout << f << endl;
	e.combat(f);
	cout << f << endl;
	f.soin(f);
	cout << f << endl;
	cout << "Fin Test pour la classe Macaque" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test Macaque attaque Gorille" << endl;
	cout << endl;
	Gorille g;
	Macaque h;
	cout << g << endl;
	cout << h << endl;
	h.combat(g);
	cout << g << endl;
	g.soin();
	cout << g << endl;
	cout << "Fin Test Macaque attaque Gorille" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test class Joueur" << endl;
	cout << endl;
	Joueur i;
	cout << i << endl;
	cout << "Fin Test class Joueur" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;





	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Déconstructeurs" << endl;
	return 0;

}