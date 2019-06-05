#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	
	cin>>n>>m;
	
	int a[n+1];
	
	f(1,n+1)
	{
		cin>>a[i];
	}
	
	map <int,int> mp;
	
	int ans[n+1];
	
	for(int i=n;i>=1;i--)
	{
		
		mp[a[i]]=1;
		ans[i]=mp.size();
	}
	
	f(1,m+1)
	{
		int k;
		cin>>k;
		cout<<ans[k]<<"\n";
	}
}


