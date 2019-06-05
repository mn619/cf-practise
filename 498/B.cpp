#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,k,a[2001];

signed main()
{
 	//start_routine
	cin>>n>>k;
	int i;
	fr(i,1,n+1)cin>>a[i];
	
	vector <int> v[n+1];
	fr(i,1,n+1)
	{
		v[i].pb(a[i]);
		v[i].pb(i);
	}
	sort(v+1,v+n+1);

	reverse(v+1,v+n+1);
	if(k==1)
	{
		cout<<v[1][0]<<"\n"<<n;
		return 0;
	}
	bool in[n+1] = {0};

	fr(i,1,k+1)
	{
		in[v[i][1]] = 1;
	}
	int j = 0,ans=0;
	fr(i,1,n+1)
	{
		if(in[i])
		{
			ans+=a[i];
		}
	}
	cout<<ans<<"\n";
	fr(i,1,n+1)
	{
		if(in[i] && k>1)
		{
				cout<<i-j<<" ";
				j = i;
				k--;
		}
	}
	cout<<n-j;
  	//end_routine
}



