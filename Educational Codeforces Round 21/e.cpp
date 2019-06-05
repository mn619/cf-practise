#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
#define maxn 300001

int n, m;
int a[maxn], b[maxn], c[maxn];
int p1[maxn], p2[maxn], p3[maxn], dp[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	int p = 0, q = 0, r = 0;
 	for(int i = 1; i <= n; i++){
 		int w, cost;
 		cin>>w>>cost;
 		if(w == 1)a[++p] = cost;
 		else if(w == 2) b[++q] = cost;
 		else c[++r] = cost;
 	}

 	sort(a + 1, a + p + 1);
 	reverse(a + 1, a + p + 1);

 	sort(b + 1, b + q + 1);
 	reverse(b + 1, b + q + 1);

 	sort(c + 1, c + r + 1);
 	reverse(c + 1, c + r + 1);
	
	fr(i, 1, r + 1) c[i] += c[i - 1];

	p1[1] = 1;
	dp[1] = a[1];

	dp[2] = max(a[1] + a[2], b[1]);
	if(dp[2] == a[1] + a[2]){
		p1[2] = 2;
	}
	else p2[2] = 1;
	
	fr(i, 3, m + 1){
		int x = p1[i - 1] + 1, y = p2[i - 1];

		dp[i] = dp[i - 1] + a[p1[i - 1] + 1];
		if(dp[i] < dp[i - 2] + a[p1[i - 2] + 1] + a[p1[i - 2] + 2]){
			x = p1[i - 2] + 2;
			y = p2[i - 1];
			dp[i] = dp[i - 2] + a[p1[i - 2] + 1] + a[p1[i - 2] + 2];
		}
		if(dp[i] < dp[i - 2] + b[p2[i - 2] + 1]){
			x = p1[i - 2], y = p2[i - 2] + 1;
			dp[i] = dp[i - 2] + b[p2[i - 2] + 1];
		}

		p1[i] = x;
		p2[i] = y;
	}

	int ans = 0;
	fr(i, 1, m + 1){
		dp[i] = max(dp[i - 1], dp[i]);
		cout<<dp[i]<<' '<<p1[i]<<" "<<p2[i]<<'\n';
	}


	fr(i, 0, r + 1){
		int rem = m - i*3;
		if(rem < 0) break;
		ans = max(ans, c[i] + dp[rem]);
	}
	cout<<ans;
}