#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>k;
	fr(i, 1, n + 1) cin>>a[i];

	int p = n, ans = 0;
	
	while(k > 1){
		int sm = 0, mxsum = a[p], mxind = p;
		for(int j = p; j >= k; j--){
			sm += a[j];
			if(sm > mxsum){
				mxsum = sm;
				mxind = j;
			}
		}
		p = mxind - 1;
		ans += mxsum*k;
		k--;
	}

	for(int j = p; j >= 1; j--){
		ans += a[j];
	}

	cout<<ans;
}