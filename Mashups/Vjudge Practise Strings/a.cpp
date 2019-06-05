#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n;
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s;

 	int cnt[26] = {0};
 	int mxcnt = 0;

 	fr(i, 0, n){
 		cnt[s[i] - 'A']++;
 		mxcnt = max(mxcnt, cnt[s[i] - 'A']);
 	}

 	int a = 0;

 	fr(i, 0, 26){
 		if(cnt[i] == mxcnt) a++;
 	}


 	int ans = 1;
 	while(n--){
 		ans *= a;
 		ans %= mod;
 	}

 	cout<<ans;
}