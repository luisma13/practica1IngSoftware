#include <conio.h>
#include <Windows.h>
#include <iostream>

#define WIDTHWORLD 78

int main() {
	bool playing = true;
	char pulsedKey = '-';

	int leftBullet  = -1;
	int rigthBullet = -1;

	int posPlayer = WIDTHWORLD / 2;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n");

	while (playing) {
		if (_kbhit()) {
			pulsedKey = _getch();

			if (pulsedKey == 'a')	posPlayer--;
			else if (pulsedKey == 'd')	posPlayer++;
			else if (pulsedKey == 'j' && leftBullet == -1)  leftBullet = posPlayer - 1;
			else if (pulsedKey == 'l' && rigthBullet == -1) rigthBullet = posPlayer + 1;
		}

		if      (posPlayer <  0)		 posPlayer = 0;
		else if (posPlayer > WIDTHWORLD) posPlayer = WIDTHWORLD;

		if	(leftBullet  != -1)  leftBullet--;
		if	(rigthBullet != -1) rigthBullet++;

		if	(leftBullet < 0)			leftBullet  = -1;
		if	(rigthBullet > WIDTHWORLD)	rigthBullet = -1;

		for (int i = 0; i <= WIDTHWORLD; i++) {
			if (i == posPlayer)   printf("*");
			else if (i == leftBullet)  printf("<");
			else if (i == rigthBullet) printf(">");

			else printf("-");
		}

		printf("\r");
		Sleep(60);
	}

	return 0;
}