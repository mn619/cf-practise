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
pair<int, int> p[maxn + 1];


vector <pair<pair<int, int>, int>> seg[4*maxn + 1];

void build(int l, int r, int node){
	if(l == r){
		seg[node].pb({{p[l].S, p[l].F}, p[l].F});
		return;
	}

	int mid = (l + r)>>1;
	build(l, mid, 2*node);
	build(mid + 1, r, 2*node + 1);

	for(auto x: seg[2*node])
		seg[node].pb(x);
	

	for(auto x: seg[2*node + 1])
		seg[node].pb(x);
	
	sort(all(seg[node]));

	seg[node][0].S = seg[node][0].F.S;

	for(int i = 1; i < (int)seg[node].size(); i++)
		seg[node][i].S = seg[node][i - 1].S + seg[node][i].F.S;
}

int Bsmol(int node, int vel, int xval){
	int L = 0, R = (int)seg[node].size() - 1, ans = 0, ind = -1;
	while(L <= R){
		int M = (L + R)>>1;
		if(seg[node][M].F.F <= vel){
			ind = M;
			ans = seg[node][M].S;
			L = M + 1;
		}
		else R = M - 1;
	}

	assert(xval*(ind + 1) - ans >= 0);

	return xval*(ind + 1) - ans;
}

int queri(int l1, int r1, int val, int xval, int l, int r, int node){
	if(l1 > r or r1 < l) return 0;
	if(l1 <= l and r <= r1){
		return Bsmol(node, val, xval);
	}
	int mid = (l + r)>>1;
	return queri(l1, r1, val, xval, l, mid, 2*node) + queri(l1, r1, val, xval, mid + 1, r, 2*node + 1);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    fr(i, 1, n + 1) cin>>p[i].F;
    fr(i, 1, n + 1) cin>>p[i].S;

    sort(p + 1, p + n + 1);

    build(1, n, 1);

    int ans = 0;
    fr(i, 1, n + 1){
    	int temp = ((i > 1)?queri(1, i - 1, p[i].S,p[i].F, 1, n, 1):0);
    	ans += temp;
    }

    cout<<ans<<'\n';
}