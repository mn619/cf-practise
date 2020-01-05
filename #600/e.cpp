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

int n, m;
vector <int> v[81];
int dp[81][maxn];

bool comp(vector <int> v1, vector <int> v2){
	return v1[1] < v2[1];
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    fr(i, 1, n + 1){
    	int x, s;
    	cin>>x>>s;
    	v[i] = {max((int)1, x - s), min(m, x + s)};
    }

    sort(v + 1, v + n + 1, comp);

    fr(j, 1, m + 1){
    	dp[1][j] = max(max((int)0, v[1][0] - 1), max(j - v[1][1], (int) 0));
	}

    fr(i, 2, n + 1){
    	fr(j, 1, m + 1){
    		dp[i][j] = dp[i - 1][j];
    		int d = max(j - v[i][1], (int)0);
			dp[i][j] = min(dp[i][j], dp[i - 1][max((int)0, v[i][0] - d - 1)] + d);	
			dp[i][j] = min(dp[i][j], max(max((int)0, v[i][0] - 1), max(j - v[i][1], (int) 0)));
    	}
    }

    cout<<dp[n][m]<<'\n';
}