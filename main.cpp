/** main.cpp
 * Dylan Auty, 2016
 */

#include <ncurses.h>
#include "CursesWindow.hpp"

using namespace std;

int main(){
	// Create the parent window and print exit instructions
	CursesWindow parentWin;
	mvprintw(0, 0, "Press F1 to quit.");
	refresh();

	// Create the map window
	WINDOW* mapWin = newwin(parentWin.lines - 4, parentWin.cols - 4, 2, 2);
	box(mapWin, 0, 0);
	wrefresh(mapWin);
	
	// Create debug row (window) at the bottom of the screen
	WINDOW* debugRowWin = newwin(1, parentWin.cols, parentWin.lines - 1, 0);
	mvwprintw(debugRowWin, 0, 0, "W:%dx%d", parentWin.lines, parentWin.cols);
	wrefresh(debugRowWin);
	
	int ch = getch();
	/*
	while(ch != KEY_F(1)){
		move(0, 0);
		clrtoeol();
		getmaxyx(stdscr, mainwin.lines, mainwin.cols);
		mvprintw(0, 0, "%d, %d", mainwin.lines, mainwin.cols);
		ch = getch();
	}
	*/
	return 0;
}


