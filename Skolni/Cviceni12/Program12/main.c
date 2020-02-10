/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...


//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##
  // Pomucka pro ladeni. Pokud to nepouzijete, klidne to smazte.

  // Po odkomentovani se nebudou tisknout ladici zpravy.
  // #define NDEBUG

  // Prikaz dprintf pro tisk ladicich zprav. Funguje stejne jako printf,
  // ale jde jej globalne vypnout odkomentovanim definice symbolu NDEBUG.
  // Vhodny pro povidani s uzivatelem v prubehu ladeni.
  #ifdef NDEBUG
    #define dprintf(...)
  #else
    #define dprintf(...) printf(__VA_ARGS__)
  #endif //NDEBUG
//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##


// zkratka
typedef unsigned int uint;

int nacteniPole(int pole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    scanf("%d", &pole[i]);
  }
}


void vypisPole(int pole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    printf("%d, ", pole[i]);
  }
  printf("\n");
}


void vypisPoleCarky(int pole[], int velikostPole)
{

  for(int i = 0; i < velikostPole-1; i++)
  {
    printf("%d, ", pole[i]);
  }

  printf("%d\n", pole[velikostPole-1]);

}


void ukol1a2()
{
  int prvku = 5;

  int pole[prvku];

  nacteniPole(pole, prvku);
  vypisPole(pole, prvku);
  vypisPoleCarky(pole, prvku);
}


void vynasobPole(int vstupPole[], int vystupPole[], int velikostPole, int nasobek)
{
  for(int i = 0; i < velikostPole; i++)
  {
    vystupPole[i] = vstupPole[i] * nasobek;
  }
  printf("\n");
}



void ukol3()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];
  int kopiePole[prvku];

  printf("Zadej %d prvku\n", prvku);
  nacteniPole(hlavniPole, prvku);

  int nasobek = 5;
  printf("Vsechno vynasobim cislem %d\n", nasobek);
  vynasobPole(hlavniPole, kopiePole, prvku, 5);

  printf("Vynasobene pole\n");
  vypisPoleCarky(kopiePole, prvku);
}




void zdvojPole(int vstupPole[], int vystupPole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    vystupPole[i] = vstupPole[i];
    vystupPole[i+velikostPole] = vstupPole[i];
  }
}


void ukol4()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];
  int kopiePole[prvku*2];

  printf("Zadej %d prvku\n", prvku);
  nacteniPole(hlavniPole, prvku);

  printf("Zdvojiji pole\n");
  zdvojPole(hlavniPole, kopiePole, prvku);

  printf("Zdvojene pole\n");
  vypisPoleCarky(kopiePole, prvku*2);
}


void opacnePoradiPole(int vstupPole[], int vystupPole[], int velikostPole)
{
  for(int i = 0; i < velikostPole; i++)
  {
    vystupPole[(velikostPole-i-1)] = vstupPole[i];
  }
}


void ukol5()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];
  int kopiePole[prvku];

  printf("Zadej %d prvku\n", prvku);
  nacteniPole(hlavniPole, prvku);

  printf("Otaceni pole\n");
  opacnePoradiPole(hlavniPole, kopiePole, prvku);

  printf("Otocene pole\n");
  vypisPoleCarky(kopiePole, prvku);
}

int minPole(int vstupPole[], int velikostPole)
{
  int min = vstupPole[0];
  int index = 0;
  for(int i = 1; i < velikostPole; i++)
  {
    if(vstupPole[i]<min)
    {
      min = vstupPole[i];
      index = i;
    }
  }
  return min; //vracim max cislo nebo jeho index
}

int maxPole(int vstupPole[], int velikostPole)
{
  int max = vstupPole[0];
  int index = 0;
  for(int i = 1; i < velikostPole; i++)
  {
    if(vstupPole[i]>max)
    {
      max = vstupPole[i];
      index = i;
    }
  }
  return max; //vracim max cislo nebo jeho index
}

void ukol6()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];

  printf("Zadej %d prvku\n", prvku);
  nacteniPole(hlavniPole, prvku);

  printf("Hledani nejvetsiho/nejmensiho cisla\n");
  int min;
  int max;
  min = minPole(hlavniPole, prvku);
  max = maxPole(hlavniPole, prvku);

  printf("Nejmensi cislo z pole je %d\n", min);
  printf("Nejvetsi cislo z pole je %d\n", max);
}


int sumPole(int vstupPole[], int velikostPole)
{
  int sum = 0;
  for(int i = 0; i < velikostPole; i++)
  {
    sum += vstupPole[i];
  }
  return sum;
}


void ukol7()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];

  printf("Zadej %d prvku\n", prvku);
  nacteniPole(hlavniPole, prvku);

  printf("Vypocet sumy\n");
  int sum;
  sum = sumPole(hlavniPole, prvku);

  printf("Soucet vsech prvku v poli je %d\n", sum);
}


void fibonaciPole(int pole[], int velikostPole)
{
  pole[0] = 1;
  pole[1] = 1;

  for(int i = 2; i < velikostPole; i++)
  {
    pole[i] = pole[i-1] + pole[i-2];
  }
}


void ukol8()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];

  printf("Zadej %d prvku\n", prvku);

  printf("Vypocet fibonaciho\n");
  fibonaciPole(hlavniPole, prvku);

  printf("Vypis pole\n");
  vypisPoleCarky(hlavniPole, prvku);
}


void pascaluvTrojuhelnikPole(int pole[], int velikostPole)
{
  pole[0] = 1;
  pole[velikostPole-1] = 1;


  for(int i = velikostPole-2; i >= 1; i--)
  {
    vypisPole(pole, velikostPole);
    printf("pole i: %d\n",i);
    pole[i] = pole[i] + pole[i-1];
  }
}


void ukol9()
{
  int prvku;
  printf("Kolik mam nacist prvku?\n");
  scanf("%d", &prvku);

  int hlavniPole[prvku];

  printf("Zadej %d prvku\n", prvku);

  printf("Vypocet pascala\n");
  pascaluvTrojuhelnikPole(hlavniPole, prvku);

  printf("Vypis pole\n");
  vypisPoleCarky(hlavniPole, prvku);
}




int main(int argc, char *argv[])
{
  //ukol1a2();  //nacteni a vypis
  //ukol3();    //vynasobeni pole cislem
  //ukol4();    //zdvoj cisla
  //ukol5();    //otoceni poradi
  //ukol6();    //min a max
  //ukol7();    //suma
  //ukol8();    //fibonaci
  ukol9();    //pascaluv trojuhelnik
  return 0;
}
