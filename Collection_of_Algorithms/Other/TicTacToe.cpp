#include "stdafx.h"
#include <iostream>
using namespace std;

void afficher(char grille[][3]);
bool EstCordonneValide(char grille[][3] , int x , int y);
bool EstPartieGagne(char grille[][3]);

int main()
{
	int numeroJoueur = 1;
	int ligneCase = 0;
	int colonneCase = 0;
	int compteur = 0;

	char grille[3][3];

	for (int i(0); i < 3; i++) {
		for (int j(0); j < 3; j++) {
			grille[i][j] = '_';
		}
	}

	do {

		system("cls"); //Clear la console
		compteur++;
		afficher(grille);
		cout << "Tour du Joueur " << numeroJoueur << " : " << endl;
		do {
			cout << "Choisissez la ligne de la case   : ";
			cin >> ligneCase;
			cout << "Choisissez la colonne de la case : ";
			cin >> colonneCase;

		} while (!EstCordonneValide(grille,ligneCase,colonneCase));

		if (numeroJoueur == 1)
			grille[ligneCase-1][colonneCase-1] = 'x';
		else
			grille[ligneCase-1][colonneCase-1] = 'o';
		

		numeroJoueur = numeroJoueur % 2 + 1;

		
	} while (!EstPartieGagne(grille) && compteur != 9);
	system("cls");

	afficher(grille);

	numeroJoueur = numeroJoueur % 2 + 1;
	if(EstPartieGagne(grille))
		cout << "Le Joueur " << numeroJoueur << " a gagne la partie " << endl << endl;
	else
		cout << "La partie s'est termine a egalite !" << endl <<endl ;
	
	

    return 0;
}

void afficher(char grille[][3])
{
	for (int i(0); i < 3; i++) {
		for (int j(0); j < 3; j++) {
			if (grille[i][j] == '_' && i == 2)
				cout << " ";
			else
				cout << grille[i][j];
			if (j != 2)
				cout << "|";
			else
				cout << endl;
		}
	}
	cout << endl;
}

bool EstCordonneValide(char grille[][3], int x, int y)
{
	if (x <= 3 && x >= 1 && y <= 3 && y >= 1) {
		if (grille[x - 1][y - 1] != '_')
			cout << "Case deja pleine !  " << endl << endl;
		else
			return true;
	}
	else
		cout << "Coordonees Invalide ! " << endl<< endl;

	return false;
}

bool EstPartieGagne(char grille[][3]) 
{
	if (grille[0][0] == grille[0][1] && grille[0][0] == grille[0][2] && grille[0][0] != '_')		//Ligne 1 
		return  true;
	else if (grille[1][0] == grille[1][1] && grille[1][0] == grille[1][2] && grille[1][0] != '_') //Ligne 2 
		return  true;
	else if (grille[2][0] == grille[2][1] && grille[2][0] == grille[2][2] && grille[2][0] != '_') //Ligne 3 
		return  true;
	else if (grille[0][0] == grille[1][0] && grille[0][0] == grille[2][0] && grille[0][0] != '_') // colonne 1 
		return  true;
	else if (grille[0][1] == grille[1][1] && grille[0][1] == grille[2][1] && grille[0][1] != '_')  // colonne 2
		return  true;
	else if (grille[0][2] == grille[1][2] && grille[0][2] == grille[2][2] && grille[0][2] != '_')  // colonne 3 
		return  true;
	else if (grille[0][0] == grille[1][1] && grille[0][0] == grille[2][2] && grille[0][0] != '_') // Diagonale 1 
		return  true;
	else if (grille[0][2] == grille[1][1] && grille[0][2] == grille[2][0] && grille[0][2] != '_') // Diagonale 2 
		return  true;

	return false;
}