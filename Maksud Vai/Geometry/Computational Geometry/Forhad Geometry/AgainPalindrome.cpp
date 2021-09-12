/*
Problem Statement:
  
Note to plugin users: This problem statement contains images.
Farmer John has several pastures, each of which can be described as several
overlapping and/or touching rectangles. For instance, the pasture in the picture
 below can be considered as the union of the rectangles (2,2)-(10,5) and (7,1)-(9,7).
  Two rectangles that only touch each other in a corner aren't counted as touching
  or overlapping rectangles, see example 4.

Farmer John wants to enclose all his pastures with fences (one fence for each pasture).
 Help him find out the total length of all fences if all the borderlines must be
 fenced (see example 2).Create a class Fences containing the method fenceLength that
  takes a vector <int> x1, a vector <int> y1, a vector <int> x2 and a vector <int> y2,
   describing the rectangles that make up the pastures by overlapping and/or touching,
    and returns an int, the total length of all fences. Element i in x1, y1, x2 and y2
     describe one rectangle with the opposite corners x1,y1 and x2,y2.
Definition
    
Class:
Fences
Method:
fenceLength
Parameters:
vector <int>, vector <int>, vector <int>, vector <int>
Returns:
int
Method signature:
int fenceLength(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)
(be sure your method is public)
    

Constraints
-
x1, y1, x2 and y2 will contain between 1 and 50 elements, inclusive.
-
x1, y1, x2 and y2 will all contain the same number of elements.
-
Each element in x1, y1, x2 and y2 will be between 0 and 1000, inclusive.
-
Element i in x1 will differ from element i in x2.
-
Element i in y1 will differ from element i in y2.
Examples
0)

    
{0,3,5,15}
{0,3,7,4}
{7,5,10,20}
{5,8,9,8}
Returns: 60
Here we have four rectangles that together describes two pastures, as rectangles 0 and 1 intersect and rectangles 1 and 2 touch each other.
1)

    
{100,80}
{200,230}
{50,90}
{250,205}
Returns: 200
x2 and y2 might be greater than x1 and y1.
2)

    
{10,30,20,10}
{10,10,10,40}
{20,40,40,30}
{40,40,20,30}
Returns: 160
These four rectangles form a single pasture with a hole in the middle. Since there must be fences along the borders, there must both be an "outer" fence (length 120) and an "inner" fence (length 40).
3)

    
{976,823,228,463,702,515,690,252,153,
 525,260,356,435,369,942, 59,605,173,
 178, 70,420, 40,705, 38,841,430,965,
 312,680,188,982,160,395,219,340,225}
{314,759, 67,232,815,882,211,839, 48,
 531,567,803,439,418,968, 74, 88,834,
 806,920,920,194,602,436,624,331,314,
  68,421,659,653, 99,921,339,865,408}
{835,794,980, 90,808,649,198,334,309,
 749,187,965,578,199,655,273,503,489,
 167,996,212,355, 34,430,749,527,109,
 501,380, 36,641,872, 47,157,433, 85}
{306,421,283,413,466,747,882,297,790,
 576,695,102,655,121, 82,400, 36,236,
 143,108,862,400,357,386,790,732,  4,
 800,316,166,239,242,121, 57,111, 85}
Returns: 3854

4)

    
{1,5}
{1,5}
{5,10}
{5,10}
Returns: 36
The two rectangles only touch each other at one corner, and are thus considered as different pastures.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 1000

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int mat[SIZE][SIZE];

class Fences
{
public:
	int fenceLength(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2)
	{
	    int i,j,k,sum,count,len,x3,y3,x4,y4,x,y;

	    memset(mat,false,sizeof(mat));
	    len=x1.size();
	    for(i=0;i<len;i++)
	    {
            x3=min(x1[i],x2[i]);
            y3=min(y1[i],y2[i]);
            x4=max(x1[i],x2[i]);
            y4=max(y1[i],y2[i]);
            for(j=x3;j<x4;j++)
                for(k=y3;k<y4;k++)
                    mat[j][k]=true;
        }
        for(i=sum=0;i<SIZE;i++)
            for(j=0;j<SIZE;j++)
            {
                if(mat[i][j])
                {
                    for(k=count=0;k<4;k++)
                    {
                        x=i+dx[k];
                        y=j+dy[k];
                        if(x>=0 && x<SIZE && y>=0 && y<SIZE)
                        {
                            if(mat[x][y]==false)
                                count++;
                        }
                        else count++;
                    }
                    sum+=count;
                }
            }
        return sum;
	}
};
