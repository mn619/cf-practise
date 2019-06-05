#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)

using namespace std;
bool solve(int a[],int n,int k,int d)
{
	cout<<n<<"\t"<<a[n-1]-a[0]<<"\n";
	int r=INT_MAX;
	int minind=-1;
	if(n<=k&&a[n-1]-a[0]<=d)return 1;
	if(n<=k)return 0;
	
	for(int i=0;i<=n-k;i++)
	{
		r=min(r,a[k+i-1]-a[i]);
		if(r<=d)minind=i;
	}
	
	int b[n-k];
	if(minind!=-1)
	{
		int t=0;
		for(int j=0;j<n;j++)
		{
			if(j==minind)
			{
				j=minind+k;
			}
			
			b[t++]=a[j];
		}
	}
	return solve(b,n-k,k,d);
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,k,d;
	cin>>n>>k>>d;
	
	int a[n];
	
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	
	bool b =solve(a,n,k,d);
	
	if(b)cout<<"YES";
	else cout<<"NO";
}


