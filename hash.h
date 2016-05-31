#ifndef HASHING_H
#define HASHING_H
#include<string.h>
#include<cstring>
#include<stdio.h>
using namespace std;

int Hashing_Function(string s)
{
	int i,sum=0,len=0,index=0;
	len=s.length();
	for(i=0;i<=len;i++ )
	{
		sum = sum + s[i];
	}
	index=sum%26;
	return index;
}

#endif
