#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	map <string,int> mymap;
	map <string, int> :: iterator it;
	
	string s[n+1];
	ll c[n+1];
	int g[n+1];
	
	ll grpc[k+1];
	
	
	
	
	
	for(int i=1;i<=n;i++) {cin>>s[i]; mymap.insert(pair <string,int> (s[i],i));}
	
	for(int i=1;i<=n;i++) cin>>c[i];
	
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		ll min=1000000001;
		
		for(int j=1;j<=x;j++)
		{
			int z; 
			cin>>z;
			
			if(c[z]<min)min=c[z];
			
			g[z]=i;
			
		}
		grpc[i]=min;
	}
	
	string msg[m+1];
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>msg[i];
		it=mymap.lower_bound (msg[i]);
		ans+=grpc[g[it->second]];
	}
	
	cout<<ans;
	
}

