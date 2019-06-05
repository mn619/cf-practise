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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	//FILEIO
 	//start_routine
	int n;
	cin>>n;
	int a[n + 1], b[n + 1];
	vector <int> v[n + 1];
	int i;

	fr(i,1,n + 1)
	{
		cin>>a[i]>>b[i];
		v[i].pb(b[i]);
	}

	int ans = 0;
	fr(i,1,n +1)
	{
		int j;
		fr(j,1,n + 1)
		{
			if(j == i) continue;
			int k;
			bool ok = 0;
			fr(k,0,v[j].size())
			{
				if(v[j][k] == a[i]) 
				{
					ans++;
					ok = 1;
					break;
				}
			}
			if(ok)break;
		}
	}
	cout<<n - ans<<'\n';
 	//end_routine
}
