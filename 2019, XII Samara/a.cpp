#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[500001], ans[500001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];

 	map <int, int> m;
 	int las = n + 1;

 	for(int i = n; i>=1; i--){
 		if(a[i] > 0){
 			m[a[i]] =  i;
 		}
 		else {
 			if(m.count(-a[i])){
 				las = min(m[-a[i]], las);
 			}
 		}
 		ans[i - 1] = las - i;
 	}
 	fr(i, 0, n) cout<<ans[i]<<" ";
}