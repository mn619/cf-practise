#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int ans = 0, n, a[200011];
map<int, int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		ans += (-a[i])*(n - i) + (a[i])*(i - 1);
 	}

 	fr(i, 1, n + 1){
 		int x = a[i] - 1, y = a[i] + 1;
 		if(cnt.count(x)) ans -= cnt[x];
 		if(cnt.count(y)) ans += cnt[y];

 		cnt[a[i]]++;
 	}

 	cout<<ans<<'\n';
}