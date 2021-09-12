/*
Problem Statement
    	
You are given the coordinates of several vertices in space. Each vertex is colored 'R', 
'G' or 'B'. You are to determine the maximum possible area of a triangle such that all 
three of its vertices are the same color, or all three of its vertices are different colors.

You are given a String[] points describing the vertices. Each element of points will 
be in the form "color x y z", where color is 'R', 'G', or 'B', and x, y, z are integers with no leading zeroes.

 
Definition
    	
Class:	FindTriangle
Method:	largestArea
Parameters:	String[]
Returns:	double
Method signature:	double largestArea(String[] points)
(be sure your method is public)
    
 
Notes
-	A triangle with all three vertices colinear, or two vertices overlapping, has area 0.
-	Returned value must be within 1.0e-9 absolute or relative error.
 
Constraints
-	points will have between 5 and 50 elements, inclusive.
-	Each element of points will be formatted as "color x y z" (quotes added for clarity).
-	Each color will be 'R', 'G', or 'B'.
-	Each x, y and z will be an integer between 0 and 999, inclusive, with no leading zeros.
 
Examples
0)	
    	
{"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "G 92 14 7",
 "G 12 16 8"}
Returns: 6.0
The coloring restrictions mean that we can only consider the first three points, 
which form a classic 3-4-5 triangle with an area of 6.
1)	
    	
{"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "G 0 5 0",
 "B 0 0 12"}
Returns: 30.0
Our bet here is to take the red point at the origin, the green point, and the blue point.
 These actually form a 5-12-13 triangle. Area = 30.
2)	
    	
{"R 0 0 0",
 "R 0 4 0",
 "R 0 0 3",
 "R 90 0 3",
 "G 2 14 7",
 "G 2 18 7",
 "G 29 14 3",
 "B 12 16 8"}
Returns: 225.0
We have a lot more choices here.
3)	
    	
{"R 0 0 0",
 "R 1 1 0",
 "R 4 4 0",
 "G 10 10 10",
 "G 0 1 2"}
Returns: 0.0
All three red points are colinear.
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

typedef struct
{
    double x,y,z;
}point;
double ABS(point a)
{
    return sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z));
}
point CAB(point a ,point b)     //Cross Vector between a and b vector
{
    point r;
    r.x=a.y*b.z-a.z*b.y;
    r.y=a.z*b.x-a.x*b.z;
    r.z=a.x*b.y-a.y*b.x;
    return r;
}

class FindTriangle
{
public:
	double largestArea(vector <string> points)
	{
	    int i,j,k,r;
	    double maxv;

	    r=points.size();
	    maxv=0;
	    for(i=0;i<r;i++)
            for(j=i+1;j<r;j++)
                for(k=j+1;k<r;k++)
                    maxv=max(maxv,tri_area(i,j,k,points));
        return maxv;
	}
	double tri_area(int i,int j,int k,vector<string>points)
	{
        double x1,y1,z1,x2,y2,z2,x3,y3,z3;
        double area;
        point a,b,c,ba,bc;
        char c1,c2,c3;

        istringstream iss;
        iss.str(points[i]);
        iss>>c1>>x1>>y1>>z1;
        a.x=x1;a.y=y1;a.z=z1;

        iss.clear();
        iss.str(points[j]);
        iss>>c2>>x2>>y2>>z2;
        b.x=x2;b.y=y2;b.z=z2;

        iss.clear();
        iss.str(points[k]);
        iss>>c3>>x3>>y3>>z3;
        c.x=x3;c.y=y3;c.z=z3;

        if(((c1==c2) && (c1==c3) && (c2==c3)) ||((c1!=c2) && (c1!=c3) && (c2!=c3)))
        {
            ba.x=a.x-b.x; ba.y=a.y-b.y; ba.z=a.z-b.z;
            bc.x=c.x-b.x; bc.y=c.y-b.y; bc.z=c.z-b.z;
            area=ABS(CAB(ba,bc))/2.0;
            return area;
        }
        return 0;
    }
};
