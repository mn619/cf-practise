#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x, a[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH	

	cin>>n>>x;

	fr(i, 1, n + 1){
		int y;
		cin>>y;
		a[y] = 1;
	}

	int ans = 0;
	fr(i, 0, x){
		if(a[i] == 0) ans++;
	}

	if(a[x]) ans++;
	cout<<ans;


}