#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, q, c;

vector <pair<int, int>> v[101];
vector<int> queri[100001];

int star[101][101];
int pref[101][101];
int ans[100001];

void update(int d){
	assert(d >= 0);

	fr(i, 1, 101){
		int l = v[i].size();
		fr(j, 0, l){
			v[i][j].second += d;
			v[i][j].second %= c + 1;
 		}
	}

	fr(i, 0, 101){
		fr(j, 0, 101) pref[i][j] = 0;
	}

	fr(i, 1, 101){
		int l = v[i].size();
		fr(j, 0, l){
			pref[i][v[i][j].first] += v[i][j].second;
		}
	}

	fr(i, 1, 101){
		fr(j, 1, 101){
			pref[i][j] += pref[i][j - 1];
		}
	}
}

int solve(int x, int y1, int y2){
	return pref[x][y2] - pref[x][y1 - 1];
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>q>>c;

 	fr(i, 1, n + 1){
 		int x, y, s;
 		cin>>x>>y>>s;
 		v[x].pb({y, s});
 	}

 	int qcnt = 1;
 	while(qcnt <= q){
 		int t, x1, y1, x2, y2;
 		cin>>t>>x1>>y1>>x2>>y2;
 		t %= c + 1;

 		queri[qcnt].pb(t);
 		queri[qcnt].pb(x1);
 		queri[qcnt].pb(y1);
 		queri[qcnt].pb(x2);
 		queri[qcnt].pb(y2);
 		queri[qcnt].pb(qcnt);
 		qcnt++;
 	}
 	sort(queri + 1, queri + q + 1);
 	int tlas = 0;
 	update(0);

 	fr(i, 1, q + 1){
 		int t = queri[i][0], x1 = queri[i][1], y1 = queri[i][2], x2 = queri[i][3], y2 = queri[i][4], ind = queri[i][5];
 		if(t > tlas){
 			update(t - tlas);
 			tlas = t;
 		}

 		int ans1 = 0;
 		fr(i, x1, x2 + 1){
 			ans1 += solve(i, y1, y2);
 		}
 		ans[ind] = ans1;
 	}

 	fr(i, 1, q+ 1) cout<<ans[i]<<'\n';
}