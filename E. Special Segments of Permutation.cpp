#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, p[200001], t[800001], ans = 0, inv[200001];

void build(int l, int r, int node){
	if(l == r) {t[node] = l; return;}

	int mid = (l + r)/2;
	build(l, mid, 2*node);
	build(mid + 1, r, 2*node + 1);

	if(p[t[2*node]] > p[t[2*node + 1]]) t[node] = t[2*node];
	else t[node] = t[2*node + 1];
}

int find_max(int l, int r, int l1, int r1, int node){
	if(l1 > r || r1 < l) return 0;
	if(l <= l1 and r1 <= r) return t[node];
	int mid = (l1 + r1)/2;

	int p1 = find_max(l, r, l1, mid, 2*node);
	int p2 = find_max(l, r, mid + 1, r1, 2*node + 1);

	if(p[p1] > p[p2]) return p1;
	return p2;
}

void solve(int l, int r){
	if(r <= l + 1) return;

	int x = find_max(l, r, 1, n, 1);

	if(x - l < r - x){
		fr(i, l, x){
			if(p[i] > p[x]) continue;
			if(inv[p[x] - p[i]] <= r and inv[p[x] - p[i]] >= x) ans++;			
		}
	}
	else{
		fr(i, x + 1, r + 1){
			if(p[i] > p[x]) continue;
			if(inv[p[x] - p[i]] <= x and inv[p[x] - p[i]] >= l) ans++;			
		}
	}

	solve(l, x - 1);
	solve(x + 1, r);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>p[i];
 		inv[p[i]] = i;
 	}

 	build(1, n, 1);
 	
 	solve(1, n);
 	cout<<ans;
}