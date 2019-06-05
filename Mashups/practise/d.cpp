#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	cin>>n>>k;
 	int a[n + 1];

 	fr(i, 1, n + 1) cin>>a[i];
 	sort(a + 1, a + n + 1);
 	int cur = k, ans = 0;

 	fr(i, 1, n + 1){
 		int p = 0;
 		while(a[i] > 2*cur){
 			cur *= 2;
 			p++;
 		}
 		cur = max(cur, a[i]);
 		ans += p;
 	}
 	cout<<ans;
}