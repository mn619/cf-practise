#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

char a[2001][2001];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	int c=0;
	ll ans=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='.') 
			{
				c++;
				if(c>=k) ans+=1;
			}
						
			if(a[i][j]=='*')
			{
				c=0;
			}
			
		}
		c=0;

	}
	c=0;
	
	
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
		
			if(a[i][j]=='.') 
			{
				c++;
				if(c>=k) ans+=1;
			}
			
			if(a[i][j]=='*')
			{
				c=0;
			}
		}
		c=0;
	}
	
	cout<<ans<<endl;
}

