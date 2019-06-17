#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
char c[1001][1001];
int cnt[1001][1001][26];
int dp[1001][1001], lenc[1001][1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>m;
	fr(i, 1, n + 1){
		fr(j, 1, m + 1){
			cin>>c[i][j];
			cnt[i][j][c[i][j] - 'a'] = 1 + cnt[i - 1][j][c[i][j] - 'a'];
		}
	}
	int ans = 0;

	fr(j, 1, m + 1){
		fr(i, 2, n){
			int u = i;
			int l = i;
			while(c[l + 1][j] == c[u][j]) l++;
			int len = (l - u + 1);
			lenc[i][j] = len;
			if(u > len and  n - l >= len){
				if(cnt[u - 1][j][c[u - 1][j] -'a'] - cnt[u - len - 1][j][c[u - 1][j] - 'a'] == len
					and cnt[l + len][j][c[l + 1][j] -'a'] - cnt[l][j][c[l + 1][j] - 'a'] == len
					)
				{
					//ans += dp[i][j - 1][!(j&1)] + 1;
					if(c[u - 1][j] != c[u][j] and c[l + 1][j] != c[l][j]){
						dp[i][j] = 1;
						if(c[i][j] == c[i][j - 1] and lenc[i][j] == lenc[i][j - 1]
							and cnt[u - 1][j - 1][c[u - 1][j] -'a'] - cnt[u - len - 1][j - 1][c[u - 1][j] - 'a'] == len
								and cnt[l + len][j - 1][c[l + 1][j] -'a'] - cnt[l][j - 1][c[l + 1][j] - 'a'] == len
							)
							dp[i][j] += dp[i][j - 1];
					}

					ans += dp[i][j];
				}
			}
			
			//cout<<j<<" "<<u<<" "<<l<<' '<<dp[i][j]<<" "<<ans<<'\n';
			i = l;
		}
	}

	cout<<ans;

}