#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

class Sequence{
	public:
		Sequence(const char *filename);
		int length();
		int numberOf(char base);
		int comlen(const char *a,const char *b);
		string longestConsecutive();
		string longestRepeated();
		string total; 

};
#endif
