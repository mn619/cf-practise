#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
vector <ll> v[1000];
int n;
ll solve(int k[], int j)
{
	ll x,y;
	int ans=0;
	for(int i=0;i<k[j]-1;i++)
	{
		x=v[j][i];
		y=v[j][i+1];
		int k=(j-1)%n, a,b;
		(k<0)?k+=n:k=k;
		
		vector <ll>::iterator ub;
		
		a=(upper_bound(v[k].begin(),v[k].end(),x)-upper_bound(v[k].begin(),v[k].end(),y));
		k=(j+1)%n;
		(k<0)?k+=n:k=k;
		
		
		b=(upper_bound(v[k].begin(),v[k].end(),x)-upper_bound(v[k].begin(),v[k].end(),y));
		//else y=(v[k].size())-(lb-v[k].begin());
	
	
	
		if(a!=b) ans++;
	}
	
	return ans;
}
int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	
	int k[n];
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		ll arr[k[i]];
		
		for(int j=0;j<k[i];j++)
		{
			cin>>arr[j];
		}
		
		sort(arr,arr+k[i]);
		//v[i].pb(0);
		for(int j=0;j<k[i];j++)v[i].pb(arr[j]);
		
	}
	
//	cout<<v[0][0]<<" "<<v[0][1]<<" "<<v[0][2]<<"\n\n";
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=solve(k,i);
	}
	
	cout<<ans;
	
}


