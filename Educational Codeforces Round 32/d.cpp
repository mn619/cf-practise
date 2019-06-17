#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, d[10] = {1};


int C(int n, int r){
	int ans = 1;
	int t = n;
	fr(i, 1, r + 1){
		ans *= t;
		t--;
	}

	fr(i, 1, r + 1) ans /= i; 
	return ans;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	d[1] = 0;
 	fr(i, 2, 10) d[i] = (i - 1)*(d[i - 1] + d[i - 2]);
 	cin>>n>>k;

 	int ans = 0;

 	fr(i, 0, k + 1){
 		int t = C(n, i)*d[i];
 		ans += t;
 	}

 	cout<<ans;
}