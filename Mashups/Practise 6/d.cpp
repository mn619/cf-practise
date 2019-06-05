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

 	string s;
 	cin>>s;
 	map <char, int> cnt;
 	fr(i, 0, s.size()){
 		cnt[s[i]]++;
 	}

 	int ans = 0;
 	for(auto x: cnt){
 		ans += x.second*x.second;
 	}

 	cout<<ans;
}