#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int cnt[10], n, k;
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k>>s;
 	ans = n;
 	fr(i, 0, n){
 		cnt[s[i] - '0']++;
 		ans = min(ans, k - cnt[s[i] - '0']);
 	}

 	ans = max(ans, (int) 0);
 	cout<<ans;


}