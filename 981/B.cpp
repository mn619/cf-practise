#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n;
	map <int,int> cf;
	map <int,int> cc;
	map <int,bool> total;
	int temp,temp2;
	for(int i=0;i<n;i++)
	{
		cin>>temp>>temp2;
		cf[temp]=temp2;
		total[temp]=1;
	}
	
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>temp>>temp2;
		cc[temp]=temp2;
		total[temp]=1;
	}
	map <int,bool> ::iterator it=total.begin();
	
	int ans=0;
	while(1)
	{
		ans+=max(cf[it->first],cc[it->first]);
		it++;
		if(it==total.end())break;
	}
	
	cout<<ans;
	
	
}


