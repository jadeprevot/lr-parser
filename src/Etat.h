#ifndef ETAT_H
#define ETAT_H

#pragma once
#include <string>
#include "Automate.h"
using namespace std;

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

class Etat {
   public:
      Etat(string nom);
      virtual bool transition (Automate &automate, Symbole *s) =0;
      virtual ~Etat() {};
      string nom; 
   protected :
};

class Etat0 : public Etat{
   public:
      Etat0() : Etat("E0") {}; 
      bool transition(Automate &automate, Symbole *s);


   protected:
      int valeur;
};

class Etat1 : public Etat{
   public:
      Etat1() : Etat("E1") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat2 : public Etat{
   public:
      Etat2() : Etat("E2") {}; 
      bool transition(Automate &automate, Symbole *s);


   protected:
      int valeur;
};

class Etat3 : public Etat{
   public:
      Etat3() : Etat("E3") {}; 
      bool transition(Automate &automate, Symbole *s);


   protected:
      int valeur;
};

class Etat4 : public Etat{
   public:
      Etat4() : Etat("E4") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat5 : public Etat{
   public:
      Etat5() : Etat("E5") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat6 : public Etat{
   public:
      Etat6() : Etat("E6") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat7 : public Etat{
   public:
      Etat7() : Etat("E7") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat8 : public Etat{
   public:
      Etat8() : Etat("E8") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

class Etat9 : public Etat{
   public:
      Etat9() : Etat("E9") {}; 
      bool transition(Automate &automate, Symbole *s);

   protected:
      int valeur;
};

#endif // Etat_H