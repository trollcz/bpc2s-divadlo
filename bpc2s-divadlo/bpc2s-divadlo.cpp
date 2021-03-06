// bpc2s-divadlo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//printf("Den: ");
//scanf_s("%d", &den);
void onPridej(uzivatel **zaznam) {
	char jmeno[VELIKOST];
	char prijmeni[VELIKOST];
	int ID, pocetrezervaci;
	int rezervace[2][5];
	system("cls");
	getchar();
	printf("ID: ");
	scanf_s("%d", &ID);
	printf("Prijmeni: ");
	getchar();
	scanf_s("%[^\n]", prijmeni, VELIKOST);
	printf("Jmeno: ");
	getchar();
	scanf_s("%[^\n]", jmeno, VELIKOST);
	printf("Kolik chcete rezervaci: ");
	scanf_s("%d", &pocetrezervaci);
	for (int j = 0; j < pocetrezervaci; j++) {
		printf("Rada: ");
		scanf_s("%d", &rezervace[0][j]);
		printf("Misto: ");
		scanf_s("%d", &rezervace[1][j]);
		map[rezervace[0][j]][rezervace[1][j]] = 1;
	}
	pridej(zaznam,ID, prijmeni, jmeno, pocetrezervaci,rezervace);
	system("cls");
}
void onEdit(uzivatel **zaznamy) {
	char jmeno[VELIKOST];
	char prijmeni[VELIKOST];
	int ID, pocetrezervaci;
	int rezervace[2][5];
	getchar();
	system("cls");
	printf("ID: ");
	scanf_s("%d", &ID);
	uzivatel *b = vratzaznam(*zaznamy, ID);
	system("cls");
	if (b != NULL) {
		tiskradku(b);
	}
	else
	{
		tiskoddelovace();
		printf("Zaznam nenalezen\n");
		tiskoddelovace();
		return;
	}
	system("cls");
	getchar();
	printf("Prijmeni: ");
	getchar();
	scanf_s("%[^\n]", prijmeni, VELIKOST);
	printf("Jmeno: ");
	getchar();
	scanf_s("%[^\n]", jmeno, VELIKOST);
	printf("Kolik chcete rezervaci: ");
	scanf_s("%d", &pocetrezervaci);
	for (int j = 0; j < pocetrezervaci; j++) {
		printf("Rada: ");
		scanf_s("%d", &rezervace[0][j]);
		printf("Misto: ");
		scanf_s("%d", &rezervace[1][j]);
		map[rezervace[0][j]][rezervace[1][j]] = 1;
	}
	editujzaznam(zaznamy, b, prijmeni, jmeno,pocetrezervaci , rezervace);
}

void onNajdi(uzivatel *zaznam) {
	char prijmeni[50];
	system("cls");
	getchar();
	printf("Prijmeni: ");
	scanf_s("%[^\n]", prijmeni, VELIKOST);
	najdizaznam(zaznam, prijmeni);
}
void onSmaz(uzivatel **zaznam) {
	int ID=0;
	system("cls");
	getchar();
	printf("Zadej ID ke smazani: ");
	scanf_s("%d",&ID);
	smaz(zaznam, ID);
}

int main()
{
	uzivatel *seznam;
	seznam = NULL;
	menu volba;

	do
	{
		printf("1:Pridat rezervaci\n2:Vypis rezervaci\n3:Najdi rezervaci\n4:Smazat rezervaci\n5:Uloz rezervace\n6:Nacti rezervace\n7:Edituj rezervaci\n8:Konec\n");
		tiskoddelovace();
		printf("Volba: ");
		if (scanf_s("%d", &volba) != 1) {
			tiskoddelovace();
			printf("Chyba pri nacitani\n");
			tiskoddelovace();
			while ((getchar()) != '\n');
			continue;
		}

		switch (volba)
		{
		case pridat:
		{
			onPridej(&seznam);
			break;
		}
		case vypis:
		{
			system("cls");
			tisk(seznam);
			break;
		}
		case najdi:
		{
			system("cls");
			onNajdi(seznam);
			break;
		}
		case smazat:
		{
			onSmaz(&seznam);
			break;
		}
		case uloz:
		{
			system("cls");
			ulozseznam(seznam);
			ulozmapu();
			break;
		}
		case nacti:
		{
			nactiseznam(&seznam);
			nactimapu();
			break;
		}
		case edituj:
		{
			//onedit(&seznam);
			break;
		}
		case konec:
		{
			printf("Konec\n");
			return 1;
			break;
		}
		default:
		{
			printf("Neznama volba.\n");
			break;
		}
		}
	} while (true);

	return 0;
}

