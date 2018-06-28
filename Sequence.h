#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

class Sequence
{
    private:
        char* DNA;
        char** a;
        int counts;
        int A;
        int G;
        int C;
        int T;
	int zui_s;
 	int zui_e;
    public:
        Sequence(string failname);
        ~Sequence(){delete[] DNA,a;}
        int length()	{return counts;}
        int numberOf(char base);
        string longestConsecutive();
        string longestRepeated();
};

#endif
