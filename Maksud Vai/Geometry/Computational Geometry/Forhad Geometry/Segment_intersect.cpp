//here only function. p1,p2,p3,& p4 are points such as pi=(xi,yi);
//this function determine whether two line(p1p2 and p3p4) segments intersect.
//using coreman algorithms books

int Segments_Intersect(vector<int>p1,vector<int>p2,vector<int>p3,vector<int>p4)
{
	int d1,d2,d3,d4;
	
	d1=Direction(p3,p4,p1);
	d2=Direction(p3,p4,p2);
	d3=Direction(p1,p2,p3);
	d4=Direction(p1,p2,p4);
	
	if( ((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)) )
		return true;
	else if( d1==0 && On_Segment(p3,p4,p1) )
		return true;
	else if( d2==0 && On_Segment(p3,p4,p2) )
		return true;
	else if( d3==0 && On_Segment(p1,p2,p3) )
		return true;
	else if( d4==0 && On_Segment(p1,p2,p4) )
		return true;
	else return false;

}

int Direction(vector<int>pi,vector<int>pj,vector<int>pk)
{
	vector<int>p,q;
	
	p.push_back(pk[0]-pi[0]);
	p.push_back(pk[1]-pi[1]);
	q.push_back(pj[0]-pi[0]);
	q.push_back(pj[1]-pi[1]);
	
	return p[0]*q[1]-p[1]*q[0];
}

int On_Segment(vector<int>pi,vector<int>pj,vector<int>pk)
{
	if( ( (min(pi[0],pj[0]) <=pk[0]) && (pk[0]<=max(pi[0],pj[0])) ) && ( (min(pi[1],pj[1]) <=pk[1]) && (pk[1]<=max(pi[1],pj[1])) ) )
		return true;
	return false;
}