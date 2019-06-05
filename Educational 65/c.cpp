#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
vector <int> v[500001];
int parent[500001];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    	parent[b] = a;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1) parent[i] = i;
 	
 	fr(i, 1, m + 1){
 		int k;
 		cin>>k;

 		fr(j, 1, k + 1){
 			int e;
 			cin>>e;
 			v[i].pb(e);
 		}

 		fr(j, 0, k){
 			union_sets(v[i][j], v[i][0]);
 		}
 	}

 	map <int, int> sz;

 	fr(i, 1, n + 1){
 		sz[find_set(i)]++;
 	}

 	fr(i, 1, n + 1){
 		cout<<sz[find_set(i)]<<" ";
 	}

}