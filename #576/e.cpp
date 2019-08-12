#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 400000

using namespace std;

int n, m;
bool vis[maxn];
vector<int> v[maxn];
map <pair<int, int>, int> e;

set <pair<int, int>> in_indps;
set <int> in_match;

set <int> match;
set <int> indps;



void reset(){
	
	for(int i = 1; i <= 3*n; i++){
		v[i].clear();
		vis[i] = 0;
	}

	e.clear();
	in_match.clear();
	in_indps.clear();
	match.clear();
	indps.clear();
}

void dfs_m(int node){
	vis[node] = 1;
	if(!in_match.count(node)){
		in_match.insert(node);

		for(auto x: v[node]){
			if(!in_match.count(x)){
				in_match.insert(x);
				match.insert(e[{node, x}]);
				break;
			}
		}
	}	

	for(auto x: v[node]) if(!vis[x])dfs_m(x);
}

void dfs_s(int node){
	vis[node] = 1;
	bool used = 0;

	for(auto x: v[node]){
		if(in_indps.count({node, x})){used = 1; break;}
	}

	if(!used){
		indps.insert(node);
		for(auto x: v[node]){
			in_indps.insert({x, node});
			in_indps.insert({node, x});
		}
	}


	for(auto x: v[node]){
		if(!vis[x]) dfs_s(x);
	}

}
void solv(){
	cin>>n>>m;


	fr(i, 1, m + 1){
		int a, b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);

		e[{a, b}] = e[{b, a}] = i;
	}

	fr(i, 1, 3*n + 1)
		if(!vis[i])
			dfs_m(1);

	fr(i, 1, 3*n + 1){
		vis[i] = 0;
	}

	fr(i, 1, 3*n + 1)
		if(!vis[i])
			dfs_s(1);

	cout<<match.size()<<" "<<indps.size()<<'\n';

	if(match.size() >= n){
		cout<<"Matching\n";
		int cnt = 0;
		for(auto x: match){
			cout<<x<<" ";
			cnt++;
			if(cnt == n) break;
		}
	}
	else if(indps.size() >= n){
		cout<<"IndSet\n";
		int cnt = 0;
		for(auto x: indps){
			cout<<x<<" ";
			cnt++;
			if(cnt == n) break;
		}
	}
	cout<<'\n';

	reset();
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int tests;
 	cin>>tests;

 	while(tests--)solv();
}