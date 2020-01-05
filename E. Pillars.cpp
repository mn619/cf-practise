#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 400000

using namespace std;


struct segTree{
	int N;
	vector <int> seg;
	segTree(int x): seg(4*x), N(x) {}

	//Modify the function depending on the problem
	int f(int prev_val, int new_val, int assign = 0){
		if(assign) return new_val;
		return max(prev_val, new_val);
	}

	int Q(int l, int r, int l1, int r1, int node){
		if(l1 > r or r1 < l) return 0;
		if(l <= l1 and r1 <= r) return seg[node];
		int mid = (l1 + r1)/2;
		return f(Q(l, r, l1, mid, 2*node), Q(l, r, mid + 1, r1, 2*node + 1));
	}

	void U(int ind, int val, int l1, int r1, int node){
		if(l1 == r1){
			if(ind != 0) seg[node] = f(seg[node], val, 1);
			return;
		}
		int mid = (l1 + r1)/2;
		if(ind <= mid) U(ind, val, l1, mid, 2*node);
		else U(ind, val, mid + 1, r1, 2*node + 1);
		seg[node] = f(seg[2*node], seg[2*node + 1]);
	}

	int queri(int l, int r){
		return Q(l, r, 1, N, 1);
	}

	void update(int ind, int val){
		U(ind, val, 1, N, 1);
	}
};

int n, d, h[maxn], id[maxn][3], dp[maxn];

void compress(){
	vector <pair<int, int>> v;
	fr(i, 1, n + 1){
		v.pb({h[i], 3*i});
		v.pb({h[i] - d, 3*i + 1});
		v.pb({h[i] + d, 3*i + 2});
	}

	sort(v.begin(), v.end());
	int cur = 1;
	id[v[0].second/3][(v[0].second)%3] = cur;

	fr(i, 1, v.size()){
		if(v[i].first != v[i - 1].first) cur++;
		id[v[i].second/3][(v[i].second)%3] = cur;		
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>d;
	fr(i, 1, n + 1) cin>>h[i];
	compress();

	segTree tree(maxn);

	fr(i, 1, n + 1){
		dp[i] = max(tree.queri(id[i][2], maxn), tree.queri(1, id[i][1])) + 1;
		tree.update(id[i][0], dp[i]);
	}
	int cur = 1;
	fr(i, 2, n + 1){
		if(dp[i] > dp[cur]) cur = i;
	}
	vector <int> ans;
	int las = cur;
	ans.pb(las);
	cur--;

	while(cur > 0){
		if(abs(h[las] - h[cur]) >= d and dp[cur] == dp[las] - 1){
			ans.pb(cur);
			las = cur;
		}
		cur--;
	}

	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<'\n';
	for(auto x: ans) cout<<x<<" ";
}