/***
 *     _____             _
 *    /  ___|           | |
 *    \ `--. _ __   __ _| | _____
 *     `--. \ '_ \ / _` | |/ / _ \
 *    /\__/ / | | | (_| |   <  __/
 *    \____/|_| |_|\__,_|_|\_\___|
 *
 * 
 *	Author: Oliwer Lisek
 * 
 *	Simple snake game in ANSI C. Based on open-sources solutions. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Keyboard support

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

static const int BOARD_WIDTH = 40;
static const int BOARD_HEIGHT = 15;

int gameOver = 0, score = 0;
int x, y; //Our snake position
int fruit_x, fruit_y; //Current fruit position
int flag;

/*
* Drawing play board
*/
void draw()
{
	system("@cls||clear");
	for (int row = 0; row <= BOARD_HEIGHT; row++) {
		for (int rowElement = 0; rowElement <= BOARD_WIDTH; rowElement++) {

			if (row == 0 || row == BOARD_HEIGHT) {
				printf("#");
			}
			else if (rowElement == 0 || rowElement == BOARD_WIDTH) {
				printf("#");
			}
			else {
				if (row == x && rowElement == y) {
					printf("&");
				}
				else if (row == fruit_x && rowElement == fruit_y) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}

		printf("\n");
	}

	printf("score: %d", score);
	printf("\n");
	printf("Press L to exit game");
}

void fruit() {

first:
	fruit_x = rand() % BOARD_HEIGHT;
	if (fruit_x == 0) {
		goto first;
	}

second:
	fruit_y = rand() % BOARD_WIDTH;
	if (fruit_y == 0) {
		goto second;
	}
}

void setup() {
	x = BOARD_HEIGHT / 2;
	y = BOARD_WIDTH / 2;
}

void keyHandler()
{
	if (_kbhit()) {
		switch (getch()) {
		case 'w':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'a':
			flag = 3;
			break;
		case 'd':
			flag = 4;
			break;
		case 'l':
			gameOver = 1;
			break;
		}
	}
}

void magic()
{
	#ifdef _WIN32
		Sleep(100);
	#else
		usleep(100 * 1000);
	#endif

	switch (flag) {
		case 1:
			x--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y--;
			break;
		case 4:
			y++;
			break;
		default:
			break;
	}

	if (x <= 0 || x >= BOARD_HEIGHT) {
		gameOver = 1;
	}

	if (y <= 0 || y >= BOARD_WIDTH) {
		gameOver = 1;
	}

	if (x == fruit_x && y == fruit_y) {
		fruit();
		score += 10;
	}
}

int main()
{
	setup();
	fruit();

	while (!gameOver) {
		draw();
		keyHandler();
		magic();
	}

	return EXIT_SUCCESS;
}