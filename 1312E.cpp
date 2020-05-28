#include<bits/stdc++.h>
#define inf 100000000
#define int long long
#define double long double
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n;
vector <int> a(501), dp1(501);
vector <vector<int>> dp(501, vector <int>(501));

signed main()
{
	FILEIO
	FLASH
	cin>>n;

	for(int i = 1; i <= n; i++)
		cin>>a[i];

	for(int l = 0; l < n; l++){
		for(int i = 1; i + l <= n; i++){
			int j = i + l;
			if(l == 0){
				dp[i][j] = a[i];
				continue;
			}
			dp[i][j] = -1;
			for(int k = i; k < j; k++){
				if(dp[i][k] == dp[k + 1][j] and dp[i][k] != -1)
					dp[i][j] = dp[i][k] + 1;
			}
		}
	}
	
	for(int i = 1;  i <= n; i++){
		dp1[i] = inf;
		for(int j = 1; j <= i; j++)
			if(dp[j][i] != -1)
				dp1[i] = min(dp1[i], dp1[j - 1] + 1);
	}

	cout<<dp1[n]<<'\n';

}
