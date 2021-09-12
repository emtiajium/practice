/*
Problem Statement
    	You have a convex polygon. You select three consecutive vertices and create a
    	triangle with them. Remove this triangle from the polygon (if you had a polygon
    	 with N vertices, the resulting polygon would have N-1 vertices). Repeat this
    	 process until the remaining polygon is a triangle.



You are given a String[] vertices, representing the vertices of the polygon in clockwise
 order. Each element will be formatted as "X Y", where X and Y are the coordinates of a
 vertex. Return a double representing the area of the largest possible triangle that can
 remain at the end.

Definition

Class:	BestTriangulation
Method:	maxArea
Parameters:	String[]
Returns:	double
Method signature:	double maxArea(String[] vertices)
(be sure your method is public)


Notes
-	The returned value must be accurate to 1e-9 relative or absolute.

Constraints
-	vertices will contain between 3 and 35 elements, inclusive.
-	Each element of vertices will be formatted as "X Y", where X and Y are integers
without leading zeroes.
-	Each X and Y will be between 1 and 10000, inclusive.

Examples
0)

{"1 1", "2 3", "3 2"}
Returns: 1.5
The polygon is already a triangle, so you cannot perform any cuts.
1)

{"1 1", "1 2", "3 3", "2 1"}
Returns: 1.5
Here you must perform one cut. If you cut vertices (3, 0, 1), a triangle of area 1.5
will remain. If you cut vertices (0, 1, 2), a triangle of area 1 will remain. If you cut
 vertices (1, 2, 3), a triangle of area 0.5 will remain. If you cut vertices (2, 3, 0),
 a triangle of area 1 will remain. Your best option is to cut (3, 0, 1).
2)

{"1 2", "1 3", "2 4", "3 4", "4 3", "4 2", "3 1", "2 1"}
Returns: 3.0
In such an 8-gon, you must cut the following triangles in order: (7, 0, 1), (7, 1, 2),
(2, 3, 4), (4, 5, 6), (4, 6, 7). Finally, a triangle with vertices (2, 4, 7) is left,
and its area is 3.
3)

{"6 2", "2 1", "1 2", "1 4", "2 6", "5 6", "6 5"}
Returns: 10.0
4)

{"10000 3469", "9963 712", "9957 634", "9834 271", "9700 165",
 "9516 46", "8836 4", "1332 57", "229 628", "171 749",
 "52 1269", "30 1412", "7 4937", "35 8676", "121 9917",
 "2247 9960", "3581 9986", "6759 9995", "9486 9998", "9888 9890",
 "9914 9318", "9957 8206", "9998 6402"}
Returns: 4.8292483E7
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

class BestTriangulation
{
public:
	double maxArea(vector <string> points)
	{
	    int i,j,k,r;
	    double maxv=0;

	    r=points.size();
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

        istringstream iss;
        iss.str(points[i]);
        iss>>x1>>y1;
        a.x=x1;a.y=y1;a.z=0;

        iss.clear();
        iss.str(points[j]);
        iss>>x2>>y2;
        b.x=x2;b.y=y2;b.z=0;

        iss.clear();
        iss.str(points[k]);
        iss>>x3>>y3;
        c.x=x3;c.y=y3;c.z=0;

        ba.x=a.x-b.x; ba.y=a.y-b.y; ba.z=a.z-b.z;
        bc.x=c.x-b.x; bc.y=c.y-b.y; bc.z=c.z-b.z;
        area=ABS(CAB(ba,bc))/2.0;
        return area;
    }
};
