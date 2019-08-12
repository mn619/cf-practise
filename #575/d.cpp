#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200010

using namespace std;

int n, k, a[maxn + 1], dp[maxn + 1][3];
string s;


void solv(){
	cin>>n>>k>>s;

	fr(i, 0, s.size()){
		if(s[i] == 'R'){
			a[i] = 0;
		}
		else if(s[i] == 'G'){
			a[i] = 1;
		}
		else a[i] = 2;
	}

	fr(i, 0, n){
		fr(j, 0, 3){
			dp[i][j] = 0;
			if(i > 0)dp[i][j] = dp[i - 1][j];
			if(a[i] != (i + j)%3){
				dp[i][j]++;
			}
		}
	}

	int ans = min(dp[k - 1][0], min(dp[k - 1][1], dp[k - 1][2]));
	fr(i, k, n){
		ans = min(ans, min(dp[i][0] - dp[i - k][0], min(dp[i][1] - dp[i - k][1], dp[i][2] - dp[i - k][2])));
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
 	while(q--)solv();
 		
}