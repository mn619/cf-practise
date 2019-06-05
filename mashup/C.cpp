#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
int t,n,a[101][2]={{0}},xxx[101][101][101];
void read()
{
	cin>>t;
}

void solve()
{

	ll ans=0;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		
		
		for(int j=0;j<n;j++)
		{
			
		int x,y,z;
		
		cin>>x>>z>>y;
		
		if(!a[y][1])
		{
			a[y][0]=x;
			a[y][1]=z;
			ans+=(z-x)*y;
		}
		else
		{
			if(x<a[y][0]&&z<a[y][1])
			{
				ans+=(a[y][0]-x)*y;
				a[y][0]=x;
			}
			else if(a[y][0]<x&&a[y][1]<z)
			{
				ans+=y*(z-a[y][1]);
				a[y][1]=z;
			}
			else if(a[y][0]>x && a[y][1]<z)
			{
				ans+=y*(a[y][0]-x)+y*(z-a[y][0]);
				a[y][0]=x;
				a[y][1]=z;
			}
		}
		}
	cout<<ans;		
	}
	
}
int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	solve();
}


