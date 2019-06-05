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

struct seg
{
	int l, r;
};


bool comp(seg s1, seg s2)
{
	if(s1.l != s2.l) return (s1.l < s2.l);
	else return (s1.r < s2.r);
}

void solve()
{
	int n;
	cin>>n;

	seg m[n + 1];
	map <pair<int, int>, int> ans;

	int l = 0;
	int i;
	int ll[n + 1], r[n + 1];
	fr(i,1,n + 1)
	{
		int x,y;
		cin>>x>>y;
		ll[i] = x, r[i] = y;
		m[i].l = x;
		m[i].r = y;
	}

	sort(m + 1, m + n + 1, comp);

	int cnt = 0;
	
	fr(i,1,n + 1)
	{

	}
	
	fr(i,1,n + 1)
	{
		cout<<ans[{ll[i],r[i]}]<<" ";
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