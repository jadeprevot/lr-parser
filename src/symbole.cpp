/******************************************************************************
						   symbole  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//--- Réalisation de la classe <symbole> (fichier symbole.cpp) ----

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
#include <iostream>

//----------------------------------------------------------- Include personnel
#include "symbole.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
void Symbole::Affiche() 
// Algorithme :
//		Aucun.
{
   cout<<Etiquettes[ident];
} //----- Fin de Affiche

void Entier::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
} //----- Fin de Affiche

int Entier::getValeur() 
// Algorithme :
//		Aucun.
{ 
   return valeur; 
} //----- Fin de getValeur


int Symbole::getValeur() 
// Algorithme :
//		Aucun.
{ 
   return -1; 
} //----- Fin de getValeur

int Expression::getValeur() 
// Algorithme :
//		Aucun.
{ 
   return valeur; 
} //----- Fin de getValeur

void OpenPar::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void ClosePar::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void Plus::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void Mult::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void Fin::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void Erreur::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche

void Expression::Affiche() 
// Algorithme :
//		Aucun.
{
   Symbole::Affiche();
} //----- Fin de Affiche