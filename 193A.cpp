#include<bits/stdc++.h>
#define ll long long int
using namespace std;




int main()
{
	ll n,m;
	cin>>n>>m;
	if(log2(m)+1<n) cout<<m;
	else
	{
		ll k=pow(2,n);
		cout<<m%k;
	}
}
