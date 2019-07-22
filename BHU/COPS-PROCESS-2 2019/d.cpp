#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
using namespace std;

int n;
vector <int> v[maxn + 2];
bool in[maxn + 2];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;
 	fr(i, 1, n + 1){
 		int l, r;
 		cin>>l>>r;
 		v[i].pb(l);
 		v[i].pb(r);
 		in[i] = 1;
  	}

  	n++;
  	v[n].pb(mod);
  	v[n].pb(mod);

 	sort(v + 1, v + n + 1);

 	int l = v[1][0], r = v[1][1];

 	vector<int> ans;
 	fr(i, 2, n + 1){
 		if(v[i][0] <= r){
 			l = v[i][0];
 			r = min(v[i][1], r);
 		}
 		else{
 			ans.pb(l);
 			l = v[i][0];
 			r = v[i][1];
 		}
 	}

 	cout<<ans.size()<<'\n';
 	for(auto x: ans) cout<<x<<" ";
}