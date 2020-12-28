#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

#include "Joueur.hh"

using namespace std;

Joueur :: Joueur()
{
  int val = 10;
  int valup = 10 ;
  int flag = 0;
  int erreur = 0;

  cout << "Choix du nom du joueur" << endl;
  cout << "Player : Entrez votre nom : ";
  cin >> name1;
  cout << endl;
  cout << "Player se nomme : " << name1 << endl;
  cout << endl;
  cout << "Fin du choix des noms" << endl;

  cout << endl;

  cout << "Choix du nombre de singes :" << endl;
  cout << "Valeur singe : 1" << endl;
  cout << "Valeur singe up : 3" << endl;
  cout << "La somme doit être inférieure à 10" << endl;

  while(flag == 0)
  {
    if(val > 5)
    {
      cout << "Nombre de Singes Normaux (MAX 5) : ";
      cin >> nbSinges;
      val = nbSinges;
      if(val > 5)
      {
        cout << "Erreur vous allez devoir recommencer" << endl;
        cout << endl;
        erreur = 1;
      }
      else
      {
        cout << "Vous avez choisi " << nbSinges << " singes normaux" << endl;
      }
    }
    if(valup > 3)
    {
      cout << "Nombre de Singes Up (MAX 3) : ";
      cin >> nbSingesUp;
      valup = nbSingesUp;
      if(valup > 3)
      {
        cout << "Erreur vous allez devoir recommencer" << endl;
        cout << endl;
        erreur = 1;
      }
      else
      {
        cout << "Vous avez choisi " << nbSingesUp << " singes normaux" << endl;
      }
    }
    if(erreur == 1||3*valup + val > 10||valup + val == 0)
    {
      cout << "Erreur vous avez choisi trop de singes ou aucuns" << endl;
      cout << "Vous allez devoir recommencer" << endl;
      cout << endl;
      val = 10;
      valup = 10;
      erreur = 0;
    }
    else
    {
      flag = 1;
    }
  }
  cout << "Fin de la création du joueur" << endl;
  cout << endl;
}

Joueur :: ~Joueur()
{
  cout << "~Joueur()" << endl;
}
