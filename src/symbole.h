/******************************************************************************
						   symbole  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//----- Interface de la classe <ssymbole> (fichier symbole.h) ------
#ifndef SYMBOLE_H
#define SYMBOLE_H

//-------------------------------------------------------- Interfaces utilisées
#pragma once
#include <string>
using namespace std;

//------------------------------------------------------------------ Constantes
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" , "EXPR"};

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <symbole>
//		Permet de gérer l'implémentation des différents symboles.
//-----------------------------------------------------------------------------
class Symbole {
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      virtual int getValeur ();

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Méthodes protégées

      //---------------------------------------------------- Attributs protégés
      int ident;
};

class Entier : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();

      //---------------------------------------------------- Attributs publics
      int getValeur();

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Méthodes protégées

      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class OpenPar : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      OpenPar () : Symbole(OPENPAR) {}
      ~OpenPar() {}
      virtual void Affiche ();
};

class ClosePar : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      ClosePar () : Symbole(CLOSEPAR) {}
      ~ClosePar() {}
      virtual void Affiche ();
};

class Plus : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      Plus () : Symbole(PLUS) {}
      ~Plus() {}
      virtual void Affiche ();
};

class Mult : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      Mult () : Symbole(MULT) { }
      ~Mult() { }
      virtual void Affiche ();
};


class Fin : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      Fin () : Symbole(FIN) {}
      ~Fin() {}
      virtual void Affiche ();
};

class Erreur : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public :
      //-------------------------------------------------- Méthodes publiques
      Erreur () : Symbole(ERREUR) {}
      ~Erreur() {}
      virtual void Affiche ();
};


class Expression : public Symbole {
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Expression(int val) : Symbole(EXPR), valeur(val) {}
      ~Expression() {}
      virtual void Affiche();

      //---------------------------------------------------- Attributs publics
      int getValeur();

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Méthodes protégées

      //---------------------------------------------------- Attributs protégés
      int valeur;
};

//--------------------------- Autres définitions dépendantes de <symbole>

#endif // symbole_H