
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cfloat>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	
*/ 

int randi(int lo, int hi)
{
	int r = 0;

	if(hi - lo > RAND_MAX || lo >= hi)
		return -1;
		
	r = rand() % (hi - lo);
	
	return lo + r;
}

int randib(int lo, int hi)
{
	int r = 0, p = 0, q = 0, k = 0;

	if(hi > INT_MAX || hi - lo > RAND_MAX*RAND_MAX || lo >= hi)
		return -1;
			
	if((hi - lo) < RAND_MAX)
	{
		return randi(lo, hi);
	}
	else
	{
		p = (hi - lo) / RAND_MAX;
		q = (hi - lo) % RAND_MAX;
		k = rand() % (p + 1);
		
		if(k == p)
		{
			r = rand() % q;
		}
		else
		{
			r = rand();
		}
	}
		
	return lo + k*RAND_MAX + r;
}

int randibb(int lo, int hi)
{
	int r = 0, p = 0, q = 0, k = 0;
	
	if(hi > INT_MAX || lo >= hi)
		return -1;
		
	if(hi - lo < RAND_MAX*RAND_MAX)
	{
		return randib(lo, hi);
	}
	else
	{
		p = (hi - lo) / (RAND_MAX*RAND_MAX);
		q = (hi - lo) % (RAND_MAX*RAND_MAX);
		k = rand() % (p + 1);
		
		if(k == p)
		{
			r = randib(0, RAND_MAX*RAND_MAX) % q; 
		}
		else
		{
			r = randib(0, RAND_MAX*RAND_MAX);
		}
		
	}

	return lo + k*RAND_MAX*RAND_MAX + r;
}

double randd(double lo, double hi)
{
	double r=0.0f;
	
	if(lo >= hi)
		return -1;
		
	r = (double)rand()/(RAND_MAX+1.0);
	
	return lo + r*(hi - lo);
}

int main()
{
	srand(time(NULL)); 
	
	int size = 100;
	double r1 = 0.0;
	int r2 = 0;
	int a[size];
	
	for(int i = 0 ; i < size ; i++)
	{
		r2 = randibb(0, 10);
//		r2 = randi(RAND_MAX, 2*RAND_MAX);

		
		a[i] = r2;
		
//		printf("%d\n", r2);
	}
	
	//printf("%3d\n", randi(0, INT_MAX));
	sort(a,a+size);
	
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d\n", a[i]);
	}
	
	printf("%d %d %d\n", 2*32767*32767, INT_MAX, 1*RAND_MAX*RAND_MAX);
	
	return 0;
}

