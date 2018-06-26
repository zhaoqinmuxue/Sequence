#include <iostream>
#include "Sequence.h"
#include <ctime>

using namespace std;

int main()
{
    clock_t start,finish;
    start = clock();
    Sequence test("dna.txt");
    // for (int i = 0;i < test.DNA.size();i++)
    // cout << test.DNA[i];
    cout << endl;
    cout << "A: " << test.A << "  " << "G: " << test.G << "  " << "C: " << test.C << "  " << "T: " << test.T << endl;
    for (int i = test.zui_s;i < test.zui_e;i++)
    cout << test.DNA[i];
    cout << endl;
    finish = clock();
    cout << (double)(finish-start)/CLOCKS_PER_SEC << endl;
    return 0;
}
