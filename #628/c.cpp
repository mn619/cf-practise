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

int n;
vector <pair<int, int>> v[maxn];
int ans[maxn];
int t = 0;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    if(n == 2){
    	cout<<0<<'\n';
    	return 0;
    }

    for(int i = 0; i < n - 1; i++){
    	ans[i] = -1;
    	int a, b;
    	cin>>a>>b;
    	v[a].pb({b, i});
    	v[b].pb({a, i});
    }

    for(int i = 1; i <= n; i++){
    	if(v[i].size() == 1){
    		ans[v[i][0].S] = t++;
    	}
    }

    for(int i = 0; i < n - 1; i++){
    	if(ans[i] == -1) cout<<t++<<'\n';
    	else cout<<ans[i]<<"\n";
    }	

    assert(t == n - 1);
}