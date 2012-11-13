////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File: siC++/fstring.hpp
//  Author: David Steinberg
//  Date: April 28, 2012
//  Description: This is a formattable string class. Dig in.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SIC_FSTRING_HPP_
#define _SIC_FSTRING_HPP_

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INCLUDES
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <vector>

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
//											COLORS AND STYLES
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SIC_COLOR_AND_STYLE_
#define _SIC_COLOR_AND_STYLE_

enum Color {
	Black = 0,
	Red = 1,
	Green = 2,
	Yellow = 3,
	Blue = 4,
	Magenta = 5,
	Cyan = 6,
	Gray = 7,
	Default = 9,
	
	iBlack = 60,
	iRed = 61,
	iGreen = 62,
	iYellow = 63,
	iBlue = 64,
	iMagenta = 65,
	iCyan = 66,
	iGray = 67
};

enum Style {
	Reset = 0,
	Bold = 1,
	Dim = 2,
	Underline = 4,
	Blink = 5,
	Reverse = 7,
	Hidden = 8
};

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SIC STRING HELPER INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SIC_STRING_HELPERS_
#define _SIC_STRING_HELPERS_

////////////////////////////////////////////////////////////////////////////////////////////////////
//											POW
////////////////////////////////////////////////////////////////////////////////////////////////////

int pow (int base, int pow) {
	if (pow == 0)
		return 1;
	for (int i = 1; i < pow; i++)
		base *= base;
	return base;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											TO CHAR
////////////////////////////////////////////////////////////////////////////////////////////////////

char toChar (int n) {
	return char(int('0') + n);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											IS SPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

bool isSpace (const char ch) {
	return (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n');
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											IS DIGIT
////////////////////////////////////////////////////////////////////////////////////////////////////

bool isDigit (const char ch) {
	return (char('0') <= ch && ch <= char('9'));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											IS MATH OPERATOR
////////////////////////////////////////////////////////////////////////////////////////////////////

bool isMathOperator (const char ch) {
	return (ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END SIC STRING HELPER INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
//											FSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											FSTRING CLASS
////////////////////////////////////////////////////////////////////////////////////////////////////

class fstring {

private:

//STRING
	int cap;
	char * str;
	static const int SIZE_CAP = 200;

// FORMAT
	const static int styleSize = 5;

	int * curStyle;

	int	curStyleSize,	
		curColor,
		curBG;

public:

// CONSTRUCTORS
							fstring			();
							fstring			(const char);
							fstring			(const char[]);
							fstring			(char*[]);
							fstring			(const std::string);
							fstring			(const int);

// DESTRUCTOR
							~fstring		();

// COPY CONSTRUCTOR
							fstring			(const fstring&);
							fstring			(const fstring&, const bool);

// SIZE
	void					resize			(const int);
	int						capacity		()												const;
	int						length			()												const;

// INDEX OF
	int						indexOf			(const char)									const;
	int						indexOf			(const char, const int)						const;
	int						indexOf			(const char, const int, const int)			const;

	int						indexOf			(const fstring&)								const;
	int						indexOf			(const fstring&, const int)					const;
	int						indexOf			(const fstring&, const int, const int)		const;

// COUNT
	int						count			(const char)									const;
	int						count			(const char, const int)						const;
	int						count			(const char, const int, const int)			const;

	int						count			(const fstring&)								const;
	int						count			(const fstring&, const int)					const;
	int						count			(const fstring&, const int, const int)		const;

// CONTAINS
	bool					contains		(const char)									const;
	bool					contains		(const fstring&)								const;
	bool					hasDigit		()												const;

// MANIPULATORS
	fstring					substr			(const int, const int)						const;
	fstring					substr			(const int, const int, const bool)			const;
	std::vector<fstring>	split			(const char)									const;
	fstring					trim			()												const;
	fstring					trim			(const bool)									const;
	fstring					noSpace			()												const;
	fstring					noSpace			(const bool)									const;	
	fstring					justDigits		()												const;
	fstring					justDigits		(const bool)									const;
	fstring					reverse			()												const;
	fstring					reverse			(const bool)									const;

// NUMBERS
	int						toInt			()												const;
	int						prevDigit		(const int)									const;
	int						nextDigit		(const int)									const;

// OVERLOADED OPERATORS
	fstring&				operator=		(fstring);
	void					swap			(fstring&);

	char					operator[]		(const int)									const;
	char&					operator[]		(const int);

	fstring					operator+		(const fstring&)								const;
	fstring&				operator+=		(const fstring&);

	bool					operator==		(const fstring&)								const;
	bool					operator&=		(const fstring&)								const;
	bool					operator<		(const fstring&)								const;
	bool					operator<=		(const fstring&)								const;
	bool					operator>=		(const fstring&)								const;
	bool					operator>		(const fstring&)								const;
	bool					operator!=		(const fstring&)								const;

	friend	std::istream&	operator>>		(std::istream&, fstring&);
	friend	std::ostream&	operator<<		(std::ostream&, const fstring&);
	friend	std::istream&	getline			(std::istream&, fstring&);

// FORMAT
	void					showSpace		()												const;
	void					showSpace		(const int)									const;

	void					highlight		(const char)									const;
	void					highlight		(const char, const int)						const;
	void					highlight		(const char, const int, const int)			const;	

	void					highlight		(const fstring&)								const;
	void					highlight		(const fstring&, const int)					const;
	void					highlight		(const fstring&, const int, const int)		const;

	void					highlight		(const int, const int)						const;
	void					highlight		(const int, const int, const int)				const;
	void					highlight		(const int, const int, const int, const int)	const;

	fstring&				setColor		(const int);
	fstring&				endColor		();

	fstring&				setBG			(const int);
	fstring&				endBG			();

	fstring&				setStyle		(const int);
	fstring&				endStyle		();
	fstring&				addStyle		(const int);
	fstring&				removeStyle		(const int);
	
	void					print			()												const;
	void					printFormat		()												const;
	void					endFormat		()												const;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
//											FSTRING FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											CONSTRUCTORS
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring::fstring () { 

	cap = SIZE_CAP;
	str = new char[cap];
	str[0] = 0;
	
	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

fstring::fstring (const char ch) {

	cap = SIZE_CAP;
	str = new char[cap];
	str[0] = ch;
	str[1] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

fstring::fstring (const char s[]) { 

	cap = SIZE_CAP;
	str = new char[cap];
    int i = 0;
    while (s[i] != 0) {
        str[i] = s[i];
        i++;
    }
    str[i] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

fstring::fstring (char *s[]) { 

	cap = SIZE_CAP;
	str = new char[cap];
    int i = 0;
	while (s[i] != 0) {
		str[i] = *s[i];
		i++;
	}
	str[i] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

fstring::fstring (const std::string s) { 

	cap = s.length();
	str = new char[cap];
    int i = 0;
	while (s[i] != 0) {
		str[i] = s[i];
		i++;
	}
	str[i] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

fstring::fstring (const int n) {

	cap = n;
	str = new char[cap];
	str[0] = 0;	

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;	
	curColor = 9;
	curBG = 9;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											DESTRUCTOR
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring::~fstring () {
	delete [] str;
	cap = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											COPY CONSTRUCTOR
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring::fstring (const fstring& actual) {

	cap = actual.cap;
	str = new char[cap];
	
	int i = 0;
	while(i < actual.length()) {
		str[i] = actual.str[i];
		i++;
	}
	str[i] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = actual.curStyle[i];

	curStyleSize = actual.curStyleSize;
	curColor = actual.curColor;
	curBG = actual.curBG;

}

fstring::fstring (const fstring& actual, const bool noFormat) {

	cap = actual.cap;
	str = new char[cap];
	
	int i = 0;
	while(i < actual.length()) {
		str[i] = actual.str[i];
		i++;
	}
	str[i] = 0;

	curStyle = new int[styleSize];
	for (int i = 0; i < styleSize; i++) curStyle[i] = 0;

	curStyleSize = 0;
	curColor = 9;
	curBG = 9;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											RESIZE
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::resize (const int newCap) {
	char * tmp = new char[newCap];
	int i=0;
	while(i < cap && i < newCap) {
		tmp[i] = str[i];
		i++;
	}
	delete [] str;
	cap = newCap;
	str = tmp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											CAPACITY
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::capacity () const {
	return cap;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											LENGTH
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::length () const {
	int i=0;
	while(str[i] != 0) i++;
	return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INDEX OF CHAR
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::indexOf (const char ch) const {
	int i = 0;
	while(i < length()) {
		if(str[i] == ch) return i;
		i++;
	}
    return -1;
}

int fstring::indexOf (const char ch, const int pos) const {  
	int i = pos;
	while(i < length()) {
		if(str[i] == ch) return i;
		i++;
	}
    return -1;
}

int fstring::indexOf (const char ch, const int startPos, const int endPos) const {  
	int i = startPos;
	while(i < endPos) {
		if(str[i] == ch) return i;
		i++;
	}
    return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											INDEX OF SUBSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::indexOf (const fstring& s) const {   
	int i = 0;
	while(i < length() - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) return i;
		i++;	
	}
	return -1;
}

int fstring::indexOf (const fstring& s, const int pos) const {   
	int i = pos;
	while(i < length() - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) return i;
		i++;
	}	
	return -1;
}

int fstring::indexOf (const fstring& s, const int startPos, const int endPos) const {   
	int i = startPos;
	while(i < endPos - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) return i;
		i++;
	}	
	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											COUNT CHAR
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::count (const char ch) const {

	int	i = 0,
		count = 0;

	while(i < length()) {
		if(str[i] == ch) count++;
		i++;
	}

    return count;

}

int fstring::count (const char ch, const int pos) const {

	int	i = pos,
		count = 0;

	while(i < length()) {
		if(str[i] == ch) count++;
		i++;
	}

    return count;

}

int fstring::count (const char ch, const int startPos, const int endPos) const {

	int	i = startPos,
		count = 0;

	while(i < endPos) {
		if(str[i] == ch) count++;
		i++;
	}

    return count;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											COUNT SUBSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::count (const fstring& s) const {

	int	i = 0,
		count = 0;

	while(i < length() - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) count++;
		i++;
	}

	return count;

}

int fstring::count (const fstring& s, const int pos) const {

	int	i = pos,
		count = 0;

	while(i < length() - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) count++;
		i++;
	}

	return count;

}

int fstring::count (const fstring& s, const int startPos, const int endPos) const {

	int	i = startPos,
		count = 0;

	while(i < endPos - s.length() + 1) {
		if(substr(i, i + s.length() - 1) == s) count++;
		i++;
	}

	return count;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											CONTAINS CHAR
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length()

bool fstring::contains (const char ch) const {

	bool found = false;

	for (int i = 0; i < length(); i++) {
		if (str[i] == ch) {
			found = true;
			break;
		}
	}

	return found;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											CONTAINS STRING
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length()

bool fstring::contains (const fstring& fstr) const {

	if (indexOf(fstr) == -1)	return false;

	return true;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											HAS DIGIT
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length(), toChar()

bool fstring::hasDigit () const {

	bool found = false;

	for (int ch = 0; ch < length(); ch++) {
		for (int num = 0; num < 9; num++) {
			if (str[ch] == toChar(num)) {
				found = true;
				break;
			}
		}
	}
	
	return found;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SUBSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring fstring::substr (const int start, const int end) const { 
	fstring result(*this);
	int i = start;
	while(i <= end) {
		result.str[i-start] = str[i];
		i++;
	}
	result.str[i-start] = 0;

    return result;               
}

fstring fstring::substr (const int start, const int end, const bool noFormat) const { 
	fstring result;
	int i = start;
	while(i <= end) {
		result.str[i-start] = str[i];
		i++;
	}
	result.str[i-start] = 0;

    return result;               
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SPLIT
////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<fstring> fstring::split (const char ch) const {   
    std::vector<fstring> result;
	int i = 0;
	int start = 0;
	while(str[i] != 0) {
		if(str[i] == ch) {
			result.push_back(substr(start, i-1));
			start = i+1;
		}
		
		i++;
	}
	
	result.push_back(substr(start, i-1));

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											TRIM
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length()

fstring fstring::trim () const {

	fstring result(*this);

	int	start = -1;

	for (int i = 0; i < length(); i++) {
		if (!isSpace(str[i])) {
			start = i;
			break;
		}
	}

	if (start != -1) {	
		for (int i = start; i < length()+1; i++) result.str[i-start] = str[i];
	
		for (int i = result.length()+1; i >= 0 ; i--) {
			if (!isSpace(result.str[i])) {
				result.str[i+1] = 0;
				break;
			}
		}
	} else {
		result.str[0] = 0;
	}
	
	return result;

}

fstring fstring::trim (const bool noFormat) const {

	fstring result;

	int	start = -1;

	for (int i = 0; i < length(); i++) {
		if (!isSpace(str[i])) {
			start = i;
			break;
		}
	}

	if (start != -1) {	
		for (int i = start; i < length(); i++) result.str[i-start] = str[i];
	
		for (int i = result.length()-1; i > 0 ; i--) {
			if (!isSpace(result.str[i])) {
				result.str[i+1] = 0;
				break;
			}
		}
	} else {
		result.str[0] = 0;
	}
	
	return result;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											NO SPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length()

fstring fstring::noSpace () const {

	fstring result(*this);

	int newSize = 0;
	for (int i = 0; i < length(); i++) {
		if (!isSpace(str[i])) {
			result.str[newSize] = str[i];
			newSize++;
		}
	}
	result.str[newSize] = 0;	

	return result;

}

fstring fstring::noSpace (const bool noFormat) const {

	fstring result;

	int newSize = 0;
	for (int i = 0; i < length(); i++) {
		if (!isSpace(str[i])) {
			result.str[newSize] = str[i];
			newSize++;
		}
	}
	result.str[newSize] = 0;	

	return result;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											REVERSE
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring fstring::reverse () const {

	fstring result(*this);

	for (int i = 0; i < length(); i++) {
		result.str[length()-i-1] = str[i];
	}

	return result;

}

fstring fstring::reverse (const bool noFormat) const {

	fstring result;

	for (int i = 0; i < length(); i++) {
		result.str[length()-i-1] = str[i];
	}

	return result;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											JUST DIGITS
////////////////////////////////////////////////////////////////////////////////////////////////////

// REQ FUNCTIONS: length(), pow()

fstring fstring::justDigits () const {

	fstring result(*this);

	int  newSize = 0;

	for (int ch = 0; ch < length(); ch++) {

		bool isDigit = false;
		for (int i = 0; i < 10; i++) {
			if (int(str[ch]) == (int('0') + i)) {
				isDigit = true;
				break;
			}
		}

		if (isDigit) {		
			result.str[newSize] = str[ch];
			newSize++;
		}

	}

	result.str[newSize] = 0;

	return result;

}

fstring fstring::justDigits (const bool noFormat) const {

	fstring result;

	int  newSize = 0;

	for (int ch = 0; ch < length(); ch++) {

		bool isDigit = false;
		for (int i = 0; i < 10; i++) {
			if (int(str[ch]) == (int('0') + i)) {
				isDigit = true;
				break;
			}
		}

		if (isDigit) {		
			result.str[newSize] = str[ch];
			newSize++;
		}

	}

	result.str[newSize] = 0;

	return result;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											TO INT
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::toInt () const {

	int	len		= length(),
		i		= len - 1,
		num		= 0,
		result	= 0;

	while (i >= 0) {

		if (i == 0 && str[i] == '-') {
			result -= (result * 2);
			break;			
		}

		int power = pow(10, (len-1-i));

		num = (int(str[i]) - int('0')) * power;
		result += num;
		i--;

	}

	return result;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											PREV DIGIT
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::prevDigit (const int end) const {

	int start = 0;

	for (int i = end-1; i >= 0; i--) {
		if (!isDigit(str[i])) {
			start = i+1;
			break;
		}
	}

	if (start != end)	return substr(start,end-1).toInt();
	else				return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											NEXT DIGIT
////////////////////////////////////////////////////////////////////////////////////////////////////

int fstring::nextDigit (const int start) const {

	int end = length();

	for (int i = start+1; i < length(); i++) {
		if (!isDigit(str[i])) {
			end = i-1;
			break;
		}
	}

	if (start != end)	return substr(start+1,end).toInt();
	else				return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SWAP
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::swap (fstring& rhs) {

	char * tmpStr = str;
	str = rhs.str;
	rhs.str = tmpStr;
	
	int tmpCap = cap;
	cap = rhs.cap;
	rhs.cap = tmpCap;
	
	int * tmpCurStyle = curStyle;
	curStyle = rhs.curStyle;
	rhs.curStyle = tmpCurStyle;
	
	int tmpCurStyleSize = curStyleSize;
	curStyleSize = rhs.curStyleSize;
	rhs.curStyleSize = tmpCurStyleSize;
	
	int tmpCurColor = curColor;
	curColor = rhs.curColor;
	rhs.curColor = tmpCurColor;

	int tmpCurBG = curBG;
	curBG = rhs.curBG;
	rhs.curBG = tmpCurBG;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED OPERATORS
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED ASSIGNMENT
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring& fstring::operator= (fstring rhs) {
	swap(rhs);
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED [ ]
////////////////////////////////////////////////////////////////////////////////////////////////////

char fstring::operator[] (const int i) const {
	assert(i >= 0 && i < length());
	return str[i];
}

char& fstring::operator[] (const int i) {
	assert(i >= 0 && i < length());
	return str[i];
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED ADDITION
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring fstring::operator+ (const fstring& rhs) const {
	fstring result(str);
	int i = length();
	while(rhs.str[i-length()] != 0) {
		result.str[i] = rhs.str[i-length()];
		i++;
	}
	result.str[i] = 0;
	return result;
}

fstring& fstring::operator+= (const fstring& rhs) {
	int len = length();
	int i = 0;
	while(rhs.str[i] != 0) {
		str[len + i] = rhs.str[i];
		i++;
	}
	str[len + i] = 0;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED COMPARITORS
////////////////////////////////////////////////////////////////////////////////////////////////////

bool fstring::operator== (const fstring& rhs) const {   
	int i=0;
	while(str[i] != 0 || rhs.str[i] != 0) {
		if(str[i] != rhs.str[i])
			return false;
		i++;
	}

	if(rhs.str[i] == 0)
		return true;
	else
		return false;
}

bool fstring::operator&= (const fstring& rhs) const {

	if (curColor != rhs.curColor) return false;
	if (curBG != rhs.curBG) return false;
	if (curStyleSize != rhs.curStyleSize) return false;
	for (int i = 0; i < styleSize; i++) {
		if (curStyle[i] != rhs.curStyle[i]) return false;
	}

	int i=0;
	while(str[i] != 0 && rhs.str[i] != 0) {
		if(str[i] != rhs.str[i])
			return false;
		i++;
	}

	if(rhs.str[i] == 0)
		return true;
	else
		return false;
}

bool fstring::operator< (const fstring& rhs) const {
	int i=0;
	while(str[i] != 0 && rhs.str[i] != 0) {
		if(str[i] < rhs.str[i])
			return true;
		if(str[i] > rhs.str[i])
			return false;
		i++;
	}

	if(rhs.str[i] != 0)
		return true;
	return false;
}

bool fstring::operator<= (const fstring& s) const {
	return (operator==(s) || operator<(s));
}

bool fstring::operator>= (const fstring& s) const {
	return (operator==(s) || !operator<(s));
}

bool fstring::operator> (const fstring& s) const {
	return !operator<(s);
}

bool fstring::operator!= (const fstring& s) const {
	return !operator==(s);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED IN / OUT
////////////////////////////////////////////////////////////////////////////////////////////////////

std::istream& operator>> (std::istream& in, fstring& s) {
	in >> s.str;
	return in;
}

std::ostream& operator<< (std::ostream& out, const fstring& s) {
	s.printFormat();
	out << s.str;
	s.endFormat();

	return out;
}

std::istream& getline (std::istream& in, fstring& s) { 

	int		i = 0;
	char	ch;

	in.get(ch);
	while(!in.eof()) {

		if (ch == '\n' || ch == '\r') {
			s.str[i] = 0;
			break;
		}

		s.str[i] = ch;
		in.get(ch);
		i++;

	}	

	return in;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											OVERLOADED FRIEND ADDITION
////////////////////////////////////////////////////////////////////////////////////////////////////


fstring operator+ (const char lhs, const fstring& rhs) {
	return fstring(lhs) + rhs;
}

fstring operator+ (const char lhs[], const fstring& rhs) {
	return fstring(lhs) + rhs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SHOW SPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::showSpace () const {

	for (int i = 0; i < length(); i++) {

		if (isSpace(str[i])) {
			userOut	<< userEscape
						<< "["
						<< (Yellow+40)
						<< "m"
						<< str[i]
						<< userEscape
						<< "[m";
		} else {
			printFormat();
			userOut << str[i];
			endFormat();
		}

	}

}

void fstring::showSpace (const int col) const {

	for (int i = 0; i < length(); i++) {

		if (isSpace(str[i])) {
			userOut	<< userEscape
						<< "["
						<< (col+40)
						<< "m"
						<< str[i]
						<< userEscape
						<< "[m";
		} else {
			printFormat();
			userOut << str[i];
			endFormat();
		}

	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											HIGHLIGHT CHAR
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::highlight (const char ch) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (str[i] == ch) {
			userOut	<< userEscape
					<< "["
					<< (Yellow+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

void fstring::highlight (const char ch, const int bg) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (str[i] == ch) {
			userOut	<< userEscape
					<< "["
					<< (bg+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

void fstring::highlight (const char ch, const int col, const int bg) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (str[i] == ch) {
			userOut	<< userEscape
					<< "["
					<< (col+30)
					<< ";"
					<< (bg+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											HIGHLIGHT SUBSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::highlight (const fstring& s) const {

	int	i = 0;
	while(i < length()) {
		printFormat();
		if (i < length() - s.length() + 1) {
			if(substr(i, i + s.length() - 1) == s) {
				userOut	<< userEscape
							<< "["
							<< (Yellow+40)
							<< "m"
							<< substr(i, i + s.length() - 1,false);
				i = i + s.length();
			} else {
				userOut << str[i];
				i++;
			}
		} else {
			userOut << str[i];
			i++;
		}
		endFormat();
	}

}

void fstring::highlight (const fstring& s, const int bg) const {

	int	i = 0;
	while(i < length()) {
		printFormat();
		if (i < length() - s.length() + 1) {
			if(substr(i, i + s.length() - 1) == s) {
				userOut	<< userEscape
							<< "["
							<< (bg+40)
							<< "m"
							<< substr(i, i + s.length() - 1,false);
				i = i + s.length();
			} else {
				userOut << str[i];
				i++;
			}
		} else {
			userOut << str[i];
			i++;
		}
		endFormat();
	}

}

void fstring::highlight (const fstring& s, const int col, const int bg) const {

	int	i = 0;
	while(i < length()) {
		printFormat();
		if (i < length() - s.length() + 1) {
			if(substr(i, i + s.length() - 1) == s) {
				userOut	<< userEscape
							<< "["
							<< (col+30)
							<< ";"
							<< (bg+40)
							<< "m"
							<< substr(i, i + s.length() - 1,false);
				i = i + s.length();
			} else {
				userOut << str[i];
				i++;
			}
		} else {
			userOut << str[i];
			i++;
		}
		endFormat();
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											HIGHLIGHT RANGE
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::highlight (const int start, const int end) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (i >= start && i <= end) {
			userOut	<< userEscape
					<< "["
					<< (Yellow+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

void fstring::highlight (const int start, const int end, const int bg) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (i >= start && i <= end) {
			userOut	<< userEscape
					<< "["
					<< (bg+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

void fstring::highlight (const int start, const int end, const int col, const int bg) const {

	for (int i = 0; i < length(); i++) {

		printFormat();

		if (i >= start && i <= end) {
			userOut	<< userEscape
					<< "["
					<< (col+30)
					<< ";"
					<< (bg+40)
					<< "m";
		}

		userOut << str[i];
		endFormat();

	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											COLOR
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring& fstring::setColor (const int col) {
	curColor = col + 30;
	return *this;
}

fstring& fstring::endColor () {
	curColor = 39;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											BG
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring& fstring::setBG (const int col) {
	curBG = col + 40;
	return *this;
}

fstring& fstring::endBG () {
	curBG = 49;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											SET/END STYLE
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring& fstring::setStyle (const int stl) {

	endStyle();

	curStyle[0] = stl;
	curStyleSize = 1;

	return *this;

}

fstring& fstring::endStyle () {

	for (int i = 0; i < curStyleSize; i++) {
		curStyle[i] = 0;
	}
	curStyleSize = 0;

	return *this;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											ADD/REMOVE STYLE
////////////////////////////////////////////////////////////////////////////////////////////////////

fstring& fstring::addStyle (const int stl) {

	bool found = false;

	for (int i = 0; i < curStyleSize; i++) {
		if (curStyle[i] == stl) {
			found = true;
			break;
		}
	}

	if (!found) {
		curStyle[curStyleSize] = stl;
		curStyleSize++;
	}

	return *this;

}

fstring& fstring::removeStyle (const int stl) {

	bool found = false;

	int i = 0;
	while (i < curStyleSize) {
		if (found) {
			curStyle[i-1] = curStyle[i];
			curStyle[i] = 0;
		} else if (curStyle[i] == stl) {
			found = true;
			curStyle[i] = 0;
		}
		i++ ;
	}

	if (found) curStyleSize--;

	return *this;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											PRINT
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::print () const {

	printFormat();
	userOut << str;
	endFormat();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											PRINT FORMAT
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::printFormat () const {

	for (int i = 0; i < curStyleSize; i++) {
		userOut	<< userEscape
				<< "["
				<< curStyle[i]
				<< "m";
	}

	userOut	<< userEscape << "[" << curColor << "m"
			<< userEscape << "[" << curBG << "m";

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END FORMAT
////////////////////////////////////////////////////////////////////////////////////////////////////

void fstring::endFormat () const {
	userOut << userEscape << "[m";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END FSTRING
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END NAMESPACE
////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////
//											END INCLUDE GUARDS
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif