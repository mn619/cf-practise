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
 	int c[n +1];
 	fr(i, 1, n + 1){
 		cin>>c[i];
 	}

 	int a = 0, b = 0;
 	fr(i, 2, n + 1){
 		if(c[i] != c[1]) a = i - 1;
 	}

 	for(int i = n - 1; i > 0; i--){
 		if(c[i] != c[n]){
 			b = n- i;
 		}
 	}

 	cout<<max(a,b);
}