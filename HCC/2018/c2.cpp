#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
int n, k, p, dp[2][51][101];
bool in[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k>>p;
 	in[0] = 1;

 	fr(i, 1, 51){
 		fr(j, 1, 100){
 			dp[0][i][j] = -inf;
 		}
 	}
 	dp[0][0] = 0;

 	fr(i, 1, n + 1){
 		int x;
 		cin>>x;
 		x %= p;
		fr(j, 0, k + 1){
			fr(l, 0, p){
				
			}
 		}
 	}
}