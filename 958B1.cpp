#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n+1]={0};
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u]++;
		a[v]++;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)ans++;
	}
	
	cout<<ans;
}

