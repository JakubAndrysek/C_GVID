/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem


int nacteniSouboruDoPole(FILE* vstup, int pole[])
{
	int i = 0;
	while(fscanf(vstup, "%d ", &pole[i])==1)
	{
		i++;
	}

	return i;
}

int zapisPoleDoSouboru(FILE* vystup, int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%d ", pole[i]);
		fprintf(vystup,"%d ", pole[i]);
	}
}

int vypisPole(int pole[], int pocet)
{
	for(int i = 0; i<pocet; i++)
	{
		printf("%2d ", pole[i]);
	}
}

void sort(int pole[], int pocet)
{
	int min, i, l;

	for(i = 0; i<pocet-2; i++)
	{
		min = i;

		for(l = i+1; l<pocet; l++)
		{
			if(pole[min] >pole[l])
			{
				min = l;
			}
		}
		int pomMin = pole[min];
		pole[min] = pole[i];
		pole[i] = pomMin;
	}
}


int main(void)
{

	FILE* vstup = fopen("vstup.txt", "r");
	FILE* vystup = fopen("vystup.txt", "w");

	if(vstup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	if(vystup == NULL)
	{
		printf("Soubor nelze otevrit");
		return 1;
	}

	int pole[1010];
	int pocet;


	pocet = nacteniSouboruDoPole(vstup, pole);

	if(pocet<2)
	{
		printf("Molo prvku v souboru");
		return 1;
	}

	sort(pole, pocet);

//	vypisPole(pole, pocet);

	zapisPoleDoSouboru(vystup, pole, pocet);
	printf("\n\nDokonceno");

	return 0;
}
