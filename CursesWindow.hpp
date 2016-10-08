/// CursesWindow - Class to define the ncurses interface.
/** Represents the curses window within which the interface will be
 * contained. Handles configuration and proper closing of the
 * ncurses session upon launching and exiting the program.
 *
 * Dylan Auty, 2016
 */

#ifndef CURSESWINDOW_HPP
#define CURSESWINDOW_HPP

class CursesWindow
{
	private:
		int fullWidth;
		int fullHeight;
	public:
		CursesWindow();		///< Constructor, initialises window.
		~CursesWindow();	///< Destructor, handles window cleanup.
};

#endif
