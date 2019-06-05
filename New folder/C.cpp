#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,k,l;
	cin>>n>>k>>l;
	int a[n*k];
	f(0,n*k)cin>>a[i];
	
	
	sort(a,a+n*k);
	if(n==1){cout<<a[0]; return 0;}
	vector<int> b[n];
	int t=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			b[i].pb(a[t++]);
		}
	}
	
	for(int i=0;i<n;i++) sort(b[i].begin(),b[i].end());
	
	int min=a[0];
	bool bo=0;

	queue <int> q;
	
	for(int i=n-1;i>=0;i--)
	{
		if(b[i][0]-min<=l){bo=1; break;}
		bool to=0;
		vector <int>::iterator it;
		
		for(int j=i-1;j>=0;j--)
		{
			it=lb(b[j].begin(),b[j].end(),min+l);
			if(*it-min==l)
			{
				int xxx=(it-b[j].begin());
				swap(b[j][xxx],b[i][0]);
				sort(b[j].begin(),b[j].end()); 
				to=1;
				break;
			}
			else if(it!=b[j].begin())
			{
				it--;
				int xxx=it-b[j].begin();
				swap(b[j][xxx],b[i][0]);
				sort(b[j].begin(),b[j].end());
				to=1;
				break;
			}
		}
		if(to==0)break;
	}
	int ans=0;
	
	if(bo)
	{
		for(int i=0;i<n;i++)
		{
			ans+=b[i][0];
		}
	}
	cout<<ans;
}


