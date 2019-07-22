#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
using namespace std;

int n, p[maxn + 1], q[maxn + 1];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;		
	map<int, int> m;
	fr(i, 1, n + 1) cin>>p[i];
	fr(i, 1, n + 1) {cin>>q[i]; m[q[i]] = i;}

	int ans = 0;

	fr(i, 1, n + 1){
		p[i] = m[p[i]];
	}

	fr(i, 2, n + 1){
		if(p[i] < p[i - 1]) return cout<<n - i + 1, 0;
	}
	cout<<0;
	
}