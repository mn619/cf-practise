#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, ans[100001];
vector<int> a[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	
	cin>>n;

	fr(i, 1, n + 1){
		int x;
		cin>>x;
		if(x >= 0){
			x = -x - 1;
		}
		a[i].pb(x);
		a[i].pb(i);
	}

	sort(a + 1, a + n + 1);

	if(n&1){
		a[1][0] = -a[1][0] - 1;
	}

	fr(i, 1, n + 1){
		ans[a[i][1]] = a[i][0];
	}

	fr(i, 1, n + 1){
		cout<<ans[i]<<" ";
	}
}