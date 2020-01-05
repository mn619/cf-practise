#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 400000

using namespace std;
int n, mx[maxn], mn[maxn];
int seg[maxn*4];

vector <int> compress(vector <int> x){
	vector <int> ans = x;
	vector <pair<int,int>> p;

	p.pb({0, 0});

	fr(i, 1, x.size()){
		p.pb({x[i], i});
	}

	sort(p.begin(), p.end());
	ans[p[1].second] = 1;
	fr(i, 2, p.size()){
		if(p[i].first > p[i - 1].first)
			ans[p[i].second] = ans[p[i - 1].second] + 1;
		else ans[p[i].second] = ans[p[i - 1].second];
	}

	return ans;
}

void update(int pos, int  val, int l1, int r1, int node){
	if(l1 == r1){
		seg[node] = val;
		return;
	}

	int mid = (l1 + r1)/2;
	if(pos <= mid){
		update(pos, val, l1, mid, 2*node);
	}
	else update(pos, val, mid + 1, r1, 2*node + 1);

	seg[node] = max(seg[2*node], seg[2*node + 1]);
}

int queri(int l, int r, int l1, int r1, int node){
	if(l1 > r or r1 < l) return 0;
	if(l <= l1 and r1 <= r) return seg[node];
	int mid = (l1 + r1)/2;
	return max(queri(l, r, l1, mid, 2*node), queri(l, r, mid + 1, r1, 2*node + 1));
}

void solv(){
	cin>>n;
	vector <int> a(n + 1);
	set <int> s;

	fr(i, 1, n + 1){
		cin>>a[i];
		s.insert(a[i]);
		mx[i] = 0;
		mn[i] = maxn;
	}

	a = compress(a);

	fr(i, 1, n + 1) {
		mx[a[i]] = i;
		mn[a[i]] = min(mn[a[i]], i);
	}

	int l = 1;
	int len = 0;

	fr(i, 1, s.size() + 1){
		update(i, mx[i], 1, n, 1);
	}

	fr(i, 1, s.size() + 1){
		while(queri(l, i - 1, 1, n, 1) > mn[i] and l < i) l++;
		len = max(len, i - l + 1);
	}

	int c = s.size();

	cout<<c - len<<'\n';
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