/*#include<bits/stdc++.h>
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

string s;
int dp[701][701][4][4];

int solve(int l, int r, int cl, int cr)
{
	if(dp[l][r][cl][cr] != 0) return dp[l][r][cl][cr];
	
}

signed main()
{
	FILEIO
 	//start_routine
	cin>>s;
	int n = s.size();

	int ans = solve(0,n - 1,0,1) + solve(0, n- 1,1,0) + solve(0, n - 1, 0, 2) + solve(0, n - 1, 2, 0);
 	cout<<ans<<'\n';
 	//end_routine
}
