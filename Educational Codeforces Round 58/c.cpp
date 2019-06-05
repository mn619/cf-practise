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
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

void solve()
{
	int n;
	cin>>n;

	map <pair<int, int>, int> m;
	map <int, int> ans;

	int l = 0;
	int i;
	int ll[n + 1], r[n + 1];

	fr(i,1,n + 1)
	{
		int x,y;
		cin>>x>>y;
		ll[i] = x, r[i] = y;
		m[{x,0}]++;
		m[{y,1}]++;
	}

	if(n == 1)
	{
		cout<<1<<"\n";
		return;
	}
	int cnt = 0;

	for(auto it: m)
	{

		if(it.first.second == 0)
		{
			if(l == 0)
			{
				ans[it.first.first] = !cnt;
				cnt = !cnt;
			}
			else ans[it.first.first] = cnt;
		}

		if(it.first.second == 0)
		{
			l+= m[it.first];
		}
		else l-=m[it.first];

		//cout<<it.first.first<<" "<<it.first.second<<" "<<l<<' '<<cnt<<'\n';
		

	}

	int ok = 0;

	fr(i,2,n + 1)
	{
		if(ans[ll[i]] != ans[ll[1]]) ok = 1; 
	}
	if(!ok)
	{
		cout<<-1<<'\n';
		return;
	}
	fr(i,1,n + 1)
	{
		cout<<ans[ll[i]] + 1<<" ";
	}
	cout<<endl;
}
signed main()
{
	//FILEIO
 	start_routine
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		solve();
	}

 	//end_routine
}