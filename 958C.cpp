#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	ll n;
	ll p;
	
	cin>>n>>p;
	ll a[n];
	ll b[n];
	cin>>a[0];
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		b[i]=(a[i]+b[i-1]);
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll s1=b[i]%p;
		ll s2=(b[n-1]-b[i])%p;
		if(s1+s2>ans)ans=s1+s2;
	}
	
	cout<<ans<<endl;
}

