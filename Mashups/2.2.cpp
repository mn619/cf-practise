#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	ll ans=0;
	int a[n+1][m+1];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int  i=1;i<=n;i++)
	{
		int t=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)t++;
		}
		
		ans+=pow(2,t)-1;
	}
	
	for(int  i=1;i<=m;i++)
	{
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1)t++;
		}
		
		ans+=pow(2,t)-1;
	}
	
	for(int  i=1;i<=n;i++)
	{
		int t=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0)t++;
		}
		
		ans+=pow(2,t)-1;
	}
	
	for(int  i=1;i<=m;i++)
	{
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==0)t++;
		}
		
		ans+=pow(2,t)-1;
	}
	
	cout<<ans-n*m;
}

