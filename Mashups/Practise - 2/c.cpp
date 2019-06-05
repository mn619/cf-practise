#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
vector <int> v[200001];
set <int> s[200001];
int a[200001];

void dfs(int node, int parent){
	s[node].erase(parent);

	for(auto x: v[node]){
		if(x != parent) dfs(x, node);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);

 		s[a].insert(b);
 		s[b].insert(a);
 	}

 	dfs(1, 0);
 	fr(i, 1, n + 1){
 		cin>>a[i];
 	}

 	if(a[1] != 1) return cout<<"no", 0;

 	int node = 1;
 	queue <int> q;
 	q.push(1);
 	int cur = 2;

 	while(!q.empty()){
 		int node = q.front();
 		q.pop();

 		int sz = s[node].size();
 		set <int> s1;

 		while(sz--){
 			q.push(a[cur]);
 			s1.insert(a[cur++]);
 		}

 		if(s1 != s[node]) {  		
 			return cout<<"no", 0;
 		}
 	}

 	return cout<<"yes", 0;
}