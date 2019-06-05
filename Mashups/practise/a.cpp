#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int clr[300001], a = 0, b = 0;
bool ok = 1;

vector <int> v[300001];


void dfs(int node, bool c){

	if(clr[node] != -1){
		if(clr[node] != c) ok = 0;
		return;
	}

	if(c == 0) a++;
	else b++;
	clr[node] = c;
	for(auto x: v[node]){
		dfs(x, !(c&1));
		if(!ok) return;
	}
}

int power(int a, int b, int m)
{
	if(b == 0) return 1;
	int temp = power(a, b/2, m);
	temp *= temp;
	temp %= m;
	if(b&1) temp *=a%m, temp%=m;
	return temp;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;

 	while(t--){
 		int n, m;
 		cin>>n>>m;
 		fr(i, 1, n + 1) clr[i] = -1;
 		fr(i, 1, m + 1){
 			int x ,y;
 			cin>>x>>y;
 			v[x].pb(y);
 			v[y].pb(x);
 		}
 		
 		
 		int ans = 1;

 		fr(i, 1, n + 1){
 			if(clr[i] != -1)
 				continue;
 			dfs(i, 0);
 			ans *= (power(2, b, mod) + power(2, a, mod));
 			ans %= mod;
 			a = 0, b = 0;
 		}
 		fr(i, 1,  n + 1) v[i].clear();
 		cout<<ok*ans<<'\n';
 		ok = 1;
 	}
}