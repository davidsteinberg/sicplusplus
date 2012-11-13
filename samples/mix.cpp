// Check these paths
#include "format.hpp"
#include "position.hpp"

using namespace std;
using namespace sic;

int main() {

	const int NAMES_SIZE = 7;

	string names[NAMES_SIZE] = {"Willy","Lucy","George","Ian","Jennifer","Paul","Nancy"};
	
	for (int i=0; i<NAMES_SIZE; i++) {
		pos(1, 1);
		print(i);
		print(". ");
		printColor(names[i],60+i);
	}

	newLine(2);

	return 0;

}
