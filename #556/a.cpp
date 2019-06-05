#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, o1 = 0, e1 = 0, o2 = 0, e2 = 0;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1){
 		int x;
 		cin>>x;
 		if(x&1) o1++;
 		else e1++;
 	}

 	fr(i, 1, m + 1){
 		int x;
 		cin>>x;
 		if(x&1) o2++;
 		else e2++;
 	}

 	int ans = min(o1, e2) + min(o2, e1);
 	cout<<ans;
}