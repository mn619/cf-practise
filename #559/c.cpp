#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, b[100001], g[100001];
int lef[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1) cin>>b[i];
 	fr(i, 1, m + 1) cin>>g[i];

 	sort(b + 1, b + n + 1);
 	sort(g + 1, g + m + 1);

 	int ans = 0;

 	fr(i, 1, n + 1){
 		if(b[i] > g[1]) return cout<<-1, 0;
 	}

 	int p = n;
 	fr(i, 1, m + 1){
 		while(b[n] > g[i] and p > 1){
 			p--;
 		}
 		ans += g[i];
 		lef[p]--;
 	}

 	if(lef[n] == -m){
 		bool ok = 0;
 		fr(i, 1, m + 1){
 			if(g[i] == b[n]) ok = 1;
 		}
 		if(!ok){
 			lef[n]++;
 			lef[n - 1]--;
 		}
 	}

	fr(i, 1, n + 1){
		ans += b[i]*(m + lef[i]);
	}

	cout<<ans;
 	
}	