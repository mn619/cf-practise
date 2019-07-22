#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int dp[2][501][501];
int c[501], lsum[501], rsum[501];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, m + 1){
 		int x;
 		cin>>x;
 		c[x] = i;
 	}

 	dp[0][1][n] = 1;

 	fr(i, 1, m + 1){
 		lsum[i] = lsum[i - 1] + 
 	}
 	fr(i, 1, n + 1){

 		fr(l, 1, c[i]){
 			fr(j, c[i], m + 1){

 			}
 		}
 	}
 	
}