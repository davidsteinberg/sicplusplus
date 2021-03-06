////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File: siC++/position.hpp
//  Author: David Steinberg
//  Date: April 28, 2012
//  Description: These functions can be used to position your output more easily.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SIC_POSITION_HPP_
#define _SIC_POSITION_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INCLUDES
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END INCLUDES
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											NAMESPACE BEGIN
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace sic {

////////////////////////////////////////////////////////////////////////////////////////////////////
//											GLOBALS
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SIC_GLOBALS_
#define _SIC_GLOBALS_

std::ostream& userOut = std::cout;
char    userNewLine = '\n',
        userTab     = '\t',
        userSpace   = ' ',
        userEscape  = '\e';

////////////////////////////////////////////////////////////////////////////////////////////////////
//											PRINT
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ VARIABLES: userOut

template <class T>
void print (T str) {
	userOut << str;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											PRINT REPEAT
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ VARIABLES: userOut

template <class T>
void printRepeat (T str, int num) {
	while (num > 0) {
		userOut << str;
		num--;
	}
}

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END GLOBALS
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											POSITIONING
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											NEWLINE 
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ VARIABLES: userOut, userNewLine

void newLine () {
	userOut << userNewLine;
}

void newLine (int num) {
	while (num > 0) {
		userOut << userNewLine;
		num--;
	}
}

template <class T>
void newLine (int num, T str) {
	while (num > 0) {
		userOut << userNewLine;
		num--;
	}
	userOut << str;
}

template <class T>
void newLine (T str, int num) {
	userOut << str;
	while (num > 0) {
		userOut << userNewLine;
		num--;
	}
}

template <class T>
void newLine (int num1, T str, int num2) {
	while (num1 > 0) {
		userOut << userNewLine;
		num1--;
	}
	userOut << str;
	while (num2 > 0) {
		userOut << userNewLine;
		num2--;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											TAB 
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ VARIABLES: userOut, userTab

void tab () {
	userOut << userTab;
}

void tab (int num) {
	while (num > 0) {
		userOut << userTab;
		num--;
	}
}

template <class T>
void tab (int num, T str) {
	while (num > 0) {
		userOut << userTab;
		num--;
	}
	userOut << str;
}

template <class T>
void tab (T str, int num) {
	userOut << str;
	while (num > 0) {
		userOut << userTab;
		num--;
	}
}

template <class T>
void tab (int num1, T str, int num2) {
	while (num1 > 0) {
		userOut << userTab;
		num1--;
	}
	userOut << str;
	while (num2 > 0) {
		userOut << userTab;
		num2--;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ VARIABLES: userOut, userSpace

void space () {
	userOut << userSpace;
}

void space (int num) {
	while (num > 0) {
		userOut << userSpace;
		num--;
	}
}

template <class T>
void space (int num, T str) {
	while (num > 0) {
		userOut << userSpace;
		num--;
	}
	userOut << str;
}

template <class T>
void space (T str, int num) {
	userOut << str;
	while (num > 0) {
		userOut << userSpace;
		num--;
	}
}

template <class T>
void space (int num1, T str, int num2) {
	while (num1 > 0) {
		userOut << userSpace;
		num1--;
	}
	userOut << str;
	while (num2 > 0) {
		userOut << userSpace;
		num2--;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											POSITION
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: newLine()

void pos (int nl) {
	newLine(nl);
}

template <class T>
void pos (int nl, T str) {
	newLine(nl,str);
}

template <class T>
void pos (T str, int nl) {
	newLine(str,nl);
}

template <class T>
void pos (int nl1, T str, int nl2) {
	newLine(nl1,str);
	newLine(nl2);
}

////////////////////////////////////////

// REQ FUNCTIONS: newLine(), tab()

void pos (int nl, int t) {
	newLine(nl);
	tab(t);
}

template <class T>
void pos (int nl, int t, T str) {
	newLine(nl);
	tab(t,str);
}

template <class T>
void pos (T str, int nl, int t) {
	newLine(str,nl);
	tab(t);
}

template <class T>
void pos (int nl1, int t1, T str, int nl2, int t2) {
	newLine(nl1);
	tab(t1,str);
	newLine(nl2);
	tab(t2);
}

////////////////////////////////////////

// REQ FUNCTIONS: newLine(), tab(), space()

void pos (int nl, int t, int s) {
	newLine(nl);
	tab(t);
	space(s);
}

template <class T>
void pos (int nl, int t, int s, T str) {
	newLine(nl);
	tab(t);
	space(s,str);
}

template <class T>
void pos (T str, int nl, int t, int s) {
	newLine(str,nl);
	tab(t);
	space(s);
}

template <class T>
void pos (int nl1, int t1, int s1, T str, int nl2, int t2, int s2) {
	newLine(nl1);
	tab(t1);
	space(s1,str);
	newLine(nl2);
	tab(t2);
	space(s2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END NAMESPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif