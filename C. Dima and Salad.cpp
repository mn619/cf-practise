#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[101], b[101];

map < pair<int, int>, int> dp;

signed main()
{
	FILEIO
 	FLASH
	
 	cout<<100<<" "<<1<<'\n';
 	fr(i,1,101) cout<<100<<" ";
 	cout<<'\n';
 	fr(i,1,101) cout<<100<<" ";
	return 0;
	
	cin>>n>>k;

	fr(i,1,n + 1) cin>>a[i];
	fr(i,1,n + 1) {cin>>b[i]; b[i] *= k;}


	dp[{0,0}] = 0;
	fr(i,1,n + 1)
	{
		fr(j,-100000,10001)
		{
		    if(dp.count({i - 1, j})) dp[{i,j}] = dp[{i - 1, j}];
		    if(dp.count({i - 1, j - (a[i] - b[i])}))
		    {
		        if(dp.count({i,j}))
		        {
		            dp[{i,j}] = max(dp[{i,j}], a[i] + dp[{i - 1, j - (a[i] - b[i])}]);
		        }
		        else dp[{i,j}] = a[i] + dp[{i - 1, j - (a[i] - b[i])}];
		    }   
			//dp[{i,j}] = max(dp[{i - 1, j}], a[i] + dp[{i - 1, j - (a[i] - b[i])}]);
		}
	}
	if(dp.count({n,0}))cout<<dp[{n,0}]<<'\n';
	else cout<<-1;
}