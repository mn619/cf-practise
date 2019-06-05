#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
	
const int N = 5000;

int n, a, b, k, dp[N + 1][N + 1];
int t[N + 1];


int queri(int l, int r){
	return (t[r] - t[l - 1] + mod)%mod;;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>a>>b>>k;

 	dp[0][a] = 1;

 	fr(i, a, n + 1){
 		t[i] = 1;
 	}

 	fr(i, 1, k + 1){
 		fr(j, 1, n + 1){
 			if(j < b){
 				dp[i][j] += queri(1, (b + j - 1)/2) - dp[i - 1][j];
 			}
 			else if(j > b){
 				dp[i][j] += queri((j + b)/2 + 1, n) - dp[i - 1][j];
 			}
 			dp[i][j] %= mod;
 		}

 		fr(j, 1, n + 1){
 			t[j] = (dp[i][j] + t[j - 1])%mod; 
 		}
 	}

 	int ans = 0;
 	fr(i, 1, n + 1){
 		ans += dp[k][i];
 		ans %= mod;
 	}
 	ans += mod;
 	cout<<ans%mod;
}