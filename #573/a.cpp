#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int x;
 	cin>>x;
 	x %= 4;

 	if(x == 0){
 		cout<<1<<" A";
 	}	
 	else if(x == 1){
 		cout<<0<<" A";
 	}
 	else if(x == 2){
 		cout<<1<<" B";
 	}
 	else cout<<2<<" A";
}