#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair

using namespace std;

int n;
int a[500001];


signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	int f[n+1]={0},b[n+1]={0};
	int sum=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]+a[i];
		sum+=a[i];
	}	
	if(sum%3!=0)
	{
		cout<<0;
		return 0;
	}
	int k=0;
	
	for(int i=n;i>=1;i--)
	{
		k+=a[i];
		if(k==sum/3)b[i]=1;
		else b[i]=0;
	}
	
	int bs[n];
	bs[n]=b[n];
	
	for(int i=n-1;i>=1;i--)bs[i]=bs[i+1]+b[i];

	int ans=0;
	
	for(int i=1;i<=n-2;i++)
	{
		if(f[i]==sum/3)
		{
			ans+=bs[i+2];
		}
	}
	
	cout<<ans;
}


