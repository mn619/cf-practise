#include<bits/stdc++.h>
#define int long long
#define inf 1000000000
#define maxn 200000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int dp[5001][5001][2];

signed main()
{
	FILEIO 

	int n;
	cin>>n;

	if(n == 1) return cout<<"0\n", 0;

	int a[n + 1];
	for(int i = 1; i <= n; i++) cin>>a[i];

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = inf;
	
	dp[1][0][1] = dp[1][1][1] = 0;
	dp[2][1][0] = (a[2] >= a[1]? a[2] - a[1] + 1: 0);
	dp[2][1][1] = (a[1] >= a[2]? a[1] - a[2] + 1: 0);

	for(int i = 3; i <= n; i++) {
		dp[i][1][0] = min(dp[i - 1][1][0], dp[i - 1][1][1] + (a[i] >= a[i - 1]? a[i] - a[i - 1] + 1: 0));
		dp[i][1][1] = (a[i] <= a[i - 1]? a[i - 1] - a[i] + 1: 0);
		for(int j = 2; j <= (i + 1)/2; j++) {
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + (a[i] >= a[i - 1]? a[i] - a[i - 1] + 1: 0));
				dp[i][j][1] = min(dp[i - 2][j - 1][0] + (a[i] <= a[i - 1]? a[i - 1] - a[i] + 1: 0), dp[i - 2][j - 1][1] + (a[i - 1] >= min(a[i - 2], a[i])?  a[i - 1] - min(a[i - 2], a[i]) + 1: 0));
		}
	}

	for(int i = 1; i <= (n + 1)/2; i++) cout<<min(dp[n][i][0], dp[n][i][1])<<" ";
}
