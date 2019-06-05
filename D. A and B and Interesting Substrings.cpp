#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

map <pair<char, int>, int> m;
int a[26];
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	fr(i,0,26) cin>>a[i];
 	cin>>s;
 	int n =s.size();
 	int pre = 0, ans = 0;
 	fr(i,0,n - 1)
 	{
 		if(s[i] == s[i + 1]) ans++;
 		pre += a[s[i] - 'a'];
 		ans += m[{s[i + 1], pre}];
 		m[{s[i], pre}]++;
 	}
 	cout<<ans<<'\n';
}