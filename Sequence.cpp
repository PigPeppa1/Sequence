#include"Sequence.h"
#include<algorithm>
const int N=1200000;
char temp_kp[N],*pos[N];

//cmp函数用于将后缀数组排成按字典顺序。
int cmp(const void *a,const void *b) {
	return strcmp(*(char* const*)a,*(char* const*)b);
}

Sequence::Sequence(const char *filename) {
	ifstream data(filename,ios_base::in);
	string _line;
	while(getline(data,_line))
		total=total+_line;
}

int Sequence::length() {
	return total.length();
}

int Sequence::numberOf(char base) {
	int a1=0,a2=0,a3=0,a4=0;
	int x=total.length();
	for(int i=0; i<x; i++) {
		switch(total[i]) {
			case 'A':
				a1++;
				break;
			case 'T':
				a2++;
				break;
			case 'C':
				a3++;
				break;
			case 'G':
				a4++;
				break;
		}
	}
	if(base=='A')return a1;
	if(base=='T')return a2;
	if(base=='C')return a3;
	if(base=='G')return a4;
}

//comlen函数用于求出相邻已排好序的数组的公共前缀。
int Sequence::comlen(const char *p,const char *q) {
	int all=0;
	while(*p&&(*p++==*q++)) {
		all++;
	}
	return all;
}

string Sequence::longestConsecutive() {
	int tempa=1,maxlen=0;
	int x=total.length();
	char base;
	for(int i=0; i<x-1; i++) {
		if(total[i+1]==total[i]) {
			tempa++;
		} else {
			if(tempa>maxlen) {
				maxlen=tempa;
				base=total[i];
			}
			tempa=1;
		}
	}
	string s;
	for(int i=0;i<maxlen;i++)
		s=s+base;
	return s;
}

//解题方法参考自:https://www.cnblogs.com/biyeymyhjob/archive/2012/08/15/2639572.html
string Sequence::longestRepeated() {
	string lort;
	int maxl=-1,position=0;
	int length=total.length();
	memcpy(temp_kp,total.c_str(),length);//将字符串total转化成以char储存。
	for(int i=0; i<length; i++) {
		pos[i]=&temp_kp[i];
	}
	qsort(pos,length,sizeof(char *),cmp);//按字典顺序将后缀数组排序。
	for(int i=0; i<length-1; i++) {
		if(comlen(pos[i],pos[i+1])>maxl) {
			maxl=comlen(pos[i],pos[i+1]);
			position=i;
		}
	}
	char trans[100001];
	strncpy(trans,pos[position],maxl);
	trans[maxl+1]='\0';
	lort=trans;
	return lort;
}

