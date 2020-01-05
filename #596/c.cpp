#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int bitcnt(int n){
	int ans = 0;
	while(n){
		if(n&1) ans++;
		n /= 2;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, p;
 	cin>>n>>p;

 	fr(k, 0, 1000001){
 		int t = n - k*p;

 		if(t >= k and bitcnt(t) <= k){
 			cout<<k;
 			return 0;
 		}
 	}	
 	cout<<-1;	
}