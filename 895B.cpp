#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int bs(ll x,ll l, ll r, ll a[])
{
	int m=(l+r)/2;
	
	if(a[m]==x) return m;
	
	if(l-r==0) return 0;
	
	if(a[m]>x)return bs(x,l,m-1,a);
	if(a[m]<x)return bs(x,m+1,(r),a);
	
}

int main()
{
	ll n,x,k;
	cin>>n>>x>>k;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		int kk=x*(k)+a[i];
		int l=lower_bound(a,a+n,kk),u=upper_bound(a,a+n,kk);
	
		if(bs(kk,0,n-1,a))ans+=u-l+1;;
		
	}
	cout<<ans;
}

