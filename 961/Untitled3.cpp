#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int a[n+1],m[n+1],s[n+1]={0};
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	
	int t[n+1];
	for(int i=1;i<=n;i++)
	{
		
		cin>>t[i];
		if(t[i]==0)m[i]=a[i];
		else m[i]=0;
		s[i]=s[i-1]+m[i];
	}
	
	ll ans=0,mt=0;
	for(int i=k;i<=n;i++)
	{
		ll x=s[i]-s[i-k];
		if(mt<x){mt=x;}
	}
	
	ans=mt;
	
	for(int i=1;i<=n;i++)
	{
		if(t[i])ans+=a[i];
	}
	
	cout<<ans;
	
	
	
}

