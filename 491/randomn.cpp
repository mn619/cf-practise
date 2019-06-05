#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define f(p,n) for(ll i=p;i<n;i++)
using namespace std;
ll exp(ll a,ll b,ll m);
ll n;

bool ch(ll c)
{
	if(c==0) return 0;
	ll c1=n;
	ll an=0;
	ll p=0;
	while(c1>0)
	{
		if(p%2==0)
		{
			ll k=min(c1,c);
			an+=k;
			c1-=k;
		}
		else
		{
			c1-=(c1)/10;
		}
		p++;
		if(an>=ceil(double(n)/2)) return 1;
	}
	if(an>=ceil(double(n)/2)) return 1;
	else return 0;
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
		cin>>n;
		if(n==1) return cout<<1<<endl,0;
		ll s=1,e=1+n/2;ll m;
		
		/*f(1,n+1) cout<<ch(i)<<" ";
		cout<<endl;*/
		
		while(s<=e)
		{
		//	cout<<s<<" "<<e<<endl;
			m=(s+e)/2;
			if(ch(m)==1) 
			{
				if(s==e || s==m || e==m) return cout<<m<<endl,0;
				
				
				if(ch(m-1)==0)	return cout<<m<<endl,0;
				e=m-1;
				continue;
			}
			else
			{
				s=m+1;
			}
		}
		cout<<m<<endl;
	
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}
