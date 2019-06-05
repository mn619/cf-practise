#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int x[26];
string s;
map <pair<char, int>, int> m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	fr(i, 0, 26) cin>>x[i];
 	cin>>s;

 	int sum = 0, ans = 0;
 	
 	fr(i, 0, s.size()){
 		int a = x[s[i] - 'a'];
 		ans += m[{s[i], sum}];
 		sum += a;
 		m[{s[i], sum}]++;
 	}
 	cout<<ans;

}