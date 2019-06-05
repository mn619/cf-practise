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

 	int n, m;
 	cin>>n>>m;

 	int a[n + 1][m + 1], b[n + 1][m + 1];

 	map <int , multiset<int> > in, fi;
 	map <int, int> cnt;

 	fr(i, 1, n + 1)
 	{
 		fr(j, 1, m + 1)
 		{
 			cin>>a[i][j];
 			cnt[a[i][j]]++;
 			in[i + j].insert(a[i][j]);
 		}
 	}

 	fr(i, 1, n + 1)
 	{
 		fr(j, 1, m + 1)
 		{
 			cin>>b[i][j];
 			cnt[b[i][j]]--;
 			fi[i + j].insert(b[i][j]);
 		}
 	}

 	for(auto x: cnt)if(x.second != 0) return cout<<"NO\n", 0;

 	string ans = "YES";

 	for(auto x: in)
 	{
 		if(x.second != fi[x.first]) return cout<<"NO\n" , 0;
 	}

 	for(auto x: fi)
 	{
 		if(x.second != fi[x.first]) return cout<<"NO\n" , 0;
 	}

 	cout<<ans;
}