#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sequence
{
    public:
        vector<char> DNA;
        int A;
        int G;
        int C;
        int T;
	int zui_s;
 	int zui_e;
    public:
        Sequence(char* failname);
        ~Sequence(){}
};

#endif
