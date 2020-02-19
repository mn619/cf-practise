#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 50000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, k, ans;
vector <int> v[maxn + 1];

vector<int> dfs(int node, int par){
	vector <int> d(501);
	d[0]++;
	for(auto x: v[node]){
		if(x == par) continue;
		auto d1 = dfs(x, node);
		for(int i = 1; i <= k; i++)
			ans += d1[i - 1]*d[k - i];
		for(int i = 0; i < 499; i++)
			d[i + 1] += d1[i];
	}
	return d;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;
    fr(i, 1, n){
    	int a, b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    dfs(1, 0);
    cout<<ans<<'\n';
}