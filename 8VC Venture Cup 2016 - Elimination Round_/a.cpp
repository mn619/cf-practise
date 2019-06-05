#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


pair<int, int> check(string s)
{
	int r = 0, u = 0;
	int n = s.size();
 	fr(i, 0, n)
 	{
 		if(s[i] == 'L') r--;
 		if(s[i] == 'R') r++;
 		if(s[i] == 'D') u--;
 		if(s[i] == 'U') u++;
 	};
 	return {r,u};
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	int n;
 	cin>>n;
 	string s;
 	cin>>s;


 	int ans = 0;

 	fr(i, 0, n)
 	{
 		string x = "";
 		fr(j, i, n)
 		{
 			x += s[j];
 			pair <int, int> p = check(x);
 			if(p.first == 0 && p.second == 0)  ans++;
 		}
 	}
 	cout<<ans<<'\n';

}