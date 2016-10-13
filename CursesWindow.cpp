/* CursesWindow.cpp
 * CursesWindow method implmentations.
 * 
 * Dylan Auty, 2016
 */

#include <ncurses.h>
#include "CursesWindow.hpp"

CursesWindow::CursesWindow() {
	this->cwInit();
	this->welcomeScr();
	return;

}

void CursesWindow::cwInit() {
	initscr();		// start ncurses session
	raw();			// Enable raw character input
	noecho();				// Disable input echoing
	keypad(stdscr, TRUE);	// Enable special key input
	
	getmaxyx(stdscr, this->lines, this->cols);
	return;
}

void CursesWindow::welcomeScr() {
	mvprintw(this->lines/2, this->cols/2 - 21, "Welcome to ATG. Press any key to continue.");
	refresh();
	getch();
	erase();
	refresh();
	return;
}

CursesWindow::~CursesWindow() {
	erase();	
	printw("Exiting. Press any key.");
	getch();
	endwin();
	return;
}

