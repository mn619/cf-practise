#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int C[2001][2001] = {{1}};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	
 	fr(i, 1, 2001){
 		fr(j, 0, i + 1){
 			if(j == 0) {C[i][j] = 1; continue;}
 			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
 			C[i][j] %= mod;
 		}
 	}

 	fr(i, 1, 2001) fac[i] = (fac[i - 1]*i)%mod;
 	while(t--){
 		int n, m;
 		cin>>n>>m;

 		cout<<C[n + m - 1][n]<<'\n';
 	}
}