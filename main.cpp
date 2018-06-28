#include <iostream>
#include "Sequence.h"
#include <ctime>

using namespace std;

int main()
{
    clock_t start,finish;
    start = clock();
    Sequence test("dna.txt");
    cout << "A: " << test.numberOf('A') << "   " << "G: " << test.numberOf('G') << "   "
	 << "C: " << test.numberOf('C') << "   " << "T: " << test.numberOf('T') << endl;
    cout << test.longestConsecutive() << endl;
    finish = clock();
    cout << (double)(finish-start)/CLOCKS_PER_SEC << endl;
    cout << test.longestRepeated() << endl;
    finish = clock();
    cout << (double)(finish-start)/CLOCKS_PER_SEC << endl;
    return 0;
}
