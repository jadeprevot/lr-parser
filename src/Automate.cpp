/******************************************************************************
						   Automate  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//--- Réalisation de la classe <Automate> (fichier Automate.cpp) ----

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
#include <iostream>

//----------------------------------------------------------- Include personnel
#include "Etat.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
Automate::Automate(string flux) 
// Algorithme :
//		Aucun.
{
  this->lexer = new Lexer(flux);
  Etat0 *depart = new Etat0();
  pileEtat.push(depart);
} //----- Fin de Automate


void Automate::run() 
// Algorithme :
//		Aucun.
{
  int i=10000000; // compteur permetant de lire dans le flux
  Symbole *s;
  while (i>0) {
        s = lexer->Consulter();
        bool nextState = pileEtat.top()->transition(*this, s);
        i--; 
        if((*s==FIN && nextState)|| *pileSymbole.top()==ERREUR ){ // si on constate une Erreur dans l'expression
            i=0; // on sort de la boucle
            }
        if(nextState) lexer->Avancer(); 
      }

      if (*pileSymbole.top() != ERREUR) { // si tout est bon
        int resultat = pileSymbole.top()->getValeur();
        cout << "Expression correcte" << endl << "Résultat : " << resultat << endl;
        } 

      else {
        cout << "Syntaxe non reconnue : caractère invalide" << endl;
        }
} //----- Fin de run

void Automate::decalage(Symbole *s, Etat *e) 
// Algorithme :
//		Aucun.
{
    pileSymbole.push(s);
    pileEtat.push(e);
} //----- Fin de decalage

void Automate::reduction(int n, Symbole *s)
// Algorithme :
//		Aucun.
{
    for (int i =0; i<n; i++) {
        delete(pileEtat.top());
        pileEtat.pop();
    }
    pileEtat.top()->transition(*this, s);
} //----- Fin de reduction

Symbole * Automate::getTopSymbole() 
// Algorithme :
//		Aucun.
{
    Symbole* s = pileSymbole.top();
    return s;
} //----- Fin de getTopSymbole

void Automate::popSymbole() 
// Algorithme :
//		Aucun.
{
    delete(pileSymbole.top());
    pileSymbole.pop();
} //----- Fin de popSymbole

void Automate::popAndDestroySymbole() 
// Algorithme :
//		Aucun.
{
    pileSymbole.pop();
} //----- Fin de popAndDestroySymbole