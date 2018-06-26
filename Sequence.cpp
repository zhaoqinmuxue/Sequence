#include "Sequence.h"

Sequence::Sequence(char* filename):A(0),G(0),C(0),T(0),zui_s(0),zui_e(0)
{
    ifstream fin(filename);
    char ch;
    char tap;
    int t_s = 0,t_e = 0;
    fin.get(ch);
            switch(ch)
            {
            case 'A':A++;break;
            case 'G':G++;break;
            case 'C':C++;break;
            case 'T':T++;break;
            default:break;
            }
            DNA.push_back(ch);
    tap = ch;

    while(fin.get(ch))
    {
        if (ch!='\n')
        {
            switch(ch)
            {
            case 'A':A++;break;
	    case 'G':G++;break;
	    case 'C':C++;break;
   	    case 'T':T++;break;
            default:break;
	    } 
	    DNA.push_back(ch);
            t_e++;
            if (tap == ch)
            continue;
            else
            {
                if (t_e-t_s > zui_e-zui_s)
	 	{zui_e = t_e;zui_s = t_s;}
		t_s=t_e;
                tap = ch;
	    }
	}
    }
    fin.close();
}
