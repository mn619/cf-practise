#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, m;
vector<int> v[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k>>m;

 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		v[a%m].pb(a);
 	}

 	fr(i, 0, m){
 		if(v[i].size() >= k){
 			cout<<"Yes\n";

 			fr(j, 0, k) cout<<v[i][j]<<' ';
 			return 0;
 		}
 	}

 	cout<<"No\n";
}