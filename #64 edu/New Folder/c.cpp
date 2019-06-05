#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, z;

set <int> x;
map <int, int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>z;

 	fr(i, 1, n + 1) {
 		int t;
 		cin>>t;
 		cnt[t]++;
 		x.insert(t);
 	}

 	int ans = 0;	
 	while(!x.empty()){
 		int t = *(x.begin());
 		if(x.lower_bound(t + z) != x.end()){
 			int l = *(x.lower_bound(t + z));
 			cnt[l]--;
 			if(cnt[l] == 0) x.erase(l);
 			ans++;
 		}
 		cnt[t]--;
 		if(cnt[t] == 0) x.erase(t);
 	}
 	cout<<ans;
}