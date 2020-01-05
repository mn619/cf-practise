#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 450000
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
int a[maxn], h[maxn], b[maxn];
double seg[maxn*5 + 1];
double l[maxn], r[maxn], z[maxn];;
vector <int> v[maxn];

void compress(){
	vector <int> xxx;
	fr(i, 1, n + 1){
		xxx.emplace_back(v[2*i][0]);
		xxx.emplace_back(v[2*i][1]);
		xxx.emplace_back(v[2*i + 1][0]);
		xxx.emplace_back(v[2*i + 1][1]);
	}

	fr(i, 1, m + 1){
		xxx.emplace_back(b[i]);
	}

	sort(all(xxx));
	map <int, int> c;
	int cur = 1;
	c[xxx[0]] = cur;
	fr(i, 1, (int)xxx.size()){
		if(xxx[i] != xxx[i - 1]) cur++;
		c[xxx[i]] = cur;
	}

	fr(i, 1, n + 1){
		v[2*i][0] = c[v[2*i][0]];
		v[2*i][1] = c[v[2*i][1]];
		v[2*i + 1][0] = c[v[2*i + 1][0]];
		v[2*i + 1][1] = c[v[2*i + 1][1]];
	}

	fr(i, 1, m + 1){
		b[i] = c[b[i]];
	}
}

void update(int l1, int r1, double val, int l, int r, int node){
	if(r1 < l or l1 > r) return;
	if(l1 <= l and r <= r1){
		seg[node] *= val;
		return;
	}
	int mid = (l + r)>>1;
	update(l1, r1, val, l, mid, 2*node);
	update(l1, r1, val, mid + 1, r, 2*node + 1);
}

double queri(int ind, int l, int r, int node, double pre){
	pre *= seg[node];
	if(l == r) return pre;

	int mid = (l + r)>>1;
	if(ind <= mid) return queri(ind, l, mid, 2*node, pre);
	else return queri(ind, mid + 1, r, 2*node + 1, pre);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH
    cin>>n>>m;

    fr(i, 1, 5*maxn + 1) seg[i] = 1.0;

    fr(i, 1, n + 1){
    	cin>>a[i]>>h[i]>>l[i]>>r[i];
    	l[i] *= 1e-2;
    	r[i] *= 1e-2;
    	v[2*i] = {a[i] - h[i], a[i] - 1, i};
    	v[2*i + 1] = {a[i] + 1, a[i] + h[i], i};
    }

    fr(i, 1, m + 1){
    	cin>>b[i]>>z[i];
    }

    compress();

    fr(i, 1, n + 1){
    	update(v[2*i][0], v[2*i][1], 1 - l[i], 1, maxn, 1);
    	update(v[2*i + 1][0], v[2*i + 1][1], 1 - r[i], 1, maxn, 1);
    }

    double ans = 0;
    fr(i, 1, m + 1){
    	ans += z[i]*queri(b[i], 1, maxn, 1, 1);
    }

    cout<<ans<<'\n';
}