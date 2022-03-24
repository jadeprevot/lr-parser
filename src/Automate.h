/******************************************************************************
						   Automate  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//----- Interface de la classe <Automate> (fichier Automate.h) ------
#ifndef AUTOMATE_H
#define AUTOMATE_H

//-------------------------------------------------------- Interfaces utilisées
#pragma once
#include <string>
#include <stack>
#include "lexer.h"
#include "symbole.h"
using namespace std;

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
class Etat;
class Etat0;
class Etat1;
class Etat2;
class Etat3;
class Etat4;
class Etat5;
class Etat6;
class Etat7;
class Etat8;
class Etat9;

// Rôle de la classe <Automate>
//		Permet de gérer le comportement de l'analyseur.
//-----------------------------------------------------------------------------
class Automate {
    //------------------------------------------------------------------ PUBLIC
    public:
        //-------------------------------------------------- Méthodes publiques
        Automate(string flux);	
        void decalage(Symbole *s, Etat *e);
        void reduction(int n, Symbole *s);
        void run ();
        Symbole * getTopSymbole();
        void popSymbole();
        void popAndDestroySymbole();

    //------------------------------------------------------------------- PROTEGE
    protected:
        //---------------------------------------------------- Méthodes protégées

        //---------------------------------------------------- Attributs protégés
        stack<Symbole*> pileSymbole;
        stack<Etat*> pileEtat;
        Lexer * lexer;

};

//--------------------------- Autres définitions dépendantes de <Automate>

#endif // Automate_H