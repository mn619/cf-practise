#include<bits/stdc++.h>
#define int long long
#define maxn 500000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k, p[6][1001], inv[5][1001];
int dp[1001];

signed main(){
	FILEIO
	cin>>n>>k;

	for(int i = 0; i < k; i++){
		for(int j = 1; j <= n; j++){
			cin>>p[i][j];
			if(i == 0){
				inv[i][p[i][j]] = j;
			}
			else{
				p[i][j] = inv[0][p[i][j]];
				inv[i][p[i][j]] = j;
			}
		}
	}
	
	k--;
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			bool ok = 1;
			for(int l = 1; l <= k; l++){
				if(inv[l][j] > inv[l][i])
					ok = 0;
			}

			if(ok){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}


	cout<<ans<<'\n';

	
}
