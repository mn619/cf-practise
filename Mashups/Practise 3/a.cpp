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

 	int a[6];

 	fr(i, 0, 6){
 		cin>>a[i];
 	}

 	int ans = 0;
 	int x= a[0]*a[0] + a[1]*a[1]+ a[0]*a[1];

 	for(int i = 0; i < 6; i += 2){
 		int l1 = a[i], l2 = a[i + 1];
 		ans += l1*l2;
 		//assert(a[i]*a[i] + a[i + 1]*a[i + 1] + a[i]*a[i + 1] == x);
 	}

 	ans += x;

 	cout<<ans;
}	