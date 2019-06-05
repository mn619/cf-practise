#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
#define maxn 10000000

bool b[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, p;
 	cin>>p>>n;
 	n = min(n, p);

 	int ans = 0;
 	fr(i, 0, n + 1){
 		int ind = (i*(i + 1)/2)%p;
 		b[ind] = 1;
 	}

 	fr(i, 0, p) ans += b[i];
 	cout<<ans;
}