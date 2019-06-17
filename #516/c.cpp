#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 3000000000000000000
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[500001], t, x[500001], b[500001];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>t;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		b[i] = inf;
 	}
 	fr(i, 1, n + 1){
 		cin>>x[i];
 		b[x[i] + 1] = min(b[x[i] + 1], a[x[i] + 1] + t - 1);
 	}

 	fr(i, 1, n + 1) cout<<b[i]<<" ";

 	cout<<"Yes\n";



}