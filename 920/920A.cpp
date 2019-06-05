#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	for(;t>0;t--)
	{
		int n,k;
		cin>>n>>k;
		
		int a[k+1];
		
		cin>>a[1];
		
		for(int i=2;i<=k;i++)
		{
			cin>>a[i];
		}
		int t=a[1];
		int ans=t;
		
		for(int i=2;i<=k;i++)
		{
			int k=a[i]-t+1;
			if(k%2)
			{
				if(k/2+1>ans) ans=k/2+1;
			}
			else if(k/2>ans) ans=k/2;
			t=a[i];
		}
		
		if(n-a[k]+1>ans) ans=n-a[k]+1;
		
		cout<<ans<<endl;
	}
}

