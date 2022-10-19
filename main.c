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

static const int BOARD_WIDTH = 60;
static const int BOARD_HEIGHT = 20;

/*
* Drawing play board
*/
void draw()
{
	for (int row = 0; row <= BOARD_HEIGHT; row++) {
		for (int rowElement = 0; rowElement <= BOARD_WIDTH; rowElement++) {

			if (row == 0 || row == BOARD_HEIGHT) {
				printf("#");
			}
			else if (rowElement == 0 || rowElement == BOARD_WIDTH) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}

		printf("\n");
	}
}

void fruit() {

}

int main()
{
	//int snake_x, snake_y; //Our snake position

	//drawSignature();
	draw();

	return EXIT_SUCCESS;
}