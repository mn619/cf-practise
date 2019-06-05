#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

ll f(ll n,ll k,ll a,ll b, ll ans, vector <ll> v[2])
{
	
	
	if(n<k){ return ans+(n-1)*a;}
	if(n==k && b<=(k-1)*a) {return ans+b;}
	if(n==k && b>(k-1)*a){return ans+(k-1)*a;}
	
	for(int i=0;i<v[0].size();i++)
	{
		if(v[0][i]==n)return v[1][i];
	}
	
	if(n%k!=0) {ll xx=n%k; (xx<0)?xx+=k:xx=xx; ll x= f(n-xx,k,a,b,ans+(xx)*a,v); v[0].pb(n); v[1].pb(x); return x;}
	
	if(b>(n-n/k)*a) {
	ll x=f(n/k,k,a,b,ans+(n-n/k)*a,v); v[0].pb(n); v[1].pb(x); return x;}
	
	{ll x=f(n/k,k,a,b,ans+b,v); v[0].pb(n); v[1].pb(x); return x;}
	
}

int main()
{
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	vector <ll> v[2];
	if(k==1)  {cout<<(n-1)*a; return 0;} 
	cout<<f(n,k,a,b,0,v);
	
}

