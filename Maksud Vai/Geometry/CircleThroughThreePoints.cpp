
void CircleThroughThreePoints(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double A,B,C,k,g,f,H,K,Y1,Y2,X1,X2,r,c,d,e;

    A = x1 * x1 + y1 * y1 ;	B = x2*x2 + y2*y2 ; C = x3*x3 + y3*y3 ;
    X1 = x1-x2;		X2 = x2-x3;   Y1 = y1-y2;   Y2 = y2-y3;
    g = ( Y2 *( B-A) - Y1*(C-B) ) / ( 2 * (X1*Y2 - X2*Y1) );
    f = (B - A - (2 * g * X1) ) / ( 2 * Y1);
    k = - A - 2 * g * x1 - 2 * f * y1;

    H = -g ;   K = -f ;  r = sqrt(g*g +f*f - k);

    //printf("Center(%lf, %lf)\nRadius: %lf\n",H,K,r);
}

