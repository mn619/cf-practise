#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
int n, m, k, p[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>k;

 	fr(i, 1, m + 1){ cin>>p[i]; p[i]--;}
 	int ans = 0;
 	int cur = 1, dis = 0;

 	while(cur <= m){
 		int t = cur;
 		while((p[t + 1] - dis)/k == (p[cur] - dis)/k and t < m) t++;
 		ans++;
 		dis += t - cur + 1;
 		cur = t + 1;
 	}

 	cout<<ans;
}