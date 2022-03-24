/******************************************************************************
						   lexer  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//----- Interface de la classe <lexer> (fichier lexer.h) ------
#ifndef LEXER_H
#define LEXER_H

//-------------------------------------------------------- Interfaces utilisées
#pragma once
#include <string>
#include "symbole.h"
using namespace std;

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <lexer>
//		Joue le rôle de la tête de lecture.
//-----------------------------------------------------------------------------
class Lexer {
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }
      Symbole * Consulter();	
      void Avancer();

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Méthodes protégées

      //---------------------------------------------------- Attributs protégés
      string flux;
      int tete;
      Symbole * tampon;
};

//--------------------------- Autres définitions dépendantes de <lexer>

#endif // lexer_H