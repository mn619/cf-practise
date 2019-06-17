#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define double long double 

using namespace std;

int n;
vector<int> v[100001];


double dfs(int node, int par){
	double ans = 0;
	int cnt = 0;

	for(auto x: v[node]){
		if(x == par) continue;
		ans += 1 + dfs(x, node);
		cnt++;
	}
		
		if(cnt == 0) return 0;
	return 1.0*ans/cnt;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cout<<setprecision(15);

 	cin>>n;
 	fr(i,1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}

 	cout<<dfs(1, 1);

}