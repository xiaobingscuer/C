
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;

/*
	Î»Í¼ 
	ÂÒÐò 
*/ 

const int nmax=10000000;
int a[nmax];

void permute(int* a, int n)
{
	for (int i = n; i > 0; i--)
	{
		swap(a[i-1], a[rand()%i]);
	}
}

void inita(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i; 
	}
	
	permute(a, n);
}

char* bitmap(const int* a, int n)
{
	int N = (n + 7) / 8;
	char* M = new char[N];
	
	memset(M,0,N);
	
	return M;
}

void set(char* M, int k)
{
	M[k >> 3] |= (0x80 >> (k & 0x07));
}

void clear(char* M, int k)
{
	M[k >> 3] &= ~(0x80 >> (k & 0x07));
}

bool test(char* M, int k)
{
	return M[k >> 3] & (0x80 >> (k & 0x07));
}

char* bitstostring(char* M, int n)
{
	char* s = new char[n+1];
	
	for (int i = 0; i < n; i++)
	{
		s[i] = (test(M, i)) ? '1' : '0';
	}
	
	s[n] = '\0';
	
	return s;
}

void printa(const int* a, int n)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
}

void printstr(char *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c", s[i]);
		if(i % 8 == 7)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main(){
	
	char* M = NULL;
	char* s = NULL;
	clock_t t;
	
	inita(a, nmax);
	
	printa(a, 10);
	
	M = bitmap(a, nmax);
	
	t = clock();
	
	for (int i = 0; i < nmax; i++)
	{
		set(M, a[i]);
	}
	
	t = clock()-t;
	printf ("bitmap took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	
	s = bitstostring(M, nmax);
	
	printstr(s, 17);
	
	delete[] M; M=NULL;
	delete[] s; s=NULL;
	
	t = clock();
	
	sort(a, a+nmax);
	
	t = clock()-t;
	printf ("qsort took me %d clicks (%f seconds).\n", t, ((float)t)/CLOCKS_PER_SEC);
	
	printa(a, 10);
	
	return 0;
}

