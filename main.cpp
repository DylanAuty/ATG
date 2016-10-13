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
	mvwprintw(debugRowWin, 0, 0, "Dims:%dx%d", parentWin.lines, parentWin.cols);
	wrefresh(debugRowWin);
	
	int ch;
	int newParentWinLines, newParentWinCols;
	// Main game loop.
	while(1){
		// Check window size is what it was before, and deal with it if not.
		getmaxyx(stdscr, newParentWinLines, newParentWinCols);
		if(newParentWinLines != parentWin.lines || newParentWinCols != parentWin.cols){
			// Resize windows and redraw borders
			parentWin.lines = newParentWinLines;
			parentWin.cols = newParentWinCols;
			
			// TODO: move resizing into a subroutine of CursesWindow that can call all subwindows and resize arbitrarily.
			wclear(stdscr);
			wclear(mapWin);
			wclear(debugRowWin);
			
			wresize(mapWin, parentWin.lines - 4, parentWin.cols - 4);
			box(mapWin, 0, 0);
			
			wresize(debugRowWin, 1, parentWin.cols);
			mvwin(debugRowWin, parentWin.lines - 1, 0);
			mvwprintw(debugRowWin, 0, 0, "Dims:%dx%d", parentWin.lines, parentWin.cols);
			
			mvwprintw(stdscr, 0, 0, "Press F1 to quit.");

			wrefresh(stdscr);
			wrefresh(mapWin);
			wrefresh(debugRowWin);
		}

		// Fetch input
		ch = getch();
		switch(ch){
			case KEY_F(1):
				return 0;
			case '.':
				break;
			default:
				wclear(debugRowWin);
				mvwprintw(debugRowWin, 0, 0, "Unknown input.");
				wrefresh(debugRowWin);
				break;
		}
	}


	return 0;
}


