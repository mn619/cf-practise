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

	int n,t,c;
	cin>>n>>t>>c;
	
	int k;
	int len=0,ans=0;
	
	f(0,n)
	{
		cin>>k;
		if(k<=t) len++;
		else len=0;
		if(len>=c) ans++;
	}
	cout<<ans;
}



