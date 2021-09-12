/*
Problem Statement
    
NOTE: This problem statement contains an image that may not display properly if viewed outside of the applet.
Given a list of two-dimensional rectangles, compute the area of their union. For example, the union of the three rectangles shown in the figure below:

cover an area of 35 units.
The list of rectangles will be given as a vector <string>, where each element describes one rectangle. Each string will be formatted as 4 space-separated integers with no leading zeros, giving the coordinates of the left, bottom, right, and top of the rectangle (in that order). The three rectangles shown above would be given as:
    { "1 3 5 6",
      "3 1 7 5",
      "4 4 9 7" }
Definition
    
Class:
BoxUnion
Method:
area
Parameters:
vector <string>
Returns:
int
Method signature:
int area(vector <string> rectangles)
(be sure your method is public)
    

Constraints
-
rectangles will contain between 1 and 3 elements, inclusive.
-
Each element of rectangles will be formatted as described in the problem statement.
-
For each rectangle, the left coordinate will be less than the right coordinate and the bottom coordinate will be less than the top coordinate.
-
All coordinates will be between 0 and 20000, inclusive.
Examples
0)

    
{ "200 300 203 304" }
Returns: 12
A single rectangle with area 12.
1)

    
{ "0 0 10 10",
  "20 20 30 30" }
Returns: 200
Two disjoint rectangles, each of area 100.
2)

    
{ "0 500 20000 501",
  "500 0 501 20000" }
Returns: 39999
These two rectangles intersect at a single point.
3)

    
{ "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" }
Returns: 10000
The third rectangle completely overlaps the first two.
4)

    
{ "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" }
Returns: 35
This is the example from the problem statement.
5)

    
{ "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" }
Returns: 400000000

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

/*

//Source Code
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

class BoxUnion
{
public:
	int area(vector <string> rect)
	{
	    int i,j,k,area,len,R[3][4],X[4];

	    len=rect.size();
	    for(i=area=0;i<len;i++)
	    {
            istringstream iss;
            iss.str(rect[i]);
            iss>>R[i][0]>>R[i][1]>>R[i][2]>>R[i][3];
            area+=(R[i][2]-R[i][0])*(R[i][3]-R[i][1]);
        }

        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                X[0]=max(R[i][0],R[j][0]);
                X[1]=max(R[i][1],R[j][1]);
                X[2]=min(R[i][2],R[j][2]);
                X[3]=min(R[i][3],R[j][3]);
                if(X[2]>=X[0] && X[3]>=X[1])
                    area-=((X[2]-X[0])*(X[3]-X[1]));
            }
        }

        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                for(k=j+1;k<len;k++)
                {
                    X[0]=max(R[i][0],max(R[j][0],R[k][0]));
                    X[1]=max(R[i][1],max(R[j][1],R[k][1]));
                    X[2]=min(R[i][2],min(R[j][2],R[k][2]));
                    X[3]=min(R[i][3],min(R[j][3],R[k][3]));
                    if(X[2]>=X[0] && X[3]>=X[1])
                        area+=((X[2]-X[0])*(X[3]-X[1]));
                }
            }
        }
        return area;
	}
};
