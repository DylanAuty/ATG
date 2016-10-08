/** main.cpp
 * Dylan Auty, 2016
 */

#include <ncurses.h>
#include "CursesWindow.hpp"

using namespace std;

int main(){
	CursesWindow mainWindow;
	
	int ch = getch();	// Wait for user input.
	while(ch != KEY_F(1)){
		printw("%c", ch);
		ch = getch();
	}

	return 0;
}


