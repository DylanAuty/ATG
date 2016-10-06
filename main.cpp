/** main.cpp
 * Dylan Auty, 2016
 */

#include <ncurses.h>

int main(){
	initscr();
	noecho();	// Turn off input echoing
	printw("Welcome! Press any button.");
	refresh();
	int ch = getch();	// Wait for user input.
	
	
	
	
	
	endwin();

	return 0;
}
