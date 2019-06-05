#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)

using namespace std;

signed main()
{
 //	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	string ans="NO\n";
	char c[n][m];
	
	vector <int> v[m];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j]; 
			
			if(c[i][j]=='1')
			{
				v[j].pb(i);
			}
		}
	}
	//cout<<v[0].size()<<"\n;";
	
	for(int i=0;i<n;i++)
	{
		bool b=0;
		for(int j=0;j<m;j++)
		{
			if(c[i][j]=='1') if(v[j].size()==1)b=1;
		}
		
		if(b==0)
		{
			ans="YES\n";
			break;
		}
	}
	
	cout<<ans;
	
}


