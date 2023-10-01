/****************************************/
/* Auteur : S. Gueye			*/
/* Date dernière maj : 19/09/2019	*/
/****************************************/

#include<iostream>
#include <fstream>
#include <stack>

using namespace std;

#include "expression.h"
/****************************************/
/* Objectif : Vérifier qu'une expression lue dans un fichier nommé
/* "filename" est équilibrée ou non
/* Entrées : filemane
/* Sorties  : vrai si elle est équilibrée, faux sinon.
/* Complexité : 0(n) où n est le nombre de caractères de l'expression
/****************************************/

bool expression::equilibre(char* filename)
{
    
    /*
    Indication sur la lecture de fichier caractère par caractère
    ***********************************************************
    L'ouverture d'un fichier de nom "filename" en lecture peut se faire comme suit : 
    file.open(filename, std::ifstream::in);
    
    L'instruction place un "curseur" en début du fichier. On peut alors le lire caracère par caractère.
    
    Si "c" est de type char : char c;
    alors file >> c envoie dans "c" le caractère où se trouve le curseur, puis celui-ci passe au caractère suivant.
    
    La lecture de tous les caractères se fait comme suit :
    
    while(!file.eof())
        file >> c;
        
    Ces instructions ont la signification suivante. Tant que l'on a pas atte la fin fichier, lire le caractère courant est le mettre dans c.
    eof() est une méthode de la classe ifstream indiquant la fin du fichier.
    
    La fermeture après utilisation du fichier se fait par l'appel :
    file.close()
    */

    file.open(filename, std::ifstream::in);
    char c;
    file >> c;

    while(!file.eof()){
        if(c == '(' || c == '[' || c == '{') {
            pile.push(c);
            } else if(c == ')' || c == ']' || c == '}') {
            if(pile.empty()) {
                return(false);
                } else {
                    char top = pile.top();
                    if((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                        pile.pop();
                    } else {
                        return(false);
                    }
                }
        }
        file >> c;
    }
    return(true);
}