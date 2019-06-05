#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007

using namespace std;
ll powers[600000+1];
ll p=101;

precompute()
{
	ll k=p;
	powers[0]=1;
	for(int i=1;i<=600000;i++)
	{
		powers[i]=(powers[i-1]*k)%mod;
		k=(k*p)%mod;
	}
}

int bs(ll a[],ll k, int l,int r)
{
	int mid=(l+r)/2;
	if(a[mid]==k)return mid;
	if(r-l<=0)return -1;
	
	if(k<a[mid])return bs(a,k,l,mid-1);
	return bs(a,k,mid+1,r);
}

ll  h1(string s)
{
	ll p=101;
	ll ans=0,k=p;
	for(int i=0;i<s.size();i++)
	{
		ans=(ans+powers[i]*(s[i]-'a'+1))%mod;
	}
	return ans%mod;
}


int main()
{
	int n,m;
	cin>>n>>m;
	
	ll a[n];
	string s;
	precompute();
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		a[i]=h1(s);
	}
	
	sort(a,a+n);
	
	for(int k=0;k<m;k++)
	{
		
		cin>>s;
	
		bool t=0;
		
		for(int i=0;i<s.size();i++)
		{
			char c=s[i];
			ll x=h1(s);
			
			for(int j=0;j<2;j++)
			{
				int ch=s[i]-'a'+1;
				if(int(s[i])==99) s[i]='a';
				else s[i]++;
				x=(x+((s[i]-'a'+1-ch)*powers[i])%mod)%mod;
				
				int xyz=bs(a,x,0,n-1);
				
				if(xyz!=-1)
				{
						t=1; break;
				}
			}
			s[i]=c;
			
				if(t)break;
			
		}
		
		if(t)cout<<"YES\n";
		else cout<<"NO\n";
	}
}

