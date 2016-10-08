/* CursesWindow.cpp
 * CursesWindow method implmentations.
 * 
 * Dylan Auty, 2016
 */

#include <ncurses.h>
#include "CursesWindow.hpp"

CursesWindow::CursesWindow()
{
	initscr();
	noecho();
	printw("Here is a window, hooraaay");
	refresh();
	return;

}

CursesWindow::~CursesWindow()
{	
	printw("Exiting. Press any key.");
	getch();
	endwin();
	return;
}

