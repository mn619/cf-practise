#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)
#define mp make_pair

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	
	map<pair <int,int> ,int >m;
	
	
	int x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{			
			if(m[mp(y[i]+y[j],x[i]+x[j])])m[mp(y[i]+y[j],x[i]+x[j])]++;
			else m[mp(y[i]+y[j],x[i]+x[j])]=1;
		}
	}
	
	
	map < pair<int,int> ,int>::iterator it=m.begin();
	int ans=0;
	int i=m.size();
	while(i--)
	{
		int x=it->second;
		//cout<<it->first.first<<" "<<it->first.second<<" "<<x<<"\n";
		ans+=x*(x-1)/2;
		it++;
	}
	
	cout<<ans;
}


