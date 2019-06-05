#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int c[m+1],a[n+1]={0};
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		a[c[i]]++;
		bool b=1;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==0){b=0; break;}
		}
		
		if(b)
		{
			for(int j=1;j<=n;j++)
			{
				a[j]--;
			}
			ans++;	
		}
		
		
		
	}
	
	cout<<ans<<"\n";
	
	
}

