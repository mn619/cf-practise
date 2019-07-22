#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define fi first
#define se second

using namespace std;

int d, n, m;

vector<int> l, r, t, b;
pair<int, int> x[maxn], y[maxn];
int cntl[maxn], cntr[maxn], cntt[maxn], cntb[maxn];

int cntL(int x){
	int l1 = 0, r1 = d - 1, ans = 0;
	while(l1 <= r1 ){
		int mid = (l1 + r1)/2;
		if(l[mid] < x){
			ans = mid + 1;
			l1 = mid + 1;
		}
		else r1 = mid - 1;
	}

	return ans;
}

int cntR(int x){
	int l1 = 0, r1 = d - 1, ans = d;
	while(l1 <=r1 ){
		int mid = (l1 + r1)/2;

		if(r[mid] > x){
			ans = mid;
			r1 = mid - 1;
		}
		else l1 = mid + 1;
	}
	return d - ans;
}


int cntT(int y){
	int l1 = 0, r1 = d - 1, ans = 0;
	while(l1 <= r1 ){
		int mid = (l1 + r1)/2;
		if(t[mid] < y){
			ans = mid + 1;
			l1 = mid + 1;
		}
		else r1 = mid - 1;
	}
	return ans;
}

int cntB(int y){
	int l1 = 0, r1 = d - 1, ans = d;
	while(l1 <= r1 ){
		int mid = (l1 + r1)/2;
		if(b[mid] > y){
			ans = mid;
			r1 = mid - 1;
		}
		else l1 = mid + 1;
	}
	
	return d  - ans;
}



signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>d>>n>>m;

 	fr(i, 1, d + 1){
 		cin>>x[i].fi>>y[i].fi>>x[i].se>>y[i].se;
 		l.pb(min(x[i].fi, x[i].se));
 		r.pb(max(x[i].fi, x[i].se));
 		t.pb(min(y[i].fi, y[i].se));
 		b.pb(max(y[i].fi, y[i].se));
 	}

 	sort(l.begin(), l.end());
 	sort(r.begin(), r.end());
 	sort(t.begin(), t.end());
 	sort(b.begin(), b.end());

 	fr(i, 1, d + 1){
 		cntl[i] = cntL(max(x[i].fi, x[i].se)) - (x[i].fi != x[i].se);
 		cntr[i] = cntR(min(x[i].fi, x[i].se)) - (x[i].fi != x[i].se);

 		cntt[i] = cntT(max(y[i].fi, y[i].se)) - (y[i].fi != y[i].se);
 		cntb[i] = cntB(min(y[i].fi, y[i].se)) - (y[i].fi != y[i].se);
 	}

 	int a, b, c, d1;
 	cin>>a>>b>>c>>d1;

 	fr(i, 1, d + 1){
 		if(cntl[i] == a and cntr[i] == b and cntt[i] == c and cntb[i] == d1) return cout<<i, 0;
 	}

 	cout<<-1;
}