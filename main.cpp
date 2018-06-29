#include "Sequence.h"
#include <iostream>

int main()
{
        Sequence ob("dna.txt");
 	cout << "The length of DNA: "  << ob.length() << endl;
	cout << "A: " << ob.numberOf('A') << endl;
	cout << "T: " << ob.numberOf('T') << endl;
	cout << "C: " << ob.numberOf('C') << endl;
	cout << "G: " << ob.numberOf('G') << endl;
	cout << "The longest Consecutive: " << ob.longestConsecutive() << endl;
	cout << "The longest Repeated: " << ob.longestRepeated() << endl;
	return 0;
}
