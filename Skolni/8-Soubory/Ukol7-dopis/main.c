/*
 * Projekt:
 * Autor: Jakub Andrysek
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
 #include <stdbool.h> // pro praci s typem bool a konstantami true a false

typedef struct
{
	char aktualni;
	char minus1;
	char minus2;
	bool tiskniAktualni;
	bool tiskniMinus1;
	bool tiskniMinus2;

}ZNAKY;

void Dopis(FILE* vstup, FILE* vystup)
{
	ZNAKY znak;
	znak.minus1 = NULL;
	znak.tiskniAktualni = true;
	znak.tiskniMinus1 = true;

	while(fscanf(vstup, "%c", &znak.aktualni) == 1)\
	{
		znak.tiskniAktualni = true;

		if(znak.aktualni == 'e' && (znak.minus1 == 'n' || znak.minus1 == 'N'))
		{
			if(znak.minus2 == ' ')
			{
				printf(" ");
				fprintf(vystup, " ");
				znak.tiskniAktualni = false;
				znak.tiskniMinus1 = false;
			}
			else if(znak.minus2 == '\n')
			{
				printf("\n");
				fprintf(vystup, "\n");
				znak.tiskniAktualni = false;
				znak.tiskniMinus1 = false;
			}
			else
			{
				dprintf("%c", znak.minus2);
				fprintf(vystup, "%c", znak.minus2);
			}

		}
		else
		{
			if(znak.minus2 != NULL && znak.tiskniMinus2)
			{
				dprintf("%c", znak.minus2);
				fprintf(vystup, "%c", znak.minus2);
			}
		}

		znak.minus2 = znak.minus1;
		znak.minus1 = znak.aktualni;

		znak.tiskniMinus2 = znak.tiskniMinus1;
		znak.tiskniMinus1 = znak.tiskniAktualni;
	}

	dprintf("%c%c", znak.minus1, znak.aktualni);
	fprintf(vystup, "%c%c", znak.minus1, znak.aktualni);
}


int main(void)
{
  FILE* vstup = fopen("Vstup.txt", "r");
  FILE* vystup = fopen("Vystup.txt", "w");

  if(vstup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  if(vystup == NULL)
  {
    printf("Chyba otevreni");
    return 1;
  }

  Dopis(vstup, vystup);

  fclose(vstup);
  fclose(vystup);


  return 0;
}
