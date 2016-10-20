/** main.cpp
 * Dylan Auty, 2016
 */

#include <ncurses.h>
#include "CursesWindow.hpp"
#include "Map.hpp"

using namespace std;

// TODO: Move redrawMap to another file for tidiness
void redrawMap(WINDOW* &mapWin, WINDOW* &debugRowWin, Map &gameMap, int currMapY, int currMapX, int currFloor);	///< Function to clear then redraw the map on demand, within the map window.

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

	// Create the map.
	Map gameMap;
	
	mvwprintw(debugRowWin, 0, 30, "GameMap Created");
	wrefresh(debugRowWin);


	int ch;	// Input character
	int newParentWinLines, newParentWinCols;	// For checking for resizing
	
	int currMapY = 0;
	int currMapX = 0;	// For the coordinates of the map to be displayed in the top left corner of the map window.
	int currFloor = 0;	// Current floor of the map.
	
	redrawMap(mapWin, debugRowWin, gameMap, currMapY, currMapX, currFloor);	// Draw map for the first time

	// Main game loop.
	while(1){
		// Check window size is what it was before, and deal with it if not.
		getmaxyx(stdscr, newParentWinLines, newParentWinCols);
		if(newParentWinLines != parentWin.lines || newParentWinCols != parentWin.cols){
			// Resize windows and redraw borders
			parentWin.lines = newParentWinLines;
			parentWin.cols = newParentWinCols;
			
			// TODO: move resizing + redrawing into a subroutine of CursesWindow that can resize all subwindows regardless of layout.
			// Would need each window to have a start position and size, and can move based on that.
			// Some windows will be resizable, some will be fixed size (e.g. message windows maybe, or menus).
			wclear(stdscr);
			wclear(mapWin);
			wclear(debugRowWin);
			
			wresize(mapWin, parentWin.lines - 4, parentWin.cols - 4);
			box(mapWin, 0, 0);
			
			wresize(debugRowWin, 1, parentWin.cols);
			mvwin(debugRowWin, parentWin.lines - 1, 0);
			mvwprintw(debugRowWin, 0, 0, "Dims:%dx%d", parentWin.lines, parentWin.cols);
			
			mvwprintw(stdscr, 0, 0, "Press F1 to quit.");

			// TODO: Insert a routine for populating the mapWindow.

			wrefresh(stdscr);
			wrefresh(mapWin);
			wrefresh(debugRowWin);
		}

		// Fetch input
		ch = getch();
		// Debugging: display input key in debugging window.
		wclear(debugRowWin);
		mvwprintw(debugRowWin, 0, 0, "Dims:%dx%d, Input %c", parentWin.lines, parentWin.cols, ch);
		wrefresh(debugRowWin);
		
		switch(ch){
			case KEY_F(1):	// EXIT
				return 0;
			// Moving around the map view
			// currMapY, currMapX denote current tile of the map that coincides with the top left coordinate of the view window.

			case KEY_UP:	// Move view window up
				currMapY -= 5;
				break;
			case KEY_DOWN:	// Move view window down
				currMapY += 5;
				break;
			case KEY_LEFT:	// Move view window left
				currMapX -= 5;
				break;
			case KEY_RIGHT:	// Move view window right
				currMapX += 5;
				break;
			case 'r':
				gameMap = Map();	// Reinitialise the game map to make checking layout easier
			default:
				break;
		}
		redrawMap(mapWin, debugRowWin, gameMap, currMapY, currMapX, currFloor);

	}
	return 0;
}

void redrawMap(WINDOW* &mapWin, WINDOW* &debugRowWin, Map &gameMap, int currMapY, int currMapX, int currFloor) {	
	//NOTE: first line and column of a window is taken up by borders.
	wclear(mapWin);
	
	int mapWinLines = 0;
	int mapWinCols = 0;
	box(mapWin, 0, 0);
	getmaxyx(mapWin, mapWinLines, mapWinCols);
	
	for(int y = 1; y < mapWinLines-1; y++){
		for(int x = 1; x < mapWinCols-1; x++){
			// Placeholder
			// 		1) Does the corresponding map tile exist?
			// 			- Corresponding map tile = (y + currMapY - 1, x + currMapX - 1)
			// 		2) If so, what is it and what needs printing? (May delegate this job to a tile object which has a char field.)
			
			//mvwprintw(debugRowWin, 0, 30, "Curr:%dx%d", y, x);
			//wrefresh(debugRowWin);
			if((y + currMapY - 1) >= 0 && (x + currMapX - 1) >= 0 && (y + currMapY - 1) <= 100 && (x + currMapX - 1) <= 100){
				/*switch(gameMap.floorVec[currFloor].tiles[currMapY + y - 1][currMapX + x - 1]){
					case 0:
						mvwaddch(mapWin, y, x, ' ');
						break;
					case 1:
						mvwaddch(mapWin, y, x, '#');
						break;
					default:
						break;
				}
				*/
				mvwaddch(mapWin, y, x, gameMap.floorVec[currFloor].tiles[currMapY + y - 1][currMapX + x - 1]);
				//mvwaddch(mapWin, y, x, gameMap.floorVec[currFloor].tiles[currMapY + y - 1][currMapX + x - 1]);	// 1 to deal with border offset from window border drawing.
			}

		}
	}
	wrefresh(mapWin);

	return;
}




