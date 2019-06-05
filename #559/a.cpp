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

 	int sum = 0, mn = 0, mx = 0;
 	fr(i, 1, n + 1){
 		char c;
 		cin>>c;
 		if(c == '-') sum--;
 		else sum++;
 		mn = min(sum, mn);
 	}

 	int ans = (-mn + sum);
 	cout<<ans;
 	
}