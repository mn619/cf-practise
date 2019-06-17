#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

ll gcd(ll x,ll y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}

int main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y;
		cin>>x>>y;
		if(gcd(x,y)!=1)cout<<"NOT GOOD\n";
		else cout<<"GOOD\n"; 
}	}


