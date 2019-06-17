#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
string s;

vector <int> p[26];
int d[26];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s;

 	fr(i, 0, s.size()){
 		p[s[i] - 'a'].pb(i);
 	}
 	int n = s.size();
 	int ans = s.size();

 	fr(i, 0, 26){
 		int l = p[i].size();
 		if(l == 0) continue;
 		int mx = max(p[i][0] + 1, n - p[i][l - 1]);

 		fr(j, 1, l){
 			mx = max(p[i][j] - p[i][j - 1], mx);
 		}
 		ans = min(ans, mx);
 	}

 	cout<<ans;


}