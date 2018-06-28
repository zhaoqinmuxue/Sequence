#include "Sequence.h"

bool compare(const char* a,const char* b)
{
    return strcmp(a,b) < 0;
}

int comlen(char* a,char* b)
{
    int i = 0;
    do{
    	if (a[i]!=b[i])
    	break;
	i++;
    }while(a[i]!='\0' && b[i]!='\0');
    return i;
}

Sequence::Sequence(string filename):counts(0),A(0),G(0),C(0),T(0),zui_s(0),zui_e(0)
{
    DNA = new char[1200000];
    a = new char*[1200000];
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
	DNA[counts] = ch;
	a[counts] = &DNA[counts];
	counts++;
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
	    DNA[counts] = ch;
	    a[counts] = &DNA[counts];
	    counts++;
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

int Sequence::numberOf(char base)
{
    switch(base)
    {
        case 'A': return A;break;
        case 'G': return G;break;
        case 'C': return C;break;
	case 'T': return T;break;
	default:  return 0;break;
    }
}

string Sequence::longestConsecutive()
{
     char* temp = new char[zui_e-zui_s+1];
     strncpy(temp,a[zui_s],zui_e-zui_s);
     temp[zui_e-zui_s] = '\0';
     string longest = temp;
     delete[] temp;
     return longest;
}

string Sequence::longestRepeated()
{
    int maxpos = 0,maxlen = 0;
    sort(a,a+counts,compare);
    for (int i = 1;i < counts;i++)
    {
    	int temp = comlen(a[i-1],a[i]);
    	if (temp > maxlen)
	{
	    maxpos = i;
	    maxlen = temp;
	}
    }
    char* temp = new char[maxlen+1];
    strncpy(temp,a[maxpos],maxlen);
    temp[maxlen] = '\0';
    string longest = temp;
    delete[] temp;
    return longest;
}
