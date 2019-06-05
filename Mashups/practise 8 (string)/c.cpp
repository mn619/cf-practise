#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int n;
string s, t;
int parent[26];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
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

 	cin>>n>>s>>t;

 	fr(i, 0, 26) parent[i] = i;

 	int ans = 0;
 	set <pair<char, char>> m;

 	fr(i, 0, n){
 		if(find_set(s[i] - 'a') != find_set(t[i] - 'a')){
 			ans++;
 			m.insert({s[i], t[i]});
 			union_sets(s[i] - 'a', t[i] - 'a');
 		}
 	}

 	cout<<ans<<'\n';
 	for(auto x: m){
 		cout<<x.first<<" "<<x.second<<'\n';
 	}
}