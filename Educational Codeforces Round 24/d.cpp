#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
int n, a, c[maxn];
vector<int> v[1000001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>a;
 	fr(i, 1, n + 1){
 	 	cin>>c[i];
 	 	v[c[i]].pb(i);
 	}


 	fr(i, 1, 1000001){
 		sort(v[i].begin(),v[i].end());
 	}
 	if(v[a].size() == 0) return cout<<c[1], 0;

 	fr(i, 1, 1000001){
 		if(v[i].size() < v[a].size() || i == a) continue;
 		bool ok = 1;
 		fr(j, 0, v[a].size()){
 			if(v[i][j] >= v[a][j]){
 				ok = 0;
 				break;
 			}
 		}
 		if(ok) return cout<<i, 0;
 	}

 	cout<<-1;
}