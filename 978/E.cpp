#include<bits/stdc++.h>
#define ll long long int


using namespace std;

signed main()
{
	ll n,w;
	cin>>n>>w;
	
	ll a[n+1];
	a[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	
	sort(a+1,a+1+n);
	ll k1=a[1];
	ll k2=a[n];
	
	if(k1>0)k1=0;
	k1=-k1;
	if(k2>=0) (w-k2-k1+1>=0)?cout<<w-k2-k1+1:cout<<0;
	
	else
	{
		if(w-k1>=0)cout<<w-k1+1;
		else cout<<0;
	}
}

