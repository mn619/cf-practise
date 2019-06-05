#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int pos[300001], n, m;
int l[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i,1,n + 1)
 	{
 		int p;
 		cin>>p;
 		pos[p] = i;
 	}

 	memset(l, -1, sizeof l);

 	fr(i,1,m + 1)
 	{
 		int x, y;
 		cin>>x>>y;
 		if(pos[x] > pos	[y]) swap(x,y);
 		//l[pos[y]] = max(pos[x], l[pos[y]]);
 		l[pos[y]] = pos[x];
 	}
 	int las = 1, ans = 0;

 	fr(i,1,n + 1)
 	{
 		if(l[i] >= las)
 		{
 			las = l[i] + 1;
 		}
 		ans += (i - las + 1);
 		//cout<<las<<" "<<l[i]<<" "<<pos[i]<<" "<<ans<<"\n";
 	}
 	cout<<ans<<'\n';
}