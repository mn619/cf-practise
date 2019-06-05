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

 	int n, t;
 	cin>>n>>t;
 	int tim = 1000000;
 	int ans;
 	fr(i, 1, n + 1)
 	{
 		int s, d;
 		cin>>s>>d;
 		while(s < t){
 			s += d;
 		}
 		if(tim > s){
 			tim = s;
 			ans = i;
 		}
 	}


 	cout<<ans;
}