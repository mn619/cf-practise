#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

ll gcd(ll p,ll q)
{
	if(q==0)return p;
	else return gcd(q,p%q);
}

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin>>n;
	ll a=1234567,b=123456,c=1234;
	//cout<<gcd(a,b)<<" "<<gcd(b,c)<<" "<<gcd(a,c);
	string ans="NO";
	
	for(int i=0;i<=n/a;i++)
	{
		for(int j=0;j<=n/b;j++)
		{
			if(n-a*i-b*j>=0&&(n-a*i-b*j)%c==0)
			{
				ans="YES";break;
			}
		}
	}
	
	cout<<ans;
	
}


