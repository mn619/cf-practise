#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

bs(ll a[],ll b,int l,int r)
{
	if(l==r)return l;
	int mid=(l+r)/2;
	if(a[mid]>=b && a[mid-1]<b)return mid;
	if(a[mid]>b)return bs(a,b,l,mid-1);
	return bs(a,b,mid+1,r);
}

void solve(ll a[],ll b,int n)
{
	int k=bs(a,b,1,n);
	
	{
		cout<<k<<" "<<b-a[k-1];
	}
	cout<<endl;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	
	ll a[n+1],b[m];
	a[0]=0;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]+a[i-1];
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		solve(a,b[i],n);
	}
	
	
}

