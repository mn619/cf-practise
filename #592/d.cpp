#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, c[maxn][3], root, ans[maxn];
vector <int> v[maxn];
vector <int> tree;
vector <int> p[6];

void dfs(int node, int par){
	tree.pb(node);
	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node);
	}
}

int cost(int b){
	int sum = 0, k = 0;
	fr(i, 0, n){
 		sum += c[tree[i]][p[b][k]];
 		k++;
 		k%=3;
 	}
 	return sum;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(j, 0, 3){
 		fr(i, 1, n + 1) cin>>c[i][j];
 	}

 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);

 		if(v[a].size() > 2 || v[b].size() > 2) return cout<<-1, 0;
 	}
 	int a[] = {0, 1, 2}, x = 0;
 		
 	do{
 		fr(i, 0, 3){
 			p[x].pb(a[i]);
 		}
 		x++;
 	}
 	while(next_permutation(a, a+3));


 	fr(i, 1, n + 1) if(v[i].size() == 1) {root = i; break;}

 	dfs(root, root);
 	int mn = cost(0);
 	vector <int> perm = p[0];

 	fr(i, 1, 6){
 		int cx = cost(i);
 		if(cx < mn){
 			mn = cx;
 			perm=p[i];
 		}
 	}

 	cout<<mn<<'\n';
 	int k = 0;
 	fr(i, 0, n){
 		ans[tree[i]] = perm[k] + 1;
 		k++;
 		k%=3;
 	} 

 	fr(i, 1, n + 1) cout<<ans[i]<<" ";
}