/*
	Problem: Given you a dataset. There are reg no.,name,mark. At first you 
	sort by mark. Which mark is greater he is in top. If two candidate marks
	are equal then you sort by reg no. Which student reg no is small then he/she 
	top in the list. If also reg. no are equal then you sort lexicographically
	 sort by their name.Example:
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

typedef struct
{
	int reg,mark;
	char str[20];
}student;

student cse[60];

int comp(const void *a,const void *b);

int main()
{
	int n,i;

	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",cse[i].str,&cse[i].reg,&cse[i].mark);
		}
		qsort(cse,n,sizeof(student),comp);
		for(i=0;i<n;i++)
		{
			printf("%s %d %d\n",cse[i].str,cse[i].reg,cse[i].mark);
		}
	}
	return 0;
}

int comp(const void *a,const void *b)
{
	student *x = (student *) a;
	student *y = (student *) b;
	if(x->mark==y->mark)
	{
		if(x->reg==y->reg)
		{
			return strcmp(x->str,y->str);
		}
		else  return x->reg - y->reg;
	}
	else return y->mark - x->mark;
}

/*
Samle Input:				Sample Output:
12						Mukta 8 90
Forkan 52 80				Mahfuj 24 90
Opu 21 85					Mahfuz 42 90
Mahfuz 42 90				shishir 1 86
Asu 60 85					Opu 21 85
Maksud 6 76					Asu 60 85
Mukta 8 90					Samir 5 83
Tethy 57 80					Forhad 52 80
Samir 5 83					Forkan 52 80
shishir 1 86				Tethy 57 80
Asif 48 76					Maksud 6 76
Mahfuj 24 90				Asif 48 76
Forhad 52 80
*/