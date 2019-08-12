#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m;

void solv(){
	cin>>n>>m;

	char c[n + 1][m + 1];
	int rows[n + 1], clm[m + 1];


	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= m; j++){
			cin>>c[i][j];
			if(c[i][j] == '*') cnt++;
		}
		rows[i] = cnt;
	}

	for(int j = 1; j <= m; j++){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(c[i][j] == '*') cnt++;
		}

		clm[j] = cnt;
	}
	
	int ans = n + m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans = min(ans, n + m - 1 - (rows[i] + clm[j] - (c[i][j] == '*')));
		}
	}

	cout<<ans<<'\n';


}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	
 	int q;
 	cin>>q;

 	while(q--) solv();
}