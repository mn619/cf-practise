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
 	int n;
 	cin>>n;
 	int cnt[10] = {0};
 	fr(i, 0, n){
 		char c;
 		cin>>c;
 		cnt[c - '0']++;
 	}

 	int ans = 0;
 	fr(i, 0, cnt[8] + 1){
 		if(i*10 + i<= n) ans = i;
 	}
 	cout<<ans;


}