#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
#define point pair<ll,ll>
#define x first
#define y second

bool f1(vector <point> v)
{
	if(v.size()<=2)return true;
	point p1=v[0],p2=v[1];
	bool b=1;
	for(int i=2;i<v.size();i++)
	{
		if((p2.y-p1.y)*(v[i].x-p1.x)!=(v[i].y-p1.y)*(p2.x-p1.x))
		{
			b=0; break;
		}
	}
	
	return b;
}

bool f(point p1, point p2, point p[], int n)
{
	vector <point> v;
	
	for(int i=1;i<=n;i++)
	{
		if((p2.y-p1.y)*(p[i].x-p1.x)!=(p[i].y-p1.y)*(p2.x-p1.x)) v.pb(pair<int,int> (p[i].x,p[i].y));
	}
	
	return f1(v);
}

int main()
{
	int n;
	cin>>n;
	if(n<=3) 
	{
		cout<<"YES";
		return 0;
	}
	
	point p[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	
	bool b=0;
	
	if(f(p[1],p[2],p,n)||f(p[2],p[3],p,n)||f(p[1],p[3],p,n))b=1;
	
	if(b)cout<<"YES";
	else cout<<"NO";
	
}

