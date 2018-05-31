#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
struct Point
{
    int x, y,index;
};

long double distance(int x1,int y1,int x2,int y2)
{
	long double ans;
	x1=abs(x1-x2);
	y1=abs(y1-y2);
	y1*=y1;
	x1*=x1;
	ans=x1+y1;
	return sqrt(ans);
	
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}
 
vector<Point> convexHull(Point points[], int n)
{
	vector<Point> hull;
    if (n < 3) return hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].y < points[l].y || (points[i].y==points[l].y && points[i].x<points[l].x))
            l = i;
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
        	int res=orientation(points[p], points[i], points[q]);
           	if (res== 2)
               q = i;
        	else if(res==0)
        	{
        		if(distance(points[i].x,points[i].y,points[p].x,points[p].y)>distance(points[q].x,points[q].y,points[p].x,points[p].y))
        		q=i;       		
			}
        }
        p = q;
 
    } while (p != l);
 
    return hull;
}

bool mySort(Point &a,Point &b)
{
	if(a.y==b.y)
	return a.x<b.x;
	else
	return a.y<b.y;
}

bool normal(const Point &a, const Point &b) {
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

bool issame(const Point &a, const Point &b) {
	return (a.x == b.x && a.y == b.y);
}

int main()
{
	int test,n,i,res;
	long double sum;
	cin>>test;
	while(test--)
	{
		sum=0;
		cin>>n;
		Point points[n];
		vector<Point> v;
		for(i=0;i<n;i++)
			{
				cin>>points[i].x>>points[i].y;
				points[i].index=i+1;
			}
		sort(points, points+n, normal);
		n = unique(points, points+n, issame) - points;
		if(n==1)
		{
			cout<<"0.00\n"<<points[0].index<<endl;
			continue;
		}
		else if(n==2) 
		{
			sum =2*distance(points[0].x , points[0].y , points[1].x , points[1].y);
			sum=sum+EPS;
			cout<<fixed;
    		cout<<setprecision(2);
    		cout<<sum<<endl;
			cout<<points[0].index<<" "<<points[1].index<<endl;
			continue;
		}
		v=convexHull(points, n);
		res=v.size();
		for(i=0;i<res;i++)
		{
			if(i+1<res)
			sum+=distance(v[i].x , v[i].y , v[i+1].x , v[i+1].y);
			else
			sum+=distance(v[i].x , v[i].y , v[0].x , v[0].y);
		}
		
		sum=sum+EPS;
		cout<<fixed;
    	cout<<setprecision(2);
    	cout<<sum<<endl;
		for(i=0;i<res;i++)
		{
			cout<<v[i].index<<" ";
		}
		cout<<endl;
	}
    return 0;
}

