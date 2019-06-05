#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int cnt[26];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	fr(i, 1, n + 1){
 		string s;
 		cin>>s;
 		cnt[s[0] - 'a']++;
 	}

 	int ans = 0;
 	fr(i, 0, 26){
 		int x = cnt[i]/2;
 		int y = cnt[i] - x;
 		ans += (x*(x - 1)/2) + (y*(y - 1))/2;
 	}

 	cout<<ans;
}