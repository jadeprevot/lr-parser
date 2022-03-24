/******************************************************************************
						   Etat  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//----- Interface de la classe <Etat> (fichier Etat.h) ------
#ifndef ETAT_H
#define ETAT_H

//-------------------------------------------------------- Interfaces utilisées
#pragma once
#include <string>
#include "Automate.h"
using namespace std;

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
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

// Rôle de la classe <Etat>
//		Permet de gérer l'implémentation des différents états.
//-----------------------------------------------------------------------------
class Etat {
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat(string nom);
      virtual bool transition (Automate &automate, Symbole *s) =0;
      virtual ~Etat() {};

      //---------------------------------------------------- Attributs publics
      string nom; 

   //------------------------------------------------------------------- PROTEGE
   protected :
};

class Etat0 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat0() : Etat("E0") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat1 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat1() : Etat("E1") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat2 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat2() : Etat("E2") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat3 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat3() : Etat("E3") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat4 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat4() : Etat("E4") {}; 
      bool transition(Automate &automate, Symbole *s);
   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat5 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat5() : Etat("E5") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat6 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat6() : Etat("E6") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat7 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat7() : Etat("E7") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat8 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat8() : Etat("E8") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

class Etat9 : public Etat{
   //------------------------------------------------------------------ PUBLIC
   public:
      //-------------------------------------------------- Méthodes publiques
      Etat9() : Etat("E9") {}; 
      bool transition(Automate &automate, Symbole *s);

   //------------------------------------------------------------------- PROTEGE
   protected:
      //---------------------------------------------------- Attributs protégés
      int valeur;
};

//--------------------------- Autres définitions dépendantes de <Etat>

#endif // Etat_H