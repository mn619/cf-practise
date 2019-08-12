#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, x, y, a[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>x>>y;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 	}



 	fr(i, 1, n + 1){
 		bool found = 1;
 		for(int j = 1; j <= x; j++){
 			if(i - j < 1) break;
 			if(a[i - j] < a[i]) found = 0;
 		}

 		for(int j = 1; j <= y; j++){
 			if(i + j > n) break;
 			if(a[i + j] < a[i]) found = 0;
 		}

 		if(found){
 			cout<<i;
 			return 0;
 		}
 	}
}