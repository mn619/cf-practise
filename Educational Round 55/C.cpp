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

vector <int> v[100001];

int s[100001], r[100001];
int cnt[100001] = {0}, sum[100001] = {0};
int ans[100001] = {0};

signed main()
{
	//FILEIO
 	//start_routine

	int n,m;
	cin>>n>>m;
	int i;
	fr(i,1,n+1)
	{
		int a,b;
		cin>>a>>b;
		s[i] = a;
		r[i] = b;
		v[i].pb(b);
		v[i].pb(a);
	}
	sort(v + 1, v+n+1);
	reverse(v +1, v+n+1);
	fr(i,1,n+1)
	{
		int a,b;
		a = v[i][1];
		b = v[i][0];
		cnt[a]++;
		sum[a] += b;
		if(sum[a] > 0)
		{
			ans[cnt[a]] += sum[a];
		}
	}
	int a = 0;
	fr(i,1,n+1)
	{
		a = max(ans[i], a);
	}
	cout<<a<<"\n";
 	//end_routine
}
