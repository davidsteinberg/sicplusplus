#include <fstream>
// Check this path
#include "fstring.hpp"

using namespace std;
using namespace sic;

int main(int argc, char** argv) {

	// Argument check
	if (argc != 3) {
		cerr << "Usage : " << argv[0] << " <fileName> <searchTerm>" << endl;
		exit(1);
	}

	fstring s;
	string line;

	// Open file
	ifstream in;
	in.open(argv[1]);

	// Read all lines in
	while (!in.eof()) {
		getline(in,line);
		
		s += line + '\n';
	}
	
	// Close file
	in.close();

	s.highlight(argv[2]);

	return 0;

}

