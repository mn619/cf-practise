#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

void solv(){
	int n, m, k;
	cin>>n>>m>>k;


	VI a(n + 1);
	fr(i, 1, n + 1) cin>>a[i];

	int t = m - 1 - k;
	if(t <= 0){
		int ans = 0;
		for(int i = 1; i <= m; i++){
			ans = max(ans, a[i]);
			ans = max(ans, a[n - i + 1]);
		}
		cout<<ans<<'\n';
		return;
	}

	int ans = 0;
	for(int i = 0; i <= k; i++){
		int l = i + 1, r = n - (k - i);
		int ans1 = inf;
		for(int j = 0; j <= t; j++){
			if(l + j > n) break;
			int temp = max(a[l + j], a[r - (t - j)]);
			ans1 = min(ans1, temp);
		}

		ans = max(ans, ans1);
	}
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;

    while(t--) solv();
}