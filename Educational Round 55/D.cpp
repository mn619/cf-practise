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

int n, a[501];
vector <int> v[501];

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;
	int k = 0, l  = 0;
	while(tests--)
	{
		cin>>n;
		int i;
		fr(i,1,n+1)
		{
			cin>>a[i];
			if(a[i] == 1) k++;
			else l+=a[i];
			v[i].pb(a[i]);
			v[i].pb(i);
		}
		if(l < 2*(n - 1) - k)
		{
			cout<<"NO\n";
			return 0;
		}
		sort(v + 1, v + 1 + n);
		int n1 = v[1][1], n2 = v[2][1];

		int las = n1;
		reverse(v + 1, v + 1 + n);

		priority_queue< pair<int,int> > pq;

		vector < pair<int,int> > ans;
		fr(i,1,n-1)
		{
			int d = v[i][0], node = v[i][1];
			if(d>1)
			{
				ans.pb({las, node});
				a[las]--;
				a[node]--;
				pq.push({a[node], node});
				las = node;
			}
			else break;
		}
		a[las]--;
		a[n2]--;
		ans.pb({las, n2});

		fr(i,i,n-1)
		{
			int node = v[i][1];
			int las = pq.top().second;


			ans.pb({las, node});
			a[node]--;
			a[las]--;
			if(a[las] == 0)
			{
				pq.pop();
			}
		}

		cout<<"YES "<<min(n-k+1, n - 1)<<'\n';
		cout<<ans.size()<<"\n";

		int len = ans.size();
		fr(i,0,len)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}

 	//end_routine
}
