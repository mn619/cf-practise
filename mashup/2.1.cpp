#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector <ll> v[n];
	
	for(int i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		v[i].pb(k);
		v[i].pb(i);
	}
	
	sort(v,v+n);
	
	int k=0;
	
	bool vst[n];
	int c[n];
	
	for(int i=0;i<n;i++)
	{
		int x=v[i][1];
		
		if(!vst[x])
		{
			vst[x]=1;
			c[k]=1;
			
			while(x!=i)
			{
				x=v[x][1];
				vst[x]=1;
				c[k]++;
			}
			k++;
		}
	}
	
	cout<<k<<endl;
	
	for(int i=0;i<n;i++)vst[i]=0;
	
	k=0;
	
	for(int i=0;i<n;i++)
	{
		int x=v[i][1];
		
		if(!vst[x])
		{
			vst[x]=1;
			cout<<c[k]<<" "; k++;
			cout<<x+1<<" ";
			while(x!=i)
			{
				x=v[x][1];
				vst[x]=1;
				cout<<x+1<<" ";
			}
			cout<<endl;
		}
	}
	

}

