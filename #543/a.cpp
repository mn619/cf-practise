#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, k, p[101], s[101];
bool in[101];

vector <int> v[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>k;

 	fr(i, 1, n + 1){
 		cin>>p[i];
 	}

 	fr(i, 1, n + 1){
 		cin>>s[i];
 		v[s[i]].pb({p[i]});
 	}

 	fr(i, 1, 101){
 		sort(v[i].begin(), v[i].end());
 		reverse(v[i].begin(), v[i].end());

 		if(v[i].size() > 0){
 			in[v[i][0]] = 1;
 		}
 	}

 	int ans = 0;
 	fr(i, 1, k + 1){
 		int c;
 		cin>>c;
 		if(in[p[c]] == 0) ans++;
 	}

 	

 	cout<<ans;

}