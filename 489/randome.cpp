#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

ll gcdd(ll a,ll b)
{
	if(a==0) return b;
	return gcdd(b%a,a);
}

/*ll gc(ll a, ll b, ll *x, ll *y)
{
   
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll g = gc(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return g;
}*/

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll l,r,x,y;
	cin>>l>>r>>x>>y;
	if(y%x!=0) return cout<<0<<endl,0;
	
	ll n=y/x;
	ll p=y*x;
	ll g;
	ll ans=0;
	ll m=sqrt(p);
	if(l>m) return cout<<0<<endl,0;
	ll s=max(l,p/r);
	if(r>=y && l<=x)
	{
	ll count=0;
	if (!(n%2))
    {
        count++;
        while (!(n%2))
            n /= 2;
    }
 	
    for (ll i = 3; i*i <= n; i = i+2)
    {
        
        if (!(n%i))
        {
            count++;
            while (!(n%i))
                n /= i;
        }
    }
 
    if (n > 2)
        count++;
        
        ans= 1<<count;
        cout<<ans<<endl;
        return 0;
   }
        
    s=max(x,s);  
	f(s,m+1)
	{
		if(p/i >r) continue;
		
		//cout<<"sjcn"<<endl;
		if(!(p%i))
		{	g=gcdd(i,p/i);
			if(g==x) ans++;
		}
	}
	ans*=2;
	if(m<=r)
	{
		if(p%m!=0 && m==x) ans--;
	}
	
	
    
	cout<<ans<<endl;
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
