/******************************************************************************
						   lexer  -  description
							 -------------------
début	   : 16.02.2022
copyright   : (C) 2022 par Adam Chellaoui & Jade Prévôt
e-mail	  : adam.chellaoui@insa-lyon.fr / jade.prevot@insa-lyon.fr
******************************************************************************/

//--- Réalisation de la classe <lexer> (fichier lexer.cpp) ----

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système

//----------------------------------------------------------- Include personnel
#include "lexer.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
Symbole * Lexer::Consulter() 
// Algorithme :
//		Aucun.
{
   if (!tampon) {

      if (tete==flux.length())
         tampon = new Symbole(FIN);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }
               else {
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
} //----- Fin de Consulter

void Lexer::Avancer() 
// Algorithme :
//		Aucun.
{
   tampon = nullptr;
} //----- Fin de Avancer