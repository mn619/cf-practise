#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int p[100001], c[100001];
vector <int> v[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;
 	fr(i, 1, n + 1)
 	{
 		cin>>p[i]>>c[i];
 		v[i].pb(p[i]);
 		if(p[i] != -1) v[p[i]].pb(i);
 	}

 	bool ans[n + 1] = {0};
 	fr(i, 1, n + 1)
 	{
 		bool ok = 1;
 		for(auto x: v[i])
 		{
 			if(x == p[i]) continue;
 			if(c[x] == 0) ok = 0;
 		}
 		ans[i] = ok;
 	}
 	
 	bool ok = 0;
 	fr(i, 1, n + 1)
 	{
 		if(ans[i] && c[i]) {cout<<i<<" "; ok =1;}
 	}

 	if(!ok) cout<<-1;
}
