#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n;
map <string, vector<int>> m;
string f[1001], s[1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1)
 	{
 		cin>>f[i]>>s[i];
 		m[f[i].substr(0,3)].pb(i);
 	}

 	string ans[n + 1];
 	set <string> ans_s;

 	for(auto x: m)
 	{
 		vector <int> v = x.second;
 		bool ok = (v.size() == 1);
 		for(auto ind: v)
 		{
 			string t = f[ind].substr(0, 3);
 			if(ans_s.find(t) != ans_s.end())
 			{
 				ok = 0;
 			}
 		}

 		if(ok) ans[v[0]] = x.first;
 		else
 		{
 			for(auto ind: v)
 			{
 				string t = f[ind].substr(0, 2);
 				t += s[ind][0];
 				if(ans_s.find(t) != ans_s.end()) return cout<<"NO", 0;
 				ans_s.insert(t);
 				ans[ind] = t;
 			}
 		}
 	}

 	cout<<"YES\n";
 	fr(i, 1, n + 1) cout<<ans[i]<<"\n";
}