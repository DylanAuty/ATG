/// CursesWindow - Class defining/initialising the ncurses interface and session.
/** Represents the curses window within which the interface will be
 * contained. Handles configuration and proper closing of the
 * ncurses session upon launching and exiting the program. Also 
 * handles the welcome screen, followed by the set up of the main
 * interface.
 *
 * Dylan Auty, 2016
 */

#ifndef CURSESWINDOW_HPP
#define CURSESWINDOW_HPP

class CursesWindow {
	public:
		CursesWindow();		///< Constructor, initialises window.
		~CursesWindow();	///< Destructor, handles window cleanup.
		int lines;			///< Stores no. of lines in window.
		int cols; 			///< Stores no. of cols in window.
	private:
		void cwInit();		///< Runs through initial configuration of curses session.
		void welcomeScr();	///< Displays a welcome screen (press any button to continue), to be used prior to subwindow setup.

};

#endif
