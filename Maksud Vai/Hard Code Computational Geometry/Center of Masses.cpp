pair<double,double> CenterOfMess(P p[],int n)
{
    int i;
    double X,Y,area;

    ///n = convexHull(p,n); //Calculate ConvexHull;

    X = Y = 0;
    p[n].x=p[0].x;
    p[n].y=p[0].y;


    area=0;
    for(i=0;i<n;i++)
        area+=(p[i].x*p[i+1].y -p[i+1].x*p[i].y );
    area = fabs(area);
    area*=3;
    for(i=0;i<n;i++){
        X+=(p[i].x+p[i+1].x) * (p[i].x*p[i+1].y -p[i+1].x*p[i].y ) ;
        Y+=(p[i].y+p[i+1].y) * (p[i].x*p[i+1].y -p[i+1].x*p[i].y ) ;
    }

    X /=area;     Y/=area;

    return make_pair(X,Y);
}



