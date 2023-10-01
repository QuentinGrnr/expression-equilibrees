/****************************************/
/* Auteur : S. Gueye			*/
/* Date dernière maj : 18/09/2019	*/
/****************************************/

#include<iostream>
#include <fstream>
#include <stack>

using namespace std;

#include "expression.h"

int main(int argc,char** argv)
{
	expression expr;

	/* Le programme principal a un argument d'entrée	*/
	/* Le nom du fichier de test			*/
	if(argc < 2)
		cout << "Nombre d'arguments insuffisants" << endl;
	else{
		if(expr.equilibre(argv[1]))
			cout << "0K" << endl;
		else
			cout << "KO" << endl;
	}

	return(1);
}